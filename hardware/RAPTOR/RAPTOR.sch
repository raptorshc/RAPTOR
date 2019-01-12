EESchema Schematic File Version 4
LIBS:RAPTOR-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "RAPTOR Schematic"
Date "2019-01-12"
Rev "PHOENIX 0.5.6"
Comp ""
Comment1 ""
Comment2 "- LED resistors"
Comment3 "todo:"
Comment4 "Arduino (HiLetGo UNO R3) Shield"
$EndDescr
Text Label 8950 1450 1    60   ~ 0
Vin
Text Label 9350 1450 1    60   ~ 0
IOREF
Text Label 8900 2500 0    60   ~ 0
A0
Text Label 8900 2600 0    60   ~ 0
A1
Text Label 8900 2700 0    60   ~ 0
A2
Text Label 8900 2800 0    60   ~ 0
A3
Text Label 8900 2900 0    60   ~ 0
A4(SDA)
Text Label 8900 3000 0    60   ~ 0
A5(SCL)
Text Label 10550 3000 0    60   ~ 0
0(Rx)
Text Label 10550 2800 0    60   ~ 0
2
Text Label 10550 2900 0    60   ~ 0
1(Tx)
Text Label 10550 2700 0    60   ~ 0
3(**)
Text Label 10550 2600 0    60   ~ 0
4
Text Label 10550 2500 0    60   ~ 0
5(**)
Text Label 10550 2400 0    60   ~ 0
6(**)
Text Label 10550 2300 0    60   ~ 0
7
Text Label 10550 2100 0    60   ~ 0
8
Text Label 10550 2000 0    60   ~ 0
9(**)
Text Label 10550 1900 0    60   ~ 0
10(**/SS)
Text Label 10550 1800 0    60   ~ 0
11(**/MOSI)
Text Label 10550 1700 0    60   ~ 0
12(MISO)
Text Label 10550 1600 0    60   ~ 0
13(SCK)
Text Label 10550 1400 0    60   ~ 0
AREF
NoConn ~ 9400 1600
Text Label 10550 1300 0    60   ~ 0
A4(SDA)
Text Label 10550 1200 0    60   ~ 0
A5(SCL)
Text Notes 10850 1000 0    60   ~ 0
Holes
Text Notes 8550 750  0    60   ~ 0
Shield for Arduino that uses\nthe same pin disposition\nlike "Uno" board Rev 3.
$Comp
L Connector_Generic:Conn_01x08 P1
U 1 1 56D70129
P 9600 1900
F 0 "P1" H 9600 2350 50  0000 C CNN
F 1 "Power" V 9700 1900 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x08" V 9750 1900 20  0000 C CNN
F 3 "" H 9600 1900 50  0000 C CNN
	1    9600 1900
	1    0    0    -1  
$EndComp
Text Label 8650 1800 0    60   ~ 0
Reset
$Comp
L power:+3.3V #PWR01
U 1 1 56D70538
P 9150 1450
F 0 "#PWR01" H 9150 1300 50  0001 C CNN
F 1 "+3.3V" V 9150 1700 50  0000 C CNN
F 2 "" H 9150 1450 50  0000 C CNN
F 3 "" H 9150 1450 50  0000 C CNN
	1    9150 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR02
U 1 1 56D707BB
P 9050 1350
F 0 "#PWR02" H 9050 1200 50  0001 C CNN
F 1 "+5V" V 9050 1550 50  0000 C CNN
F 2 "" H 9050 1350 50  0000 C CNN
F 3 "" H 9050 1350 50  0000 C CNN
	1    9050 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 56D70CC2
P 9300 3150
F 0 "#PWR03" H 9300 2900 50  0001 C CNN
F 1 "GND" H 9300 3000 50  0000 C CNN
F 2 "" H 9300 3150 50  0000 C CNN
F 3 "" H 9300 3150 50  0000 C CNN
	1    9300 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 56D70CFF
P 10300 3150
F 0 "#PWR04" H 10300 2900 50  0001 C CNN
F 1 "GND" H 10300 3000 50  0000 C CNN
F 2 "" H 10300 3150 50  0000 C CNN
F 3 "" H 10300 3150 50  0000 C CNN
	1    10300 3150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 P2
U 1 1 56D70DD8
P 9600 2700
F 0 "P2" H 9600 2300 50  0000 C CNN
F 1 "Analog" V 9700 2700 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x06" V 9750 2750 20  0000 C CNN
F 3 "" H 9600 2700 50  0000 C CNN
	1    9600 2700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P5
U 1 1 56D71177
P 10800 650
F 0 "P5" V 10900 650 50  0000 C CNN
F 1 "CONN_01X01" V 10900 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 10721 724 20  0000 C CNN
F 3 "" H 10800 650 50  0000 C CNN
	1    10800 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P6
U 1 1 56D71274
P 10900 650
F 0 "P6" V 11000 650 50  0000 C CNN
F 1 "CONN_01X01" V 11000 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 10900 650 20  0001 C CNN
F 3 "" H 10900 650 50  0000 C CNN
	1    10900 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P7
U 1 1 56D712A8
P 11000 650
F 0 "P7" V 11100 650 50  0000 C CNN
F 1 "CONN_01X01" V 11100 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" V 11000 650 20  0001 C CNN
F 3 "" H 11000 650 50  0000 C CNN
	1    11000 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P8
U 1 1 56D712DB
P 11100 650
F 0 "P8" V 11200 650 50  0000 C CNN
F 1 "CONN_01X01" V 11200 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 11024 572 20  0000 C CNN
F 3 "" H 11100 650 50  0000 C CNN
	1    11100 650 
	0    -1   -1   0   
$EndComp
NoConn ~ 10800 850 
NoConn ~ 10900 850 
NoConn ~ 11000 850 
NoConn ~ 11100 850 
$Comp
L Connector_Generic:Conn_01x08 P4
U 1 1 56D7164F
P 10000 2600
F 0 "P4" H 10000 2100 50  0000 C CNN
F 1 "Digital" V 10100 2600 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x08" V 10150 2550 20  0000 C CNN
F 3 "" H 10000 2600 50  0000 C CNN
	1    10000 2600
	-1   0    0    -1  
$EndComp
Wire Notes Line
	8525 825  9925 825 
Wire Notes Line
	9925 825  9925 475 
Wire Wire Line
	9350 1450 9350 1700
Wire Wire Line
	9350 1700 9400 1700
Wire Wire Line
	9400 1900 9150 1900
Wire Wire Line
	9400 2000 9050 2000
Wire Wire Line
	9400 2300 8950 2300
Wire Wire Line
	9400 2100 9300 2100
Wire Wire Line
	9400 2200 9300 2200
Connection ~ 9300 2200
Wire Wire Line
	8950 2300 8950 1450
Wire Wire Line
	9050 2000 9050 1350
Wire Wire Line
	9150 1900 9150 1450
Wire Wire Line
	9400 2500 8900 2500
Wire Wire Line
	9400 2600 8900 2600
Wire Wire Line
	9400 2700 8900 2700
Wire Wire Line
	9400 2800 8900 2800
Wire Wire Line
	9400 2900 8900 2900
Wire Wire Line
	9400 3000 8900 3000
$Comp
L Connector_Generic:Conn_01x10 P3
U 1 1 56D721E0
P 10000 1600
F 0 "P3" H 10000 2150 50  0000 C CNN
F 1 "Digital" V 10100 1600 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x10" V 10150 1600 20  0000 C CNN
F 3 "" H 10000 1600 50  0000 C CNN
	1    10000 1600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10200 2100 10550 2100
Wire Wire Line
	10200 2000 10550 2000
Wire Wire Line
	10200 1900 10550 1900
Wire Wire Line
	10200 1800 10550 1800
Wire Wire Line
	10200 1700 10550 1700
Wire Wire Line
	10200 1600 10550 1600
Wire Wire Line
	10200 1400 10550 1400
Wire Wire Line
	10200 1300 10550 1300
Wire Wire Line
	10200 1200 10550 1200
Wire Wire Line
	10200 3000 10550 3000
Wire Wire Line
	10200 2900 10550 2900
Wire Wire Line
	10200 2800 10550 2800
Wire Wire Line
	10200 2700 10550 2700
Wire Wire Line
	10200 2600 10550 2600
Wire Wire Line
	10200 2500 10550 2500
Wire Wire Line
	10200 2400 10550 2400
Wire Wire Line
	10200 2300 10550 2300
Wire Wire Line
	10200 1500 10300 1500
Wire Wire Line
	10300 1500 10300 3150
Wire Wire Line
	9300 2100 9300 2200
Wire Wire Line
	9300 2200 9300 3150
Wire Notes Line
	8500 500  8500 3450
Wire Notes Line
	8500 3450 11200 3450
Wire Wire Line
	9400 1800 8650 1800
Text Notes 9700 1600 0    60   ~ 0
1
Wire Notes Line
	11200 1000 10700 1000
Wire Notes Line
	10700 1000 10700 500 
$Comp
L RAPTOR-rescue:BMP280-bmp280 U1
U 1 1 5BD31CAC
P 1400 1000
F 0 "U1" H 1400 1454 45  0000 C CNN
F 1 "BMP280 Breakout" H 1400 1370 45  0000 C CNN
F 2 "RAPTOR_footprints:BMP280" H 1400 1450 20  0001 C CNN
F 3 "https://learn.adafruit.com/adafruit-bmp280-barometric-pressure-plus-temperature-sensor-breakout/overview" H 1400 1000 60  0001 C CNN
	1    1400 1000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0101
U 1 1 5BD35138
P 650 700
F 0 "#PWR0101" H 650 550 50  0001 C CNN
F 1 "+5V" H 665 873 50  0000 C CNN
F 2 "" H 650 700 50  0001 C CNN
F 3 "" H 650 700 50  0001 C CNN
	1    650  700 
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  700  650  800 
Wire Wire Line
	650  800  850  800 
$Comp
L power:GND #PWR0102
U 1 1 5BD35A48
P 650 1400
F 0 "#PWR0102" H 650 1150 50  0001 C CNN
F 1 "GND" H 655 1227 50  0000 C CNN
F 2 "" H 650 1400 50  0001 C CNN
F 3 "" H 650 1400 50  0001 C CNN
	1    650  1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  1300 650  1300
Wire Wire Line
	650  1300 650  1400
Text Label 2300 1100 0    50   ~ 0
A5(SCL)
Text Label 2300 1000 0    50   ~ 0
A4(SDA)
Wire Wire Line
	1950 1000 2300 1000
Wire Wire Line
	1950 1100 2300 1100
$Comp
L RAPTOR-rescue:BNO055-bno055 U2
U 1 1 5BD45163
P 1400 2150
F 0 "U2" H 1400 2604 45  0000 C CNN
F 1 "BNO055 Breakout" H 1400 2520 45  0000 C CNN
F 2 "RAPTOR_footprints:BNO055" H 1400 2600 20  0001 C CNN
F 3 "https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor/overview" H 1400 2150 60  0001 C CNN
	1    1400 2150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5BD4727B
P 650 1850
F 0 "#PWR0103" H 650 1700 50  0001 C CNN
F 1 "+5V" H 665 2023 50  0000 C CNN
F 2 "" H 650 1850 50  0001 C CNN
F 3 "" H 650 1850 50  0001 C CNN
	1    650  1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  1850 650  1950
Wire Wire Line
	650  1950 850  1950
$Comp
L power:GND #PWR0104
U 1 1 5BD47283
P 650 2550
F 0 "#PWR0104" H 650 2300 50  0001 C CNN
F 1 "GND" H 655 2377 50  0000 C CNN
F 2 "" H 650 2550 50  0001 C CNN
F 3 "" H 650 2550 50  0001 C CNN
	1    650  2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  2450 650  2450
Wire Wire Line
	650  2450 650  2550
Text Label 2300 2150 0    50   ~ 0
A5(SCL)
Text Label 2300 2000 0    50   ~ 0
A4(SDA)
Wire Wire Line
	1950 2150 2300 2150
Wire Wire Line
	1950 2000 2300 2000
$Comp
L RAPTOR-rescue:OpenLog-openlog U3
U 1 1 5BDE8282
P 1350 3250
F 0 "U3" H 1350 3704 45  0000 C CNN
F 1 "OpenLog" H 1350 3620 45  0000 C CNN
F 2 "RAPTOR_footprints:OpenLog" H 1350 3700 20  0001 C CNN
F 3 "https://learn.sparkfun.com/tutorials/openlog-hookup-guide/all" H 1350 3250 60  0001 C CNN
	1    1350 3250
	1    0    0    -1  
$EndComp
$Comp
L RAPTOR-rescue:AdafruitGPS-adafruitgps U4
U 1 1 5BDE25E6
P 1500 4450
F 0 "U4" H 1500 4975 50  0000 C CNN
F 1 "AdafruitGPS" H 1500 4884 50  0000 C CNN
F 2 "RAPTOR_footprints:AdafruitGPS" H 1600 4400 50  0001 C CNN
F 3 "https://learn.adafruit.com/adafruit-ultimate-gps" H 1600 4400 50  0001 C CNN
	1    1500 4450
	1    0    0    -1  
$EndComp
Text Label 2250 3500 0    50   ~ 0
0(Rx)
Wire Wire Line
	1900 3500 2250 3500
Text Label 2250 3100 0    50   ~ 0
1(Tx)
Wire Wire Line
	1900 3100 2250 3100
$Comp
L power:GND #PWR0105
U 1 1 5BDE53C7
P 600 3650
F 0 "#PWR0105" H 600 3400 50  0001 C CNN
F 1 "GND" H 605 3477 50  0000 C CNN
F 2 "" H 600 3650 50  0001 C CNN
F 3 "" H 600 3650 50  0001 C CNN
	1    600  3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  3550 600  3550
Wire Wire Line
	600  3550 600  3650
$Comp
L power:GND #PWR0106
U 1 1 5BDE7CE6
P 600 4900
F 0 "#PWR0106" H 600 4650 50  0001 C CNN
F 1 "GND" H 605 4727 50  0000 C CNN
F 2 "" H 600 4900 50  0001 C CNN
F 3 "" H 600 4900 50  0001 C CNN
	1    600  4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  4800 600  4800
Wire Wire Line
	600  4800 600  4900
$Comp
L power:+5V #PWR0107
U 1 1 5BDE90FA
P 600 4100
F 0 "#PWR0107" H 600 3950 50  0001 C CNN
F 1 "+5V" H 615 4273 50  0000 C CNN
F 2 "" H 600 4100 50  0001 C CNN
F 3 "" H 600 4100 50  0001 C CNN
	1    600  4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	600  4100 600  4200
Wire Wire Line
	600  4200 800  4200
$Comp
L power:+5V #PWR0108
U 1 1 5BDEA4F5
P 600 3000
F 0 "#PWR0108" H 600 2850 50  0001 C CNN
F 1 "+5V" H 615 3173 50  0000 C CNN
F 2 "" H 600 3000 50  0001 C CNN
F 3 "" H 600 3000 50  0001 C CNN
	1    600  3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	600  3000 600  3100
Wire Wire Line
	600  3100 800  3100
Text Label 2550 4300 0    50   ~ 0
3(**)
Wire Wire Line
	2200 4300 2550 4300
Text Label 2550 4450 0    50   ~ 0
2
Wire Wire Line
	2200 4450 2550 4450
Text Label 2550 4750 0    50   ~ 0
FIX_LED
Wire Wire Line
	2200 4750 2550 4750
NoConn ~ 800  4300
NoConn ~ 800  4450
NoConn ~ 2200 4600
NoConn ~ 2200 4150
NoConn ~ 800  3350
NoConn ~ 800  3450
NoConn ~ 850  2150
NoConn ~ 850  1000
NoConn ~ 1950 800 
NoConn ~ 1950 1300
$Comp
L Motor:Motor_Servo M1
U 1 1 5BE79CAA
P 4950 1650
F 0 "M1" H 4946 1343 50  0000 C CNN
F 1 "AR-3606HB" H 4946 1434 50  0000 C CNN
F 2 "" H 4950 1460 50  0001 C CNN
F 3 "https://www.pololu.com/product/2149" H 4950 1460 50  0001 C CNN
	1    4950 1650
	-1   0    0    1   
$EndComp
Text Label 5650 1750 0    50   ~ 0
6(**)
Wire Wire Line
	5250 1750 5650 1750
$Comp
L power:+6V #PWR0109
U 1 1 5BE7EDED
P 5550 1500
F 0 "#PWR0109" H 5550 1350 50  0001 C CNN
F 1 "+6V" H 5565 1673 50  0000 C CNN
F 2 "" H 5550 1500 50  0001 C CNN
F 3 "" H 5550 1500 50  0001 C CNN
	1    5550 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5BE823AD
P 5400 1350
F 0 "#PWR0110" H 5400 1100 50  0001 C CNN
F 1 "GND" H 5405 1177 50  0000 C CNN
F 2 "" H 5400 1350 50  0001 C CNN
F 3 "" H 5400 1350 50  0001 C CNN
	1    5400 1350
	-1   0    0    1   
$EndComp
Wire Wire Line
	5250 1550 5400 1550
Wire Wire Line
	5400 1550 5400 1350
Wire Wire Line
	5250 1650 5550 1650
Wire Wire Line
	5550 1650 5550 1500
$Comp
L Motor:Motor_Servo M2
U 1 1 5BE85BA8
P 4950 1000
F 0 "M2" H 4946 693 50  0000 C CNN
F 1 "AR-3606HB" H 4946 784 50  0000 C CNN
F 2 "" H 4950 810 50  0001 C CNN
F 3 "https://www.pololu.com/product/2149" H 4950 810 50  0001 C CNN
	1    4950 1000
	-1   0    0    1   
$EndComp
Text Label 5650 1100 0    50   ~ 0
5(**)
Wire Wire Line
	5250 1100 5650 1100
$Comp
L power:GND #PWR0112
U 1 1 5BE85BB7
P 5400 700
F 0 "#PWR0112" H 5400 450 50  0001 C CNN
F 1 "GND" H 5405 527 50  0000 C CNN
F 2 "" H 5400 700 50  0001 C CNN
F 3 "" H 5400 700 50  0001 C CNN
	1    5400 700 
	-1   0    0    1   
$EndComp
Wire Wire Line
	5250 900  5400 900 
Wire Wire Line
	5400 900  5400 700 
Wire Wire Line
	5250 1000 5550 1000
Wire Wire Line
	5550 1000 5550 850 
$Comp
L power:+12V #PWR0113
U 1 1 5BE8A086
P 4950 2100
F 0 "#PWR0113" H 4950 1950 50  0001 C CNN
F 1 "+12V" H 4965 2273 50  0000 C CNN
F 2 "" H 4950 2100 50  0001 C CNN
F 3 "" H 4950 2100 50  0001 C CNN
	1    4950 2100
	1    0    0    -1  
$EndComp
$Comp
L RAPTOR-rescue:MOSFET-NCH-2N7002PW-SparkFun-DiscreteSemi Q1
U 1 1 5BE8A581
P 4850 2400
F 0 "Q1" H 5015 2495 45  0000 L CNN
F 1 "MOSFET-NCH-2N7002PW" H 5015 2411 45  0000 L CNN
F 2 "SOT323" H 4850 2700 20  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds11303.pdf" H 4850 2400 50  0001 C CNN
F 4 "TRANS-11151" H 5015 2316 60  0000 L CNN "Field4"
	1    4850 2400
	1    0    0    -1  
$EndComp
Text Label 4350 2500 0    50   ~ 0
8
Wire Wire Line
	4650 2500 4350 2500
Wire Wire Line
	4950 2100 4950 2200
$Comp
L Device:Buzzer BZ1
U 1 1 5BEADE3C
P 3700 5150
F 0 "BZ1" H 3853 5179 50  0000 L CNN
F 1 "Buzzer" H 3853 5088 50  0000 L CNN
F 2 "" V 3675 5250 50  0001 C CNN
F 3 "~" V 3675 5250 50  0001 C CNN
	1    3700 5150
	1    0    0    -1  
$EndComp
$Comp
L RAPTOR-rescue:MOSFET-NCH-2N7002PW-SparkFun-DiscreteSemi Q3
U 1 1 5BEB292C
P 3500 4700
F 0 "Q3" H 3665 4795 45  0000 L CNN
F 1 "MOSFET-NCH-2N7002PW" H 3665 4711 45  0000 L CNN
F 2 "SOT323" H 3500 5000 20  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds11303.pdf" H 3500 4700 50  0001 C CNN
F 4 "TRANS-11151" H 3665 4616 60  0000 L CNN "Field4"
	1    3500 4700
	1    0    0    -1  
$EndComp
Text Label 2900 4800 0    50   ~ 0
11
Wire Wire Line
	3300 4800 2900 4800
$Comp
L power:+6V #PWR0115
U 1 1 5BEB715A
P 3600 4400
F 0 "#PWR0115" H 3600 4250 50  0001 C CNN
F 1 "+6V" H 3615 4573 50  0000 C CNN
F 2 "" H 3600 4400 50  0001 C CNN
F 3 "" H 3600 4400 50  0001 C CNN
	1    3600 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 4900 3600 5050
$Comp
L power:GND #PWR0116
U 1 1 5BEBE024
P 3600 5400
F 0 "#PWR0116" H 3600 5150 50  0001 C CNN
F 1 "GND" H 3605 5227 50  0000 C CNN
F 2 "" H 3600 5400 50  0001 C CNN
F 3 "" H 3600 5400 50  0001 C CNN
	1    3600 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 5250 3600 5400
Wire Wire Line
	3600 4500 3600 4400
$Comp
L Device:LED D1
U 1 1 5BEC62B7
P 2400 5500
F 0 "D1" H 2391 5716 50  0000 C CNN
F 1 "LED" H 2391 5625 50  0000 C CNN
F 2 "" H 2400 5500 50  0001 C CNN
F 3 "~" H 2400 5500 50  0001 C CNN
	1    2400 5500
	1    0    0    -1  
$EndComp
Text Label 2650 5500 0    50   ~ 0
FIX_LED
$Comp
L power:GND #PWR0117
U 1 1 5BEC8E4F
P 2100 5600
F 0 "#PWR0117" H 2100 5350 50  0001 C CNN
F 1 "GND" H 2105 5427 50  0000 C CNN
F 2 "" H 2100 5600 50  0001 C CNN
F 3 "" H 2100 5600 50  0001 C CNN
	1    2100 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 5500 2100 5500
Wire Wire Line
	2100 5500 2100 5600
Wire Wire Line
	2550 5500 2650 5500
$Comp
L Device:LED D2
U 1 1 5BECDE5B
P 2400 6400
F 0 "D2" H 2391 6616 50  0000 C CNN
F 1 "SOLP_LED" H 2391 6525 50  0000 C CNN
F 2 "" H 2400 6400 50  0001 C CNN
F 3 "~" H 2400 6400 50  0001 C CNN
	1    2400 6400
	1    0    0    -1  
$EndComp
Text Label 2650 6400 0    50   ~ 0
A2
$Comp
L power:GND #PWR0118
U 1 1 5BECDE63
P 2100 6500
F 0 "#PWR0118" H 2100 6250 50  0001 C CNN
F 1 "GND" H 2105 6327 50  0000 C CNN
F 2 "" H 2100 6500 50  0001 C CNN
F 3 "" H 2100 6500 50  0001 C CNN
	1    2100 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 6400 2100 6400
Wire Wire Line
	2100 6400 2100 6500
Wire Wire Line
	2550 6400 2650 6400
$Comp
L Device:LED D3
U 1 1 5BED08A1
P 2400 7200
F 0 "D3" H 2391 7416 50  0000 C CNN
F 1 "SOLC_LED" H 2391 7325 50  0000 C CNN
F 2 "" H 2400 7200 50  0001 C CNN
F 3 "~" H 2400 7200 50  0001 C CNN
	1    2400 7200
	1    0    0    -1  
$EndComp
Text Label 2650 7200 0    50   ~ 0
A3
$Comp
L power:GND #PWR0119
U 1 1 5BED08A9
P 2100 7300
F 0 "#PWR0119" H 2100 7050 50  0001 C CNN
F 1 "GND" H 2105 7127 50  0000 C CNN
F 2 "" H 2100 7300 50  0001 C CNN
F 3 "" H 2100 7300 50  0001 C CNN
	1    2100 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 7200 2100 7200
Wire Wire Line
	2100 7200 2100 7300
Wire Wire Line
	2550 7200 2650 7200
$Comp
L Switch:SW_SPST SW1
U 1 1 5BED49C4
P 950 5500
F 0 "SW1" H 950 5735 50  0000 C CNN
F 1 "EEPROM_BTN" H 950 5644 50  0000 C CNN
F 2 "" H 950 5500 50  0001 C CNN
F 3 "" H 950 5500 50  0001 C CNN
	1    950  5500
	1    0    0    -1  
$EndComp
Text Label 1350 5500 0    50   ~ 0
7
$Comp
L power:+5V #PWR0120
U 1 1 5BED5ECD
P 600 5450
F 0 "#PWR0120" H 600 5300 50  0001 C CNN
F 1 "+5V" H 615 5623 50  0000 C CNN
F 2 "" H 600 5450 50  0001 C CNN
F 3 "" H 600 5450 50  0001 C CNN
	1    600  5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	600  5450 600  5500
Wire Wire Line
	600  5500 750  5500
Wire Wire Line
	1150 5500 1350 5500
$Comp
L Switch:SW_SPST SW2
U 1 1 5BEDC896
P 950 6400
F 0 "SW2" H 950 6635 50  0000 C CNN
F 1 "SOLP_SW" H 950 6544 50  0000 C CNN
F 2 "" H 950 6400 50  0001 C CNN
F 3 "" H 950 6400 50  0001 C CNN
	1    950  6400
	1    0    0    -1  
$EndComp
Text Label 1350 6400 0    50   ~ 0
A0
$Comp
L power:+5V #PWR0121
U 1 1 5BEDC89E
P 600 6350
F 0 "#PWR0121" H 600 6200 50  0001 C CNN
F 1 "+5V" H 615 6523 50  0000 C CNN
F 2 "" H 600 6350 50  0001 C CNN
F 3 "" H 600 6350 50  0001 C CNN
	1    600  6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	600  6350 600  6400
Wire Wire Line
	600  6400 750  6400
Wire Wire Line
	1150 6400 1350 6400
$Comp
L Switch:SW_SPST SW3
U 1 1 5BEDFD43
P 900 7200
F 0 "SW3" H 900 7435 50  0000 C CNN
F 1 "SOLC_SW" H 900 7344 50  0000 C CNN
F 2 "" H 900 7200 50  0001 C CNN
F 3 "" H 900 7200 50  0001 C CNN
	1    900  7200
	1    0    0    -1  
$EndComp
Text Label 1300 7200 0    50   ~ 0
A1
$Comp
L power:+5V #PWR0122
U 1 1 5BEDFD4B
P 550 7150
F 0 "#PWR0122" H 550 7000 50  0001 C CNN
F 1 "+5V" H 565 7323 50  0000 C CNN
F 2 "" H 550 7150 50  0001 C CNN
F 3 "" H 550 7150 50  0001 C CNN
	1    550  7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	550  7150 550  7200
Wire Wire Line
	550  7200 700  7200
Wire Wire Line
	1100 7200 1300 7200
$Comp
L Device:LED D4
U 1 1 5BEE4EBE
P 3250 6650
F 0 "D4" H 3241 6866 50  0000 C CNN
F 1 "SOLP_LED" H 3241 6775 50  0000 C CNN
F 2 "" H 3250 6650 50  0001 C CNN
F 3 "~" H 3250 6650 50  0001 C CNN
	1    3250 6650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 5BEE4EC6
P 2950 6750
F 0 "#PWR0123" H 2950 6500 50  0001 C CNN
F 1 "GND" H 2955 6577 50  0000 C CNN
F 2 "" H 2950 6750 50  0001 C CNN
F 3 "" H 2950 6750 50  0001 C CNN
	1    2950 6750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 6650 2950 6650
Wire Wire Line
	2950 6650 2950 6750
$Comp
L Device:LED D5
U 1 1 5BEE4ECF
P 3250 7050
F 0 "D5" H 3241 7266 50  0000 C CNN
F 1 "SOLC_LED" H 3241 7175 50  0000 C CNN
F 2 "" H 3250 7050 50  0001 C CNN
F 3 "~" H 3250 7050 50  0001 C CNN
	1    3250 7050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0124
U 1 1 5BEE4ED7
P 2950 7150
F 0 "#PWR0124" H 2950 6900 50  0001 C CNN
F 1 "GND" H 2955 6977 50  0000 C CNN
F 2 "" H 2950 7150 50  0001 C CNN
F 3 "" H 2950 7150 50  0001 C CNN
	1    2950 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 7050 2950 7050
Wire Wire Line
	2950 7050 2950 7150
$Comp
L Device:LED D7
U 1 1 5BEE8A04
P 4000 7050
F 0 "D7" H 3991 7266 50  0000 C CNN
F 1 "SOLP_LED" H 3991 7175 50  0000 C CNN
F 2 "" H 4000 7050 50  0001 C CNN
F 3 "~" H 4000 7050 50  0001 C CNN
	1    4000 7050
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0125
U 1 1 5BEE8A0C
P 4300 7150
F 0 "#PWR0125" H 4300 6900 50  0001 C CNN
F 1 "GND" H 4305 6977 50  0000 C CNN
F 2 "" H 4300 7150 50  0001 C CNN
F 3 "" H 4300 7150 50  0001 C CNN
	1    4300 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 7050 4300 7050
$Comp
L Device:LED D6
U 1 1 5BEE8A15
P 4000 6650
F 0 "D6" H 3991 6866 50  0000 C CNN
F 1 "SOLC_LED" H 3991 6775 50  0000 C CNN
F 2 "" H 4000 6650 50  0001 C CNN
F 3 "~" H 4000 6650 50  0001 C CNN
	1    4000 6650
	-1   0    0    1   
$EndComp
Wire Wire Line
	4300 7050 4300 7150
$Comp
L power:GND #PWR0126
U 1 1 5BF1D48C
P 4300 6750
F 0 "#PWR0126" H 4300 6500 50  0001 C CNN
F 1 "GND" H 4305 6577 50  0000 C CNN
F 2 "" H 4300 6750 50  0001 C CNN
F 3 "" H 4300 6750 50  0001 C CNN
	1    4300 6750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 6650 4300 6650
Wire Wire Line
	4300 6650 4300 6750
Wire Wire Line
	3400 6650 3650 6650
Wire Wire Line
	3850 7050 3650 7050
Wire Wire Line
	3650 7050 3650 6650
Connection ~ 3650 7050
Wire Wire Line
	3650 7050 3400 7050
Connection ~ 3650 6650
Wire Wire Line
	3650 6650 3850 6650
Text Label 3150 6350 0    50   ~ 0
12
$Comp
L RAPTOR-rescue:MOSFET-NCH-2N7002PW-SparkFun-DiscreteSemi Q4
U 1 1 5BF36D0B
P 3550 6250
F 0 "Q4" H 3715 6345 45  0000 L CNN
F 1 "MOSFET-NCH-2N7002PW" H 3715 6261 45  0000 L CNN
F 2 "SOT323" H 3550 6550 20  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds11303.pdf" H 3550 6250 50  0001 C CNN
F 4 "TRANS-11151" H 3715 6166 60  0000 L CNN "Field4"
	1    3550 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 6450 3650 6650
Wire Wire Line
	3650 6050 3650 5850
Wire Wire Line
	3350 6350 3150 6350
$Comp
L power:+3.3V #PWR0127
U 1 1 5BF54F36
P 3650 5850
F 0 "#PWR0127" H 3650 5700 50  0001 C CNN
F 1 "+3.3V" H 3665 6023 50  0000 C CNN
F 2 "" H 3650 5850 50  0001 C CNN
F 3 "" H 3650 5850 50  0001 C CNN
	1    3650 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery BT1
U 1 1 5C3C688C
P 3550 3450
F 0 "BT1" H 3658 3496 50  0000 L CNN
F 1 "7.4V" H 3658 3405 50  0000 L CNN
F 2 "" V 3550 3510 50  0001 C CNN
F 3 "~" V 3550 3510 50  0001 C CNN
	1    3550 3450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5C40FAEF
P 3550 2400
F 0 "#PWR012" H 3550 2150 50  0001 C CNN
F 1 "GND" H 3555 2227 50  0000 C CNN
F 2 "" H 3550 2400 50  0001 C CNN
F 3 "" H 3550 2400 50  0001 C CNN
	1    3550 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 2250 3550 2400
$Comp
L power:+7.5V #PWR011
U 1 1 5C42772B
P 3000 1900
F 0 "#PWR011" H 3000 1750 50  0001 C CNN
F 1 "+7.5V" H 3015 2073 50  0001 C CNN
F 2 "" H 3000 1900 50  0001 C CNN
F 3 "" H 3000 1900 50  0001 C CNN
F 4 "+7.4V" H 3015 2073 50  0000 C CNN "Real Value"
	1    3000 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 1950 3000 1950
Wire Wire Line
	3850 1950 4100 1950
$Comp
L power:+12V #PWR013
U 1 1 5C4334FC
P 4100 1900
F 0 "#PWR013" H 4100 1750 50  0001 C CNN
F 1 "+12V" H 4115 2165 50  0000 C CNN
F 2 "" H 4100 1900 50  0001 C CNN
F 3 "" H 4100 1900 50  0001 C CNN
F 4 "(TO SOLENOID)" H 4115 2074 50  0000 C CNN "Note"
	1    4100 1900
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR014
U 1 1 5C442A87
P 5550 850
F 0 "#PWR014" H 5550 700 50  0001 C CNN
F 1 "+5V" H 5565 1023 50  0000 C CNN
F 2 "" H 5550 850 50  0001 C CNN
F 3 "" H 5550 850 50  0001 C CNN
	1    5550 850 
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7805 U6
U 1 1 5C49E003
P 3550 700
F 0 "U6" H 3550 942 50  0000 C CNN
F 1 "L7805" H 3550 851 50  0000 C CNN
F 2 "" H 3575 550 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 3550 650 50  0001 C CNN
	1    3550 700 
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5C49E00A
P 4100 1000
F 0 "C4" H 4215 1046 50  0000 L CNN
F 1 "0.1uF" H 4215 955 50  0000 L CNN
F 2 "" H 4138 850 50  0001 C CNN
F 3 "~" H 4100 1000 50  0001 C CNN
	1    4100 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5C49E011
P 2950 1000
F 0 "C2" H 3065 1046 50  0000 L CNN
F 1 "0.33 uF" H 3065 955 50  0000 L CNN
F 2 "" H 2988 850 50  0001 C CNN
F 3 "~" H 2950 1000 50  0001 C CNN
	1    2950 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 700  2950 700 
Wire Wire Line
	2950 700  2950 850 
Wire Wire Line
	3850 700  4100 700 
Wire Wire Line
	4100 700  4100 850 
$Comp
L power:GND #PWR08
U 1 1 5C49E01C
P 3550 1300
F 0 "#PWR08" H 3550 1050 50  0001 C CNN
F 1 "GND" H 3555 1127 50  0000 C CNN
F 2 "" H 3550 1300 50  0001 C CNN
F 3 "" H 3550 1300 50  0001 C CNN
	1    3550 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 1150 3550 1150
Wire Wire Line
	3550 1150 3550 1300
Wire Wire Line
	4100 1150 3550 1150
Connection ~ 3550 1150
$Comp
L power:+7.5V #PWR06
U 1 1 5C49E027
P 2700 700
F 0 "#PWR06" H 2700 550 50  0001 C CNN
F 1 "+7.5V" H 2715 873 50  0001 C CNN
F 2 "" H 2700 700 50  0001 C CNN
F 3 "" H 2700 700 50  0001 C CNN
F 4 "+7.4V" H 2715 873 50  0000 C CNN "Real Value"
	1    2700 700 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 700  2700 700 
Connection ~ 2950 700 
$Comp
L power:+5V #PWR010
U 1 1 5C49E02F
P 4350 700
F 0 "#PWR010" H 4350 550 50  0001 C CNN
F 1 "+5V" H 4365 873 50  0000 C CNN
F 2 "" H 4350 700 50  0001 C CNN
F 3 "" H 4350 700 50  0001 C CNN
	1    4350 700 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 700  4350 700 
Connection ~ 4100 700 
Wire Wire Line
	3550 1000 3550 1150
Wire Wire Line
	3000 1950 3000 1900
Wire Wire Line
	4100 1950 4100 1900
$Comp
L power:GND #PWR016
U 1 1 5C4EC7ED
P 3550 3800
F 0 "#PWR016" H 3550 3550 50  0001 C CNN
F 1 "GND" H 3555 3627 50  0000 C CNN
F 2 "" H 3550 3800 50  0001 C CNN
F 3 "" H 3550 3800 50  0001 C CNN
	1    3550 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3650 3550 3800
$Comp
L power:+7.5V #PWR015
U 1 1 5C4F2CBE
P 3550 3050
F 0 "#PWR015" H 3550 2900 50  0001 C CNN
F 1 "+7.5V" H 3565 3223 50  0001 C CNN
F 2 "" H 3550 3050 50  0001 C CNN
F 3 "" H 3550 3050 50  0001 C CNN
F 4 "+7.4V" H 3565 3223 50  0000 C CNN "Real Value"
	1    3550 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3050 3550 3250
$Comp
L power:GND #PWR09
U 1 1 5C3CAEEF
P 4950 3000
F 0 "#PWR09" H 4950 2750 50  0001 C CNN
F 1 "GND" H 4955 2827 50  0000 C CNN
F 2 "" H 4950 3000 50  0001 C CNN
F 3 "" H 4950 3000 50  0001 C CNN
	1    4950 3000
	1    0    0    -1  
$EndComp
$Comp
L RAPTOR-rescue:U3V12F12 U5
U 1 1 5C3DF905
P 3550 1950
F 0 "U5" H 3550 2192 50  0000 C CNN
F 1 "U3V12F12" H 3550 2101 50  0000 C CNN
F 2 "" H 3550 2200 50  0001 C CNN
F 3 "" H 3550 2200 50  0001 C CNN
	1    3550 1950
	1    0    0    -1  
$EndComp
$Comp
L SparkFun-DiscreteSemi:DIODE-1N4148 D9
U 1 1 5C415339
P 5850 2800
F 0 "D9" V 5945 2722 45  0000 R CNN
F 1 "DIODE-1N4148" V 5861 2722 45  0000 R CNN
F 2 "DIODE-1N4148" H 5850 3000 20  0001 C CNN
F 3 "" H 5850 2800 50  0001 C CNN
F 4 "DIO-08378" V 5766 2722 60  0000 R CNN "Field4"
	1    5850 2800
	0    -1   -1   0   
$EndComp
$Comp
L SparkFun-Connectors:CONN_02 J2
U 1 1 5C4D5A1A
P 5050 2750
F 0 "J2" H 4822 2705 45  0000 R CNN
F 1 "SOLP_CONN" H 4822 2789 45  0000 R CNN
F 2 "1X02" H 5050 3000 20  0001 C CNN
F 3 "" H 5050 2750 50  0001 C CNN
F 4 "XXX-00000" H 4822 2884 60  0000 R CNN "Field4"
	1    5050 2750
	-1   0    0    1   
$EndComp
Wire Wire Line
	4950 2600 4950 2750
Wire Wire Line
	4950 3000 4950 2850
Wire Wire Line
	4950 2600 5850 2600
Wire Wire Line
	5850 2600 5850 2700
Connection ~ 4950 2600
Wire Wire Line
	5850 2900 5850 3000
Wire Wire Line
	5850 3000 4950 3000
Connection ~ 4950 3000
$Comp
L power:+12V #PWR05
U 1 1 5C55623C
P 4950 3550
F 0 "#PWR05" H 4950 3400 50  0001 C CNN
F 1 "+12V" H 4965 3723 50  0000 C CNN
F 2 "" H 4950 3550 50  0001 C CNN
F 3 "" H 4950 3550 50  0001 C CNN
	1    4950 3550
	1    0    0    -1  
$EndComp
$Comp
L RAPTOR-rescue:MOSFET-NCH-2N7002PW-SparkFun-DiscreteSemi Q2
U 1 1 5C556243
P 4850 3850
F 0 "Q2" H 5015 3945 45  0000 L CNN
F 1 "MOSFET-NCH-2N7002PW" H 5015 3861 45  0000 L CNN
F 2 "SOT323" H 4850 4150 20  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds11303.pdf" H 4850 3850 50  0001 C CNN
F 4 "TRANS-11151" H 5015 3766 60  0000 L CNN "Field4"
	1    4850 3850
	1    0    0    -1  
$EndComp
Text Label 4350 3950 0    50   ~ 0
8
Wire Wire Line
	4650 3950 4350 3950
Wire Wire Line
	4950 3550 4950 3650
$Comp
L power:GND #PWR07
U 1 1 5C556254
P 4950 4450
F 0 "#PWR07" H 4950 4200 50  0001 C CNN
F 1 "GND" H 4955 4277 50  0000 C CNN
F 2 "" H 4950 4450 50  0001 C CNN
F 3 "" H 4950 4450 50  0001 C CNN
	1    4950 4450
	1    0    0    -1  
$EndComp
$Comp
L SparkFun-DiscreteSemi:DIODE-1N4148 D8
U 1 1 5C55625B
P 5850 4250
F 0 "D8" V 5945 4172 45  0000 R CNN
F 1 "DIODE-1N4148" V 5861 4172 45  0000 R CNN
F 2 "DIODE-1N4148" H 5850 4450 20  0001 C CNN
F 3 "" H 5850 4250 50  0001 C CNN
F 4 "DIO-08378" V 5766 4172 60  0000 R CNN "Field4"
	1    5850 4250
	0    -1   -1   0   
$EndComp
$Comp
L SparkFun-Connectors:CONN_02 J1
U 1 1 5C556263
P 5050 4200
F 0 "J1" H 4822 4155 45  0000 R CNN
F 1 "SOLC_CONN" H 4822 4239 45  0000 R CNN
F 2 "1X02" H 5050 4450 20  0001 C CNN
F 3 "" H 5050 4200 50  0001 C CNN
F 4 "XXX-00000" H 4822 4334 60  0000 R CNN "Field4"
	1    5050 4200
	-1   0    0    1   
$EndComp
Wire Wire Line
	4950 4050 4950 4200
Wire Wire Line
	4950 4450 4950 4300
Wire Wire Line
	4950 4050 5850 4050
Wire Wire Line
	5850 4050 5850 4150
Connection ~ 4950 4050
Wire Wire Line
	5850 4350 5850 4450
Wire Wire Line
	5850 4450 4950 4450
Connection ~ 4950 4450
$EndSCHEMATC
