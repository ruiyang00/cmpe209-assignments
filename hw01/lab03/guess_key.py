from binascii import hexlify, unhexlify
from Crypto.Cipher import AES

iv = '09080706050403020100A2B2C2D2E2F2'
p = '255044462d312e350a25d0d4c5d80a34'
c = 'd06bf9d0dab8e8ef880660d2af65aa82'

file1=open('keys.txt', 'r')
lineList = [line.rstrip('\n') for line in file1]
file1.close()

#for s in lineList:
#	print(s)


cipher =AES.new(lineList[1], AES.MODE_CBC, iv);

print(cipher)

