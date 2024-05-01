from serial import Serial, SerialException

#with Serial('COM5', 9600) as ser:
#    while True:
#        print(ser.readline().decode())

with Serial('COM5', 9600) as ser:
    ser.write(bytes([0x1]))
    print(ser.read() == bytes([0xaa]))

    ser.write(bytes([0x0]))
    print(ser.read() == bytes([0xaa]))

    ser.write(bytes([0x2]))
    print(ser.read() == bytes([0xff]))
