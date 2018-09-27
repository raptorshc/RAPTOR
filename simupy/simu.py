"""
simu.py
Displays data output from a serial port using matplotlib.
Original code: https://gist.github.com/electronut/d5e5f68c610821e311b0
"""
import sys
import serial
import argparse
import numpy as np
import re
from time import sleep
from collections import deque

import matplotlib.pyplot as plt
import matplotlib.animation as animation


# plot class
class plotter:
    # constr
    def __init__(self, strPort, maxLen, axis):
        # open serial port
        self.ser = serial.Serial(strPort,baudrate=9600,
                     bytesize=serial.EIGHTBITS,
                     parity=serial.PARITY_NONE,
                     stopbits=serial.STOPBITS_ONE,
                     timeout=1,
                     xonxoff=0,
                     rtscts=0)
        # reset and flush input
        self.ser.setDTR(False)
        sleep(1)
        self.ser.flushInput()
        self.ser.setDTR(True)

        self.ax = deque([0.0]*maxLen)
        self.ay = deque([0.0]*maxLen)
        self.maxLen = maxLen

        self.axis = axis
        self.xlim = 200
        self.ylim = 10000

    # add to buffer
    def addToBuf(self, buf, val):
        if len(buf) < self.maxLen:
            buf.append(val)
        else:
            buf.pop()
            buf.appendleft(val)

    # add data
    def add(self, data):   
        self.addToBuf(self.ax, data[0])
        self.addToBuf(self.ay, data[1])

    # update plot
    def update(self, frameNum, a0, a1):
        try:
            line = self.ser.readline().strip().decode("ASCII")
            if line:
                data = [float(val) for val in line.split(',') if val]
                print(data)
                if(len(data) > 10):
                    self.add(data)
                    a0.set_data(self.ax, self.ay)

                    # update the limits
                    if(data[0] > self.xlim):
                        self.axis.set_xlim([0,data[0]])
                        self.xlim = data[0]
                    if(data[1] > self.ylim):
                        self.axis.set_ylim([0,data[1]])
                        self.ylim = data[1]
        except KeyboardInterrupt:
            print('exiting')
        except ValueError:
            pass

        return a0,

    # clean up
    def close(self):
        # close serial
        self.ser.flush()
        self.ser.close()

# main() function


def main():
    # create parser
    parser = argparse.ArgumentParser(description="LDR serial")
    # add expected arguments
    parser.add_argument('--port', dest='port', required=True)

    # parse args
    args = parser.parse_args()

    # strPort = '/dev/ttyACM0'
    strPort = args.port

    print('reading from serial port %s...' % strPort)

    # plot parameters
    fig = plt.figure()
    ax = plt.axes(xlim=(0,200), ylim=(0,10000))
    plot = plotter(strPort, 100, ax)

    print('plotting data...')

    # set up animation
    a0, = ax.plot([], [])
    a1, = ax.plot([], [])
    anim = animation.FuncAnimation(fig, plot.update,
                                   fargs=(a0, a1),
                                   interval=50)
    # show plot
    plt.show()

    # clean up
    plot.close()

    print('exiting.')


# call main
if __name__ == '__main__':
    main()