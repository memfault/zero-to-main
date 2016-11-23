import Image
import sys

# Converts an exported font character image image file (such as files generated
# with the free "Codehead's Bitmap Font Generator (CBFG)" tool at
# http://www.codehead.co.uk/cbfg/ ) into a font array suitable for use with the
# GFX font functions of ASF.

if len(sys.argv) == 4:
	source_image = sys.argv[1]
	char_width = int(sys.argv[2])
	char_height = int(sys.argv[3])
	print "// Source file: %s   Char Size:%dx%d\n" % (source_image, char_width, char_height)
else:
	print "Incorrect number of arguments, usage:\n bmp2font.py <image_in> <char_width> <char_height>\nEx: bmp2font.py FontMap.bmp 10 14 > image.h"
	sys.exit()

# Open the exported font bitmap file, convert it to a pixel array
im = Image.open(source_image)
im = im.convert('1')
pixels = im.load()

# Get the dimensions of the character map image
img_width, img_height = im.size

# Start and end characters of the map to convert (an assumption is made that the
# first character cell of the image contains the start character)
start_char = ' '
end_char = '}'

# Compute the size of the character cells and how many cells are on each line
# of the image (an assumption is made that the character data is top-left
# adjusted in each cell)
cell_width = char_width
cell_height = char_height
cells_per_line = img_width / char_width

# Maximum number of hex formatted data bytes that should be printed to each line
max_line_elements = 10

# Iterate over each character to convert in the character map, from start->end
# characters
for letter in range(0, 1 + ord(end_char) - ord(start_char)):
	line = ""
	
	# Compute the cell X and Y coordinate in the image, based on the number of
	# cells that are on each line of the image
	cell_x = letter % cells_per_line
	cell_y = letter // cells_per_line
	
	# Convert the cell coordinates to a set of pixel coordinates
	cell_pixel_x_start = cell_x * cell_width
	cell_pixel_y_start = cell_y * cell_height
	
	# Pixel data is stored X,Y so iterate over Y lines of the character
	elements_on_line = 0
	for y in range(0, char_height):
		binary = ""
		
		# Pixel data is stored X,Y so iterate over X columns of the character
		for x in range(0, char_width):
			# Make sure we split the X data into bytes when printed if the X
			# width is >= 8
			if (x > 0 and not (x % 8)):
				line += '0x%02X, ' % (int(binary, 2))
				elements_on_line = elements_on_line + 1
				binary = ""

				# Move to next line of output when max number of elements on
				# current output line is reached
				if elements_on_line and not (elements_on_line % max_line_elements):
					line += '\n\t'
			
			# Read the current pixel XY coordinate of the image, convert to binary
			if (pixels[cell_pixel_x_start + x, cell_pixel_y_start + y] > 0):
				binary += '1'
			else:
				binary += '0'
		
		# Make sure we prefix the output with the correct number of trailing
		# zeros, as the font data is left-adjusted in the encoded bytes
		if (char_width % 8):
			binary += ("0" * (8 - (char_width % 8)))
		
		line += '0x%02X, ' % (int(binary, 2))		
		elements_on_line = elements_on_line + 1
		
		if elements_on_line and not (elements_on_line % max_line_elements):
			line += '\\\n'
			
	print "%s /* ""%c"" */ \\" % (line[:-1], chr(letter + ord(start_char)))
