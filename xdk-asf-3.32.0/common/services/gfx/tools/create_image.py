import Image
import sys


if len(sys.argv) == 4:
	display_controller = sys.argv[1]
	filename_in = sys.argv[2]
	name = sys.argv[3]
	print "// Source file: %s\n" % (filename_in)
else:
	print "Incorrect number of arguments, usage:\n create_image.py <display_controller> <image_in> <image_name>\nEx: create_image.py hx8347a image.jpg image > image.h"
	sys.exit()


im = Image.open(filename_in)

width = im.size[0]
height = im.size[1]

print "// Image info: ", im.format, im.size, im.mode
print "// Display controller: ", display_controller
print '#include "gfx.h"'

name_data = name + "_data"
struct_init = "struct gfx_bitmap %s =  { .width = %d, .height = %d , .type = GFX_BITMAP_PROGMEM, .data.progmem = (gfx_color_t PROGMEM_PTR_T)%s};" % (name, width, height, name_data)

# print array initializer
print "PROGMEM_DECLARE(gfx_color_t, %s_data[%d]) = {" % (name, (width * height))

col = 0
data_string = ""
for y in range(0, height):
	for x in range(0, width):
		if (col == 8):
			data_string += "\n"
			col = 0
		pixel = im.getpixel((x, y))
		r = pixel[0]
		g = pixel[1]
		b = pixel[2]
		
		if (display_controller == "hx8347a"):
			color_val = ((b >> 3) << 11) | ((g >> 2) << 5) | ((r >> 3) << 0)
			color_val = ((color_val << 8) | (color_val >> 8)) & 0xFFFF
		elif (display_controller == "ili9341"):
			color_val = ((r >> 3) << 11) | ((g >> 2) << 5) | ((b >> 3) << 0)
			color_val = ((color_val << 8) | (color_val >> 8)) & 0xFFFF
		elif (display_controller == "hx8347a_uc3"):
			color_val = ((r >> 3) << 11) | ((g >> 2) << 5) | ((b >> 3) << 0)
		else:
			print "Unknown display controller \"%s\"" % display_controller
			sys.exit()
		
		if col == 7 :
			data_string += "0x%04x," % (color_val)
		else :
			data_string += "0x%04x, " % (color_val)
		col += 1

# Print array data
print data_string + "\n};"

# Print bitmap struct initializer
print struct_init
