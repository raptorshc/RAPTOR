import serial

ser = serial.Serial('/dev/ttyASCM0', 9600)
while True:
    print(ser.readline())