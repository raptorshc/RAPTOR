EESchema Schematic File Version 4
LIBS:RAPTOR-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "RAPTOR Schematic"
Date "2019-01-12"
Rev "PHOENIX 0.5.5"
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
F 1 "BMP280 Breakout" H 2300 2070 45  0000 C CNN
F 2 "RAPTOR_footprints:BMP280" H 2300 2150 20  0001 C CNN
F 3 "https://learn.adafruit.com/adafruit-bmp280-barometric-pressure-plus-temperature-sensor-breakout/overview" H 2300 1700 60  0001 C CNN
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
F 1 "BNO055 Breakout" H 2300 3570 45  0000 C CNN
F 2 "RAPTOR_footprints:BNO055" H 2300 3650 20  0001 C CNN
F 3 "https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor/overview" H 2300 3200 60  0001 C CNN
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
F 3 "https://learn.sparkfun.com/tutorials/openlog-hookup-guide/all" H 2300 4500 60  0001 C CNN
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
F 3 "https://learn.adafruit.com/adafruit-ultimate-gps" H 2550 5900 50  0001 C CNN
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
$Comp
L Motor:Motor_Servo M1
U 1 1 5BE79CAA
P 6550 1100
F 0 "M1" H 6546 793 50  0000 C CNN
F 1 "Motor_Servo" H 6546 884 50  0000 C CNN
F 2 "" H 6550 910 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 6550 910 50  0001 C CNN
	1    6550 1100
	-1   0    0    1   
$EndComp
Text Label 7250 1200 0    50   ~ 0
6(**)
Wire Wire Line
	6850 1200 7250 1200
$Comp
L power:+6V #PWR0109
U 1 1 5BE7EDED
P 7150 950
F 0 "#PWR0109" H 7150 800 50  0001 C CNN
F 1 "+6V" H 7165 1123 50  0000 C CNN
F 2 "" H 7150 950 50  0001 C CNN
F 3 "" H 7150 950 50  0001 C CNN
	1    7150 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5BE823AD
P 7000 800
F 0 "#PWR0110" H 7000 550 50  0001 C CNN
F 1 "GND" H 7005 627 50  0000 C CNN
F 2 "" H 7000 800 50  0001 C CNN
F 3 "" H 7000 800 50  0001 C CNN
	1    7000 800 
	-1   0    0    1   
$EndComp
Wire Wire Line
	6850 1000 7000 1000
Wire Wire Line
	7000 1000 7000 800 
Wire Wire Line
	6850 1100 7150 1100
Wire Wire Line
	7150 1100 7150 950 
$Comp
L Motor:Motor_Servo M2
U 1 1 5BE85BA8
P 6550 2150
F 0 "M2" H 6546 1843 50  0000 C CNN
F 1 "Motor_Servo" H 6546 1934 50  0000 C CNN
F 2 "" H 6550 1960 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 6550 1960 50  0001 C CNN
	1    6550 2150
	-1   0    0    1   
$EndComp
Text Label 7250 2250 0    50   ~ 0
5(**)
Wire Wire Line
	6850 2250 7250 2250
$Comp
L power:GND #PWR0112
U 1 1 5BE85BB7
P 7000 1850
F 0 "#PWR0112" H 7000 1600 50  0001 C CNN
F 1 "GND" H 7005 1677 50  0000 C CNN
F 2 "" H 7000 1850 50  0001 C CNN
F 3 "" H 7000 1850 50  0001 C CNN
	1    7000 1850
	-1   0    0    1   
$EndComp
Wire Wire Line
	6850 2050 7000 2050
Wire Wire Line
	7000 2050 7000 1850
Wire Wire Line
	6850 2150 7150 2150
Wire Wire Line
	7150 2150 7150 2000
$Comp
L power:-12V #SOLP0101
U 1 1 5BE89FE1
P 4650 3600
F 0 "#SOLP0101" H 4592 3591 50  0000 R CNN
F 1 "-12V" H 4592 3682 50  0000 R CNN
F 2 "" H 4650 3600 50  0001 C CNN
F 3 "" H 4650 3600 50  0001 C CNN
F 4 "Solenoid" H 4650 3600 50  0001 C CNN "Name"
	1    4650 3600
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR0113
U 1 1 5BE8A086
P 4650 3000
F 0 "#PWR0113" H 4650 2850 50  0001 C CNN
F 1 "+12V" H 4665 3173 50  0000 C CNN
F 2 "" H 4650 3000 50  0001 C CNN
F 3 "" H 4650 3000 50  0001 C CNN
	1    4650 3000
	1    0    0    -1  
$EndComp
$Comp
L RAPTOR-rescue:MOSFET-NCH-2N7002PW-SparkFun-DiscreteSemi Q1
U 1 1 5BE8A581
P 4550 3300
F 0 "Q1" H 4715 3395 45  0000 L CNN
F 1 "MOSFET-NCH-2N7002PW" H 4715 3311 45  0000 L CNN
F 2 "SOT323" H 4550 3600 20  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds11303.pdf" H 4550 3300 50  0001 C CNN
F 4 "TRANS-11151" H 4715 3216 60  0000 L CNN "Field4"
	1    4550 3300
	1    0    0    -1  
$EndComp
Text Label 4050 3400 0    50   ~ 0
8
Wire Wire Line
	4350 3400 4050 3400
Wire Wire Line
	4650 3500 4650 3600
Wire Wire Line
	4650 3000 4650 3100
$Comp
L power:-12V #SOLC0101
U 1 1 5BEAB449
P 4650 4600
F 0 "#SOLC0101" H 4592 4591 50  0000 R CNN
F 1 "-12V" H 4592 4682 50  0000 R CNN
F 2 "" H 4650 4600 50  0001 C CNN
F 3 "" H 4650 4600 50  0001 C CNN
F 4 "Solenoid" H 4650 4600 50  0001 C CNN "Name"
	1    4650 4600
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR0114
U 1 1 5BEAB450
P 4650 4000
F 0 "#PWR0114" H 4650 3850 50  0001 C CNN
F 1 "+12V" H 4665 4173 50  0000 C CNN
F 2 "" H 4650 4000 50  0001 C CNN
F 3 "" H 4650 4000 50  0001 C CNN
	1    4650 4000
	1    0    0    -1  
$EndComp
$Comp
L RAPTOR-rescue:MOSFET-NCH-2N7002PW-SparkFun-DiscreteSemi Q2
U 1 1 5BEAB457
P 4550 4300
F 0 "Q2" H 4715 4395 45  0000 L CNN
F 1 "MOSFET-NCH-2N7002PW" H 4715 4311 45  0000 L CNN
F 2 "SOT323" H 4550 4600 20  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds11303.pdf" H 4550 4300 50  0001 C CNN
F 4 "TRANS-11151" H 4715 4216 60  0000 L CNN "Field4"
	1    4550 4300
	1    0    0    -1  
$EndComp
Text Label 4050 4400 0    50   ~ 0
9(**)
Wire Wire Line
	4350 4400 4050 4400
Wire Wire Line
	4650 4500 4650 4600
Wire Wire Line
	4650 4000 4650 4100
$Comp
L Device:Buzzer BZ1
U 1 1 5BEADE3C
P 4750 5700
F 0 "BZ1" H 4903 5729 50  0000 L CNN
F 1 "Buzzer" H 4903 5638 50  0000 L CNN
F 2 "" V 4725 5800 50  0001 C CNN
F 3 "~" V 4725 5800 50  0001 C CNN
	1    4750 5700
	1    0    0    -1  
$EndComp
$Comp
L RAPTOR-rescue:MOSFET-NCH-2N7002PW-SparkFun-DiscreteSemi Q3
U 1 1 5BEB292C
P 4550 5250
F 0 "Q3" H 4715 5345 45  0000 L CNN
F 1 "MOSFET-NCH-2N7002PW" H 4715 5261 45  0000 L CNN
F 2 "SOT323" H 4550 5550 20  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds11303.pdf" H 4550 5250 50  0001 C CNN
F 4 "TRANS-11151" H 4715 5166 60  0000 L CNN "Field4"
	1    4550 5250
	1    0    0    -1  
$EndComp
Text Label 3950 5350 0    50   ~ 0
11
Wire Wire Line
	4350 5350 3950 5350
$Comp
L power:+6V #PWR0115
U 1 1 5BEB715A
P 4650 4950
F 0 "#PWR0115" H 4650 4800 50  0001 C CNN
F 1 "+6V" H 4665 5123 50  0000 C CNN
F 2 "" H 4650 4950 50  0001 C CNN
F 3 "" H 4650 4950 50  0001 C CNN
	1    4650 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 5450 4650 5600
$Comp
L power:GND #PWR0116
U 1 1 5BEBE024
P 4650 5950
F 0 "#PWR0116" H 4650 5700 50  0001 C CNN
F 1 "GND" H 4655 5777 50  0000 C CNN
F 2 "" H 4650 5950 50  0001 C CNN
F 3 "" H 4650 5950 50  0001 C CNN
	1    4650 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 5800 4650 5950
Wire Wire Line
	4650 5050 4650 4950
$Comp
L Device:LED D1
U 1 1 5BEC62B7
P 4350 6500
F 0 "D1" H 4341 6716 50  0000 C CNN
F 1 "LED" H 4341 6625 50  0000 C CNN
F 2 "" H 4350 6500 50  0001 C CNN
F 3 "~" H 4350 6500 50  0001 C CNN
	1    4350 6500
	1    0    0    -1  
$EndComp
Text Label 4600 6500 0    50   ~ 0
FIX_LED
$Comp
L power:GND #PWR0117
U 1 1 5BEC8E4F
P 4050 6600
F 0 "#PWR0117" H 4050 6350 50  0001 C CNN
F 1 "GND" H 4055 6427 50  0000 C CNN
F 2 "" H 4050 6600 50  0001 C CNN
F 3 "" H 4050 6600 50  0001 C CNN
	1    4050 6600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 6500 4050 6500
Wire Wire Line
	4050 6500 4050 6600
Wire Wire Line
	4500 6500 4600 6500
$Comp
L Device:LED D2
U 1 1 5BECDE5B
P 5750 6150
F 0 "D2" H 5741 6366 50  0000 C CNN
F 1 "SOLP_LED" H 5741 6275 50  0000 C CNN
F 2 "" H 5750 6150 50  0001 C CNN
F 3 "~" H 5750 6150 50  0001 C CNN
	1    5750 6150
	1    0    0    -1  
$EndComp
Text Label 6000 6150 0    50   ~ 0
A2
$Comp
L power:GND #PWR0118
U 1 1 5BECDE63
P 5450 6250
F 0 "#PWR0118" H 5450 6000 50  0001 C CNN
F 1 "GND" H 5455 6077 50  0000 C CNN
F 2 "" H 5450 6250 50  0001 C CNN
F 3 "" H 5450 6250 50  0001 C CNN
	1    5450 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 6150 5450 6150
Wire Wire Line
	5450 6150 5450 6250
Wire Wire Line
	5900 6150 6000 6150
$Comp
L Device:LED D3
U 1 1 5BED08A1
P 5750 6550
F 0 "D3" H 5741 6766 50  0000 C CNN
F 1 "SOLC_LED" H 5741 6675 50  0000 C CNN
F 2 "" H 5750 6550 50  0001 C CNN
F 3 "~" H 5750 6550 50  0001 C CNN
	1    5750 6550
	1    0    0    -1  
$EndComp
Text Label 6000 6550 0    50   ~ 0
A3
$Comp
L power:GND #PWR0119
U 1 1 5BED08A9
P 5450 6650
F 0 "#PWR0119" H 5450 6400 50  0001 C CNN
F 1 "GND" H 5455 6477 50  0000 C CNN
F 2 "" H 5450 6650 50  0001 C CNN
F 3 "" H 5450 6650 50  0001 C CNN
	1    5450 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 6550 5450 6550
Wire Wire Line
	5450 6550 5450 6650
Wire Wire Line
	5900 6550 6000 6550
$Comp
L Switch:SW_SPST SW1
U 1 1 5BED49C4
P 6100 3850
F 0 "SW1" H 6100 4085 50  0000 C CNN
F 1 "EEPROM_BTN" H 6100 3994 50  0000 C CNN
F 2 "" H 6100 3850 50  0001 C CNN
F 3 "" H 6100 3850 50  0001 C CNN
	1    6100 3850
	1    0    0    -1  
$EndComp
Text Label 6500 3850 0    50   ~ 0
7
$Comp
L power:+5V #PWR0120
U 1 1 5BED5ECD
P 5750 3800
F 0 "#PWR0120" H 5750 3650 50  0001 C CNN
F 1 "+5V" H 5765 3973 50  0000 C CNN
F 2 "" H 5750 3800 50  0001 C CNN
F 3 "" H 5750 3800 50  0001 C CNN
	1    5750 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 3800 5750 3850
Wire Wire Line
	5750 3850 5900 3850
Wire Wire Line
	6300 3850 6500 3850
$Comp
L Switch:SW_SPST SW2
U 1 1 5BEDC896
P 6100 3350
F 0 "SW2" H 6100 3585 50  0000 C CNN
F 1 "SOLP_SW" H 6100 3494 50  0000 C CNN
F 2 "" H 6100 3350 50  0001 C CNN
F 3 "" H 6100 3350 50  0001 C CNN
	1    6100 3350
	1    0    0    -1  
$EndComp
Text Label 6500 3350 0    50   ~ 0
A0
$Comp
L power:+5V #PWR0121
U 1 1 5BEDC89E
P 5750 3300
F 0 "#PWR0121" H 5750 3150 50  0001 C CNN
F 1 "+5V" H 5765 3473 50  0000 C CNN
F 2 "" H 5750 3300 50  0001 C CNN
F 3 "" H 5750 3300 50  0001 C CNN
	1    5750 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 3300 5750 3350
Wire Wire Line
	5750 3350 5900 3350
Wire Wire Line
	6300 3350 6500 3350
$Comp
L Switch:SW_SPST SW3
U 1 1 5BEDFD43
P 6100 4300
F 0 "SW3" H 6100 4535 50  0000 C CNN
F 1 "SOLC_SW" H 6100 4444 50  0000 C CNN
F 2 "" H 6100 4300 50  0001 C CNN
F 3 "" H 6100 4300 50  0001 C CNN
	1    6100 4300
	1    0    0    -1  
$EndComp
Text Label 6500 4300 0    50   ~ 0
A1
$Comp
L power:+5V #PWR0122
U 1 1 5BEDFD4B
P 5750 4250
F 0 "#PWR0122" H 5750 4100 50  0001 C CNN
F 1 "+5V" H 5765 4423 50  0000 C CNN
F 2 "" H 5750 4250 50  0001 C CNN
F 3 "" H 5750 4250 50  0001 C CNN
	1    5750 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 4250 5750 4300
Wire Wire Line
	5750 4300 5900 4300
Wire Wire Line
	6300 4300 6500 4300
$Comp
L Device:LED D4
U 1 1 5BEE4EBE
P 9850 5600
F 0 "D4" H 9841 5816 50  0000 C CNN
F 1 "SOLP_LED" H 9841 5725 50  0000 C CNN
F 2 "" H 9850 5600 50  0001 C CNN
F 3 "~" H 9850 5600 50  0001 C CNN
	1    9850 5600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 5BEE4EC6
P 9550 5700
F 0 "#PWR0123" H 9550 5450 50  0001 C CNN
F 1 "GND" H 9555 5527 50  0000 C CNN
F 2 "" H 9550 5700 50  0001 C CNN
F 3 "" H 9550 5700 50  0001 C CNN
	1    9550 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 5600 9550 5600
Wire Wire Line
	9550 5600 9550 5700
$Comp
L Device:LED D5
U 1 1 5BEE4ECF
P 9850 6000
F 0 "D5" H 9841 6216 50  0000 C CNN
F 1 "SOLC_LED" H 9841 6125 50  0000 C CNN
F 2 "" H 9850 6000 50  0001 C CNN
F 3 "~" H 9850 6000 50  0001 C CNN
	1    9850 6000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0124
U 1 1 5BEE4ED7
P 9550 6100
F 0 "#PWR0124" H 9550 5850 50  0001 C CNN
F 1 "GND" H 9555 5927 50  0000 C CNN
F 2 "" H 9550 6100 50  0001 C CNN
F 3 "" H 9550 6100 50  0001 C CNN
	1    9550 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 6000 9550 6000
Wire Wire Line
	9550 6000 9550 6100
$Comp
L Device:LED D7
U 1 1 5BEE8A04
P 10600 6000
F 0 "D7" H 10591 6216 50  0000 C CNN
F 1 "SOLP_LED" H 10591 6125 50  0000 C CNN
F 2 "" H 10600 6000 50  0001 C CNN
F 3 "~" H 10600 6000 50  0001 C CNN
	1    10600 6000
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0125
U 1 1 5BEE8A0C
P 10900 6100
F 0 "#PWR0125" H 10900 5850 50  0001 C CNN
F 1 "GND" H 10905 5927 50  0000 C CNN
F 2 "" H 10900 6100 50  0001 C CNN
F 3 "" H 10900 6100 50  0001 C CNN
	1    10900 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	10750 6000 10900 6000
$Comp
L Device:LED D6
U 1 1 5BEE8A15
P 10600 5600
F 0 "D6" H 10591 5816 50  0000 C CNN
F 1 "SOLC_LED" H 10591 5725 50  0000 C CNN
F 2 "" H 10600 5600 50  0001 C CNN
F 3 "~" H 10600 5600 50  0001 C CNN
	1    10600 5600
	-1   0    0    1   
$EndComp
Wire Wire Line
	10900 6000 10900 6100
$Comp
L power:GND #PWR0126
U 1 1 5BF1D48C
P 10900 5700
F 0 "#PWR0126" H 10900 5450 50  0001 C CNN
F 1 "GND" H 10905 5527 50  0000 C CNN
F 2 "" H 10900 5700 50  0001 C CNN
F 3 "" H 10900 5700 50  0001 C CNN
	1    10900 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	10750 5600 10900 5600
Wire Wire Line
	10900 5600 10900 5700
Wire Wire Line
	10000 5600 10250 5600
Wire Wire Line
	10450 6000 10250 6000
Wire Wire Line
	10250 6000 10250 5600
Connection ~ 10250 6000
Wire Wire Line
	10250 6000 10000 6000
Connection ~ 10250 5600
Wire Wire Line
	10250 5600 10450 5600
Text Label 9750 5300 0    50   ~ 0
12
$Comp
L RAPTOR-rescue:MOSFET-NCH-2N7002PW-SparkFun-DiscreteSemi Q4
U 1 1 5BF36D0B
P 10150 5200
F 0 "Q4" H 10315 5295 45  0000 L CNN
F 1 "MOSFET-NCH-2N7002PW" H 10315 5211 45  0000 L CNN
F 2 "SOT323" H 10150 5500 20  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds11303.pdf" H 10150 5200 50  0001 C CNN
F 4 "TRANS-11151" H 10315 5116 60  0000 L CNN "Field4"
	1    10150 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 5400 10250 5600
Wire Wire Line
	10250 5000 10250 4800
Wire Wire Line
	9950 5300 9750 5300
$Comp
L power:+3.3V #PWR0127
U 1 1 5BF54F36
P 10250 4800
F 0 "#PWR0127" H 10250 4650 50  0001 C CNN
F 1 "+3.3V" H 10265 4973 50  0000 C CNN
F 2 "" H 10250 4800 50  0001 C CNN
F 3 "" H 10250 4800 50  0001 C CNN
	1    10250 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery BT1
U 1 1 5C3C688C
P 7600 3200
F 0 "BT1" H 7708 3246 50  0000 L CNN
F 1 "7.4V" H 7708 3155 50  0000 L CNN
F 2 "" V 7600 3260 50  0001 C CNN
F 3 "~" V 7600 3260 50  0001 C CNN
	1    7600 3200
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7805 U5
U 1 1 5C3F6891
P 4700 800
F 0 "U5" H 4700 1042 50  0000 C CNN
F 1 "L7805" H 4700 951 50  0000 C CNN
F 2 "" H 4725 650 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 4700 750 50  0001 C CNN
	1    4700 800 
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5C3F6898
P 5250 1100
F 0 "C3" H 5365 1146 50  0000 L CNN
F 1 "0.1uF" H 5365 1055 50  0000 L CNN
F 2 "" H 5288 950 50  0001 C CNN
F 3 "~" H 5250 1100 50  0001 C CNN
	1    5250 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5C3F689F
P 4100 1100
F 0 "C1" H 4215 1146 50  0000 L CNN
F 1 "0.33 uF" H 4215 1055 50  0000 L CNN
F 2 "" H 4138 950 50  0001 C CNN
F 3 "~" H 4100 1100 50  0001 C CNN
	1    4100 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 800  4100 800 
Wire Wire Line
	4100 800  4100 950 
Wire Wire Line
	5000 800  5250 800 
Wire Wire Line
	5250 800  5250 950 
$Comp
L power:GND #PWR07
U 1 1 5C3F68AA
P 4700 1400
F 0 "#PWR07" H 4700 1150 50  0001 C CNN
F 1 "GND" H 4705 1227 50  0000 C CNN
F 2 "" H 4700 1400 50  0001 C CNN
F 3 "" H 4700 1400 50  0001 C CNN
	1    4700 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 1250 4700 1250
Wire Wire Line
	4700 1250 4700 1400
Wire Wire Line
	5250 1250 4700 1250
Connection ~ 4700 1250
$Comp
L power:+7.5V #PWR05
U 1 1 5C3F68B5
P 3850 800
F 0 "#PWR05" H 3850 650 50  0001 C CNN
F 1 "+7.5V" H 3865 973 50  0001 C CNN
F 2 "" H 3850 800 50  0001 C CNN
F 3 "" H 3850 800 50  0001 C CNN
F 4 "+7.4V" H 3865 973 50  0000 C CNN "Real Value"
	1    3850 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 800  3850 800 
Connection ~ 4100 800 
$Comp
L power:+5V #PWR09
U 1 1 5C3F68BD
P 5500 800
F 0 "#PWR09" H 5500 650 50  0001 C CNN
F 1 "+5V" H 5515 973 50  0000 C CNN
F 2 "" H 5500 800 50  0001 C CNN
F 3 "" H 5500 800 50  0001 C CNN
	1    5500 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 800  5500 800 
Connection ~ 5250 800 
Wire Wire Line
	4700 1100 4700 1250
$Comp
L RAPTOR-rescue:U3V12F12 U7
U 1 1 5C40F0AB
P 6600 5000
F 0 "U7" H 5100 6142 50  0000 C CNN
F 1 "U3V12F12" H 5100 6051 50  0000 C CNN
F 2 "" H 5100 6150 50  0001 C CNN
F 3 "https://www.robotshop.com/media/files/PDF/datasheet-2117.pdf" H 5100 6150 50  0001 C CNN
	1    6600 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5C40FAEF
P 6600 5450
F 0 "#PWR012" H 6600 5200 50  0001 C CNN
F 1 "GND" H 6605 5277 50  0000 C CNN
F 2 "" H 6600 5450 50  0001 C CNN
F 3 "" H 6600 5450 50  0001 C CNN
	1    6600 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 5300 6600 5450
$Comp
L power:+7.5V #PWR011
U 1 1 5C42772B
P 6050 4950
F 0 "#PWR011" H 6050 4800 50  0001 C CNN
F 1 "+7.5V" H 6065 5123 50  0001 C CNN
F 2 "" H 6050 4950 50  0001 C CNN
F 3 "" H 6050 4950 50  0001 C CNN
F 4 "+7.4V" H 6065 5123 50  0000 C CNN "Real Value"
	1    6050 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 5000 6050 5000
Wire Wire Line
	6900 5000 7150 5000
$Comp
L power:+12V #PWR013
U 1 1 5C4334FC
P 7150 4950
F 0 "#PWR013" H 7150 4800 50  0001 C CNN
F 1 "+12V" H 7165 5215 50  0000 C CNN
F 2 "" H 7150 4950 50  0001 C CNN
F 3 "" H 7150 4950 50  0001 C CNN
F 4 "(TO SOLENOID)" H 7165 5124 50  0000 C CNN "Note"
	1    7150 4950
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR014
U 1 1 5C442A87
P 7150 2000
F 0 "#PWR014" H 7150 1850 50  0001 C CNN
F 1 "+5V" H 7165 2173 50  0000 C CNN
F 2 "" H 7150 2000 50  0001 C CNN
F 3 "" H 7150 2000 50  0001 C CNN
	1    7150 2000
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7805 U6
U 1 1 5C49E003
P 4700 1950
F 0 "U6" H 4700 2192 50  0000 C CNN
F 1 "L7805" H 4700 2101 50  0000 C CNN
F 2 "" H 4725 1800 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 4700 1900 50  0001 C CNN
	1    4700 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5C49E00A
P 5250 2250
F 0 "C4" H 5365 2296 50  0000 L CNN
F 1 "0.1uF" H 5365 2205 50  0000 L CNN
F 2 "" H 5288 2100 50  0001 C CNN
F 3 "~" H 5250 2250 50  0001 C CNN
	1    5250 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5C49E011
P 4100 2250
F 0 "C2" H 4215 2296 50  0000 L CNN
F 1 "0.33 uF" H 4215 2205 50  0000 L CNN
F 2 "" H 4138 2100 50  0001 C CNN
F 3 "~" H 4100 2250 50  0001 C CNN
	1    4100 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 1950 4100 1950
Wire Wire Line
	4100 1950 4100 2100
Wire Wire Line
	5000 1950 5250 1950
Wire Wire Line
	5250 1950 5250 2100
$Comp
L power:GND #PWR08
U 1 1 5C49E01C
P 4700 2550
F 0 "#PWR08" H 4700 2300 50  0001 C CNN
F 1 "GND" H 4705 2377 50  0000 C CNN
F 2 "" H 4700 2550 50  0001 C CNN
F 3 "" H 4700 2550 50  0001 C CNN
	1    4700 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 2400 4700 2400
Wire Wire Line
	4700 2400 4700 2550
Wire Wire Line
	5250 2400 4700 2400
Connection ~ 4700 2400
$Comp
L power:+7.5V #PWR06
U 1 1 5C49E027
P 3850 1950
F 0 "#PWR06" H 3850 1800 50  0001 C CNN
F 1 "+7.5V" H 3865 2123 50  0001 C CNN
F 2 "" H 3850 1950 50  0001 C CNN
F 3 "" H 3850 1950 50  0001 C CNN
F 4 "+7.4V" H 3865 2123 50  0000 C CNN "Real Value"
	1    3850 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 1950 3850 1950
Connection ~ 4100 1950
$Comp
L power:+5V #PWR010
U 1 1 5C49E02F
P 5500 1950
F 0 "#PWR010" H 5500 1800 50  0001 C CNN
F 1 "+5V" H 5515 2123 50  0000 C CNN
F 2 "" H 5500 1950 50  0001 C CNN
F 3 "" H 5500 1950 50  0001 C CNN
	1    5500 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 1950 5500 1950
Connection ~ 5250 1950
Wire Wire Line
	4700 2250 4700 2400
Wire Wire Line
	6050 5000 6050 4950
Wire Wire Line
	7150 5000 7150 4950
$Comp
L power:GND #PWR016
U 1 1 5C4EC7ED
P 7600 3550
F 0 "#PWR016" H 7600 3300 50  0001 C CNN
F 1 "GND" H 7605 3377 50  0000 C CNN
F 2 "" H 7600 3550 50  0001 C CNN
F 3 "" H 7600 3550 50  0001 C CNN
	1    7600 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 3400 7600 3550
$Comp
L power:+7.5V #PWR015
U 1 1 5C4F2CBE
P 7600 2800
F 0 "#PWR015" H 7600 2650 50  0001 C CNN
F 1 "+7.5V" H 7615 2973 50  0001 C CNN
F 2 "" H 7600 2800 50  0001 C CNN
F 3 "" H 7600 2800 50  0001 C CNN
F 4 "+7.4V" H 7615 2973 50  0000 C CNN "Real Value"
	1    7600 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 2800 7600 3000
$EndSCHEMATC
