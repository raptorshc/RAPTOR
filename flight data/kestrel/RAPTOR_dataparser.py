import csv
import matplotlib.pyplot as plt

csvfile = open('DATA2.csv', encoding='latin1')
raw = csv.reader(csvfile, delimiter=',')

time = []
temperature = []
pressure = []
altitude = []
servo1 = []
servo2 = []
solenoid1 = []
solenoid2 = []

for row in raw:
    time.append(float(row[0]))
    temperature.append(float(row[1]))
    pressure.append(float(row[2]))
    altitude.append(float(row[3]))
    servo1.append(row[4])
    servo2.append(row[5])
    solenoid1.append(row[6])
    solenoid2.append(row[7])


#AXIS 1, TEMPERATURE
fig, ax1 = plt.subplots()
ax1.plot(time, temperature, 'b')
ax1.set_xlabel('time (s)')

ax1.set_ylabel('temperature (c)',color='b')
ax1.tick_params('y', colors='b')

#Keep track of what data is present for the legend
present = ['Temperature']
#Insert failures as scatter dots
for x in range(0,len(time)-1):
    if servo1[x] == "FALSE": #If there was a failure
        ax1.scatter(time[x],temperature[x], c='y')
        if 'Servo 1 Failure' not in present:
            present.append('Servo 1 Failure')

        
    if servo2[x] == "FALSE":
        ax1.scatter(time[x],temperature[x], c='g')
        if 'Servo 2 Failure' not in present:
            present.append('Servo 2 Failure')

            
    if solenoid1[x] == "FALSE":
        ax1.scatter(time[x],temperature[x], color='r')
        if 'Solenoid 1 Failure' not in present:
            present.append('Solenoid 1 Failure')
            
    if solenoid2[x] == "TRUE": #For the first flight data, change to FALSE
        ax1.scatter(time[x],temperature[x], c='p')
        if 'Solenoid 2 Failure' not in present:
            present.append('Solenoid 2 Failure')

#AXIS 2, PRESSURE
##ax2 = ax1.twinx()
##ax2.plot(time, pressure, 'g')
##
##ax2.set_ylabel('pressure (mb)',color='g')
##ax2.tick_params('y', colors='g')

#AXIS 3, ALTITUDE
##ax3 = ax1.twinx()
##ax3.plot(time, altitude, 'r')
##
##ax3.set_ylabel('altitude (m)',color='r')
##ax3.tick_params('y', colors='r')

ax1.legend(present)
fig.tight_layout()
plt.show() 
