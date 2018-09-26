import serial

import matplotlib.pyplot as plt
import matplotlib.animation as animation

# class DataPlot:
#     def __init__(self, port, maxlen):
#         # open serial port
#         self.ser = serial.Serial(port, 9600)
#     def update(self):
#         nop

ser = serial.Serial('/dev/ttyACM0', 9600)

time = []
temperature = []
pressure = []

# fig = plt.figure()
# ax1 = fig.add_subplot(1,1,1)

# def animate(i):
#     raw = ser.readline.split(',')

while True:
    raw = ser.readline().split(',')
    print(raw)
    # print(f'Time: {raw[0]} Temperature: {raw[1]} Pressure: {raw[2]}')