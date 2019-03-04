"""
live-plot.py
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
    def __init__(self, strPort, maxLen, axis1, axis2=False):
        # open serial port
        self.ser = serial.Serial(strPort, baudrate=9600,
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
        self.ay2 = deque([0.0]*maxLen)

        self.maxLen = maxLen

        self.axis1 = axis1
        self.axis2 = axis2  # ay2

        self.xlim = 100
        self.ylim1 = 100
        self.ylim2 = 100

    # add to buffer
    def addToBuf(self, buf, val):
        if len(buf) < self.maxLen:
            buf.append(val)
        else:
            buf.pop()
            buf.appendleft(val)

    # add data
    def add(self, data):
        try:
            self.addToBuf(self.ax, data[0])
            self.addToBuf(self.ay, data[1])

            if self.axis2:
                self.addToBuf(self.ay2, data[2])
        except IndexError:
            pass

    # update plot
    def update(self, frameNum, a0, a1=0):
        try:
            line = self.ser.readline().strip().decode("ASCII")
            if line:
                data = [float(val) for val in line.split(',') if val]
                print(data)
                if(len(data) > 0):
                    self.add(data)
                    a0.set_data(self.ax, self.ay)
                    if self.axis2:
                        a1.set_data(self.ay2)

                    # update the limits
                    if(data[0] > self.xlim):
                        self.axis1.set_xlim([0, data[0]])
                        self.xlim = data[0]
                    if(data[1] > self.ylim1):
                        self.ylim1 = data[1]
                        self.axis1.set_ylim([0, self.ylim1])
                    if self.axis2:
                        if(data[2] > self.ylim2):
                            self.ylim2 = data[2]
                            self.axis2.set_ylim([0, self.ylim2])
        except KeyboardInterrupt:
            print('exiting')
        except ValueError or IndexError:
            pass

        if self.axis2:
            return (a0, a1)
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
    parser.add_argument('--data', dest='datalist', nargs='+', required=False)

    # parse args
    args = parser.parse_args()

    # strPort = '/dev/ttyACM0'
    strPort = args.port

    print('reading from serial port %s...' % strPort)
    print('data: ')
    for item in args.datalist:
        print(item)

    # build plots
    if len(args.datalist) > 2:
        fig, (ax1, ax2) = plt.subplots(2, 1)
        ax1 = plt.axes(xlim=(0, 100), ylim=(0, 100))
        ax1.set_xlabel(args.datalist[0])
        ax1.set_ylabel(args.datalist[1])

        ax2 = ax1.twinx()
        ax2.set_ylim(0, 100)
        ax2.tick_params('y', colors='r')
        ax2.set_ylabel(args.datalist[2], color='r')

        plot = plotter(strPort, 100, axis1=ax1, axis2=ax2)

        print('plotting data...')

        # set up animation
        a0, = ax1.plot([], [])
        a1, = ax2.plot([], [])
        anim = animation.FuncAnimation(fig, plot.update,
                                       fargs=(a0, a1),
                                       interval=50)

    else:
        fig = plt.figure()
        ax = plt.axes(xlim=(0, 100), ylim=(0, 100))
        ax.set_xlabel(args.datalist[0])
        ax.set_ylabel(args.datalist[1])
        plot = plotter(strPort, 100, axis1=ax)

        print('plotting data...')

        # set up animation
        a0 = ax.plot([], [])
        anim = animation.FuncAnimation(fig, plot.update,
                                       fargs=(a0),
                                       interval=50)

    # show plot
    plt.show()

    # clean up
    plot.close()

    print('exiting.')


# call main
if __name__ == '__main__':
    main()
