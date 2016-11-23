import time
import serial,struct
import sys
import os
import string
import argparse

parser = argparse.ArgumentParser(description = 'UART Bootloader script')
parser.add_argument('-p','--port', help='COM port name',required=True)
parser.add_argument('-i','--inputfile', help='Input file name',required=True)
args = parser.parse_args()

page_size = 64
buffer_size = 32

ser = serial.Serial(
	port = args.port,
	baudrate = 115200,
	parity = serial.PARITY_NONE,
	stopbits = serial.STOPBITS_ONE,
	bytesize = serial.EIGHTBITS,
	timeout = 5
)
print ("Port %s opened" % ser.port)


out = os.path.getsize(args.inputfile)
#print out
#print string.zfill(hex(out).rstrip("L").lstrip("0x"),4)
out = out & 0xFFFFFFF
out_0 =  (out & 0xFF)
out_1 = ((out >> 8) & 0xFF)
out_2 = ((out >> 16) & 0xFF)
out_3 = ((out >> 24) & 0xFF)
output = struct.pack('BBBB',out_3,out_2,out_1,out_0)
#length = ser.write(chr(out_3))
#print out_0
#length = ser.write(chr(out_2))
#print out_1
#length = ser.write(chr(out_1))
#print out_2
#length = ser.write(chr(out_0))
#print out_3
length = ser.write(output)
read = ''
print "Length transmitted"

out = 0
len = os.path.getsize(args.inputfile)
input_file = open(args.inputfile, 'rb')
block_len = page_size
#print block_len
nb_blocks = len / block_len
#print nb_blocks
rem_data = len % block_len
#print rem_data

print "Transferring file",

out = ''
for x in xrange(0, nb_blocks):
	for y in xrange(0, buffer_size):
		out += input_file.read(1)

	#print x
	#print "\n>>" + out + "\n>>"
	length = ser.write(out)
	#print length
	out = ''
	print ".",

	out = ''
	for y in xrange(buffer_size, page_size):
		out += input_file.read(1)
	length = ser.write(out)
	#print length
	out = ''
	print ".",

	read = ''
	#count = 0

	while True:
		read = ser.read(1)
		if read == 's':
			break
	#print count
	#print read
	#print "\n" , ord(read), "received"
	if read != 's':
		print "No response from device \n"
		exit()

for x in xrange(0, rem_data):
	out += input_file.read(1)
length = ser.write(out)
#print length

print "\nTransfer complete"
input_file.close()
exit()