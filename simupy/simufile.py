"""
simu.py
Displays data output from Arduino using matplotlib.
Original code: https://gist.github.com/electronut/d5e5f68c610821e311b0
"""
import sys, serial, argparse
import numpy as np
from time import sleep
from collections import deque

import matplotlib.pyplot as plt 
import matplotlib.animation as animation

    
# plot class
class plotter:
  # constr
  def __init__(self, file, maxLen):
      # open file
      self.inf = open(file,"r")

      self.ax = deque([0.0]*maxLen)
      self.ay = deque([0.0]*maxLen)
      self.maxLen = maxLen

  # add to buffer
  def addToBuf(self, buf, val):
      if len(buf) < self.maxLen:
          buf.append(val)
      else:
          buf.pop()
          buf.appendleft(val)

  # add data
  def add(self, data):
      assert(len(data) == 2)
      self.addToBuf(self.ax, data[0])
      self.addToBuf(self.ay, data[1])

  # update plot
  def update(self, frameNum, a0, a1):
      try:
          line = self.inf.readline().strip()
          if line:
            print(f'line:{line}')
            data = [float(val) for val in line.split(',')]
            # print data
            if(len(data) == 2):
                self.add(data)
                a0.set_data(range(self.maxLen), self.ax)
                a1.set_data(range(self.maxLen), self.ay)
      except KeyboardInterrupt:
          print('exiting')
      
      return a0, 

  # clean up
  def close(self):
      # close file
      self.inf.flush()
      self.inf.close()    

# main() function
def main():

  # plot parameters
  pl = plotter("test.txt", 100)

  print('plotting data...')

  # set up animation
  fig = plt.figure()
  ax = plt.axes(xlim=(0, 100), ylim=(0, 1023))
  a0, = ax.plot([], [])
  a1, = ax.plot([], [])
  anim = animation.FuncAnimation(fig, pl.update, 
                                 fargs=(a0, a1), 
                                 interval=50)

  # show plot
  plt.show()
  
  # clean up
  pl.close()

  print('exiting.')
  

# call main
if __name__ == '__main__':
  main()