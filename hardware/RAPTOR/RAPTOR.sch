EESchema Schematic File Version 4
LIBS:RAPTOR-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "RAPTOR Schematic"
Date "2018-11-03"
Rev "FALCON"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
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
P 2300 1700
F 0 "U1" H 2300 2154 45  0000 C CNN
F 1 "BMP280" H 2300 2070 45  0000 C CNN
F 2 "RAPTOR_footprints:BMP280" H 2300 2150 20  0001 C CNN
F 3 "" H 2300 1700 60  0001 C CNN
	1    2300 1700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0101
U 1 1 5BD35138
P 1550 1400
F 0 "#PWR0101" H 1550 1250 50  0001 C CNN
F 1 "+5V" H 1565 1573 50  0000 C CNN
F 2 "" H 1550 1400 50  0001 C CNN
F 3 "" H 1550 1400 50  0001 C CNN
	1    1550 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 1400 1550 1500
Wire Wire Line
	1550 1500 1750 1500
$Comp
L power:GND #PWR0102
U 1 1 5BD35A48
P 1550 2100
F 0 "#PWR0102" H 1550 1850 50  0001 C CNN
F 1 "GND" H 1555 1927 50  0000 C CNN
F 2 "" H 1550 2100 50  0001 C CNN
F 3 "" H 1550 2100 50  0001 C CNN
	1    1550 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2000 1550 2000
Wire Wire Line
	1550 2000 1550 2100
Text Label 3200 1800 0    50   ~ 0
A5(SCL)
Text Label 3200 1700 0    50   ~ 0
A4(SDA)
Wire Wire Line
	2850 1700 3200 1700
Wire Wire Line
	2850 1800 3200 1800
$Comp
L RAPTOR-rescue:BNO055-bno055 U2
U 1 1 5BD45163
P 2300 3200
F 0 "U2" H 2300 3654 45  0000 C CNN
F 1 "BNO055" H 2300 3570 45  0000 C CNN
F 2 "RAPTOR_footprints:BNO055" H 2300 3650 20  0001 C CNN
F 3 "" H 2300 3200 60  0001 C CNN
	1    2300 3200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5BD4727B
P 1550 2900
F 0 "#PWR0103" H 1550 2750 50  0001 C CNN
F 1 "+5V" H 1565 3073 50  0000 C CNN
F 2 "" H 1550 2900 50  0001 C CNN
F 3 "" H 1550 2900 50  0001 C CNN
	1    1550 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 2900 1550 3000
Wire Wire Line
	1550 3000 1750 3000
$Comp
L power:GND #PWR0104
U 1 1 5BD47283
P 1550 3600
F 0 "#PWR0104" H 1550 3350 50  0001 C CNN
F 1 "GND" H 1555 3427 50  0000 C CNN
F 2 "" H 1550 3600 50  0001 C CNN
F 3 "" H 1550 3600 50  0001 C CNN
	1    1550 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 3500 1550 3500
Wire Wire Line
	1550 3500 1550 3600
Text Label 3200 3200 0    50   ~ 0
A5(SCL)
Text Label 3200 3050 0    50   ~ 0
A4(SDA)
Wire Wire Line
	2850 3200 3200 3200
Wire Wire Line
	2850 3050 3200 3050
$Comp
L RAPTOR-rescue:OpenLog-openlog U3
U 1 1 5BDE8282
P 2300 4500
F 0 "U3" H 2300 4954 45  0000 C CNN
F 1 "OpenLog" H 2300 4870 45  0000 C CNN
F 2 "RAPTOR_footprints:OpenLog" H 2300 4950 20  0001 C CNN
F 3 "" H 2300 4500 60  0001 C CNN
	1    2300 4500
	1    0    0    -1  
$EndComp
$Comp
L RAPTOR-rescue:AdafruitGPS-adafruitgps U4
U 1 1 5BDE25E6
P 2450 5950
F 0 "U4" H 2450 6475 50  0000 C CNN
F 1 "AdafruitGPS" H 2450 6384 50  0000 C CNN
F 2 "RAPTOR_footprints:AdafruitGPS" H 2550 5900 50  0001 C CNN
F 3 "" H 2550 5900 50  0001 C CNN
	1    2450 5950
	1    0    0    -1  
$EndComp
Text Label 3200 4750 0    50   ~ 0
0(Rx)
Wire Wire Line
	2850 4750 3200 4750
Text Label 3200 4350 0    50   ~ 0
1(Tx)
Wire Wire Line
	2850 4350 3200 4350
$Comp
L power:GND #PWR0105
U 1 1 5BDE53C7
P 1550 4900
F 0 "#PWR0105" H 1550 4650 50  0001 C CNN
F 1 "GND" H 1555 4727 50  0000 C CNN
F 2 "" H 1550 4900 50  0001 C CNN
F 3 "" H 1550 4900 50  0001 C CNN
	1    1550 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 4800 1550 4800
Wire Wire Line
	1550 4800 1550 4900
$Comp
L power:GND #PWR0106
U 1 1 5BDE7CE6
P 1550 6400
F 0 "#PWR0106" H 1550 6150 50  0001 C CNN
F 1 "GND" H 1555 6227 50  0000 C CNN
F 2 "" H 1550 6400 50  0001 C CNN
F 3 "" H 1550 6400 50  0001 C CNN
	1    1550 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 6300 1550 6300
Wire Wire Line
	1550 6300 1550 6400
$Comp
L power:+5V #PWR0107
U 1 1 5BDE90FA
P 1550 5600
F 0 "#PWR0107" H 1550 5450 50  0001 C CNN
F 1 "+5V" H 1565 5773 50  0000 C CNN
F 2 "" H 1550 5600 50  0001 C CNN
F 3 "" H 1550 5600 50  0001 C CNN
	1    1550 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 5600 1550 5700
Wire Wire Line
	1550 5700 1750 5700
$Comp
L power:+5V #PWR0108
U 1 1 5BDEA4F5
P 1550 4250
F 0 "#PWR0108" H 1550 4100 50  0001 C CNN
F 1 "+5V" H 1565 4423 50  0000 C CNN
F 2 "" H 1550 4250 50  0001 C CNN
F 3 "" H 1550 4250 50  0001 C CNN
	1    1550 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 4250 1550 4350
Wire Wire Line
	1550 4350 1750 4350
Text Label 3500 5800 0    50   ~ 0
3(**)
Wire Wire Line
	3150 5800 3500 5800
Text Label 3500 5950 0    50   ~ 0
2
Wire Wire Line
	3150 5950 3500 5950
Text Label 3500 6250 0    50   ~ 0
FIX_LED
Wire Wire Line
	3150 6250 3500 6250
NoConn ~ 1750 5800
NoConn ~ 1750 5950
NoConn ~ 3150 6100
NoConn ~ 3150 5650
NoConn ~ 1750 4600
NoConn ~ 1750 4700
NoConn ~ 1750 3200
NoConn ~ 1750 1700
NoConn ~ 2850 1500
NoConn ~ 2850 2000
$EndSCHEMATC
