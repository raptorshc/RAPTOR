import serial

import matplotlib.pyplot as plt
import matplotlib.animation as animation

# class DataPlot:
#     def __init__(self, port, maxlen):
#         # open serial port
#         self.ser = serial.Serial(port, 9600)
#     def update(self):
#         nop

ser = serial.Serial('/dev/ttyASCM0', 9600)

time = []
temperature = []
pressure = []

while True:
    raw = ser.readline().split(',')
    print(f'Time: {raw[0]} Temperature: {raw[1]} Pressure: {raw[2]}')