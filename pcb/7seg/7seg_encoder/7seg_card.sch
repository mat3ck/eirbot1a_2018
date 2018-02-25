EESchema Schematic File Version 2
LIBS:7_segments_encodeur-rescue
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:7_segments_encodeur-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Conn_01x04_Female J7
U 1 1 5A2B2081
P 8250 4300
F 0 "J7" H 8250 4500 50  0000 C CNN
F 1 "Conn_01x04_Female" H 8250 4000 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x04_Pitch2.54mm" H 8250 4300 50  0001 C CNN
F 3 "" H 8250 4300 50  0001 C CNN
	1    8250 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 4500 8050 4500
Wire Wire Line
	8000 4100 8000 4700
Connection ~ 8000 4400
Connection ~ 8000 4300
Connection ~ 8000 4200
$Comp
L GND #PWR013
U 1 1 5A2B3A50
P 8000 4700
F 0 "#PWR013" H 8000 4450 50  0001 C CNN
F 1 "GND" H 8000 4550 50  0000 C CNN
F 2 "" H 8000 4700 50  0001 C CNN
F 3 "" H 8000 4700 50  0001 C CNN
	1    8000 4700
	1    0    0    -1  
$EndComp
Connection ~ 8000 4500
$Comp
L 7SEGMENT_CC U3
U 1 1 5A2C4056
P 3650 3650
F 0 "U3" H 3150 4025 50  0000 R CNN
F 1 "7SEGMENT_CC" H 3150 3950 50  0000 R CNN
F 2 "Displays_7-Segment:SBC18-11SURKCGKWA" H 3700 3350 50  0001 L CNN
F 3 "" H 3650 3670 50  0001 L CNN
	1    3650 3650
	1    0    0    1   
$EndComp
$Comp
L 7SEGMENT_CC U4
U 1 1 5A2C41F7
P 5200 3650
F 0 "U4" H 4700 4025 50  0000 R CNN
F 1 "7SEGMENT_CC" H 4700 3950 50  0000 R CNN
F 2 "Displays_7-Segment:SBC18-11SURKCGKWA" H 5250 3350 50  0001 L CNN
F 3 "" H 5200 3670 50  0001 L CNN
	1    5200 3650
	1    0    0    1   
$EndComp
$Comp
L 7SEGMENT_CC U5
U 1 1 5A2C4253
P 7300 3650
F 0 "U5" H 6800 4025 50  0000 R CNN
F 1 "7SEGMENT_CC" H 6800 3950 50  0000 R CNN
F 2 "Displays_7-Segment:SBC18-11SURKCGKWA" H 7350 3350 50  0001 L CNN
F 3 "" H 7300 3670 50  0001 L CNN
	1    7300 3650
	1    0    0    1   
$EndComp
Wire Wire Line
	8050 4300 8000 4300
Wire Wire Line
	8050 4400 8000 4400
$Comp
L 2N7000 Q5
U 1 1 5A317178
P 4050 4950
F 0 "Q5" H 4250 5025 50  0000 L CNN
F 1 "2N7000" H 4250 4950 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Wide" H 4250 4875 50  0001 L CIN
F 3 "" H 4050 4950 50  0001 L CNN
	1    4050 4950
	-1   0    0    1   
$EndComp
$Comp
L 2N7000 Q6
U 1 1 5A31755F
P 4550 4950
F 0 "Q6" H 4750 5025 50  0000 L CNN
F 1 "2N7000" H 4750 4950 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Wide" H 4750 4875 50  0001 L CIN
F 3 "" H 4550 4950 50  0001 L CNN
	1    4550 4950
	-1   0    0    1   
$EndComp
$Comp
L 2N7000 Q7
U 1 1 5A3175D6
P 5050 4950
F 0 "Q7" H 5250 5025 50  0000 L CNN
F 1 "2N7000" H 5250 4950 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Wide" H 5250 4875 50  0001 L CIN
F 3 "" H 5050 4950 50  0001 L CNN
	1    5050 4950
	-1   0    0    1   
$EndComp
$Comp
L 2N7000 Q8
U 1 1 5A31760E
P 5550 4950
F 0 "Q8" H 5750 5025 50  0000 L CNN
F 1 "2N7000" H 5750 4950 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Wide" H 5750 4875 50  0001 L CIN
F 3 "" H 5550 4950 50  0001 L CNN
	1    5550 4950
	-1   0    0    1   
$EndComp
$Comp
L 2N7000 Q9
U 1 1 5A317645
P 6050 4950
F 0 "Q9" H 6250 5025 50  0000 L CNN
F 1 "2N7000" H 6250 4950 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Wide" H 6250 4875 50  0001 L CIN
F 3 "" H 6050 4950 50  0001 L CNN
	1    6050 4950
	-1   0    0    1   
$EndComp
$Comp
L 2N7000 Q10
U 1 1 5A317683
P 6550 4950
F 0 "Q10" H 6750 5025 50  0000 L CNN
F 1 "2N7000" H 6750 4950 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Wide" H 6750 4875 50  0001 L CIN
F 3 "" H 6550 4950 50  0001 L CNN
	1    6550 4950
	-1   0    0    1   
$EndComp
$Comp
L 2N7000 Q4
U 1 1 5A3176CA
P 3550 4950
F 0 "Q4" H 3750 5025 50  0000 L CNN
F 1 "2N7000" H 3750 4950 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Wide" H 3750 4875 50  0001 L CIN
F 3 "" H 3550 4950 50  0001 L CNN
	1    3550 4950
	-1   0    0    1   
$EndComp
Wire Wire Line
	3250 4050 3250 4700
Wire Wire Line
	3250 4700 3900 4700
Wire Wire Line
	3450 4700 3450 4750
Wire Wire Line
	3950 4650 3950 4750
Wire Wire Line
	4900 4650 3350 4650
Wire Wire Line
	3350 4650 3350 4050
Wire Wire Line
	3450 4050 3450 4600
Wire Wire Line
	3450 4600 5000 4600
Wire Wire Line
	4450 4600 4450 4750
Wire Wire Line
	3550 4050 3550 4550
Wire Wire Line
	3550 4550 5100 4550
Wire Wire Line
	4950 4550 4950 4750
Wire Wire Line
	3650 4050 3650 4500
Wire Wire Line
	3650 4500 5450 4500
Wire Wire Line
	5450 4500 5450 4750
Wire Wire Line
	3750 4050 3750 4450
Wire Wire Line
	3750 4450 7400 4450
Wire Wire Line
	5950 4450 5950 4750
Wire Wire Line
	3850 4050 3850 4400
Wire Wire Line
	3850 4400 7500 4400
Wire Wire Line
	6450 4400 6450 4750
Wire Wire Line
	4800 4050 4800 4350
Wire Wire Line
	4800 4350 3900 4350
Wire Wire Line
	3900 4350 3900 4700
Connection ~ 3450 4700
Wire Wire Line
	4900 4050 4900 4650
Connection ~ 3950 4650
Wire Wire Line
	5000 4600 5000 4050
Connection ~ 4450 4600
Wire Wire Line
	5100 4550 5100 4050
Connection ~ 4950 4550
Wire Wire Line
	5200 4050 5200 4500
Connection ~ 5200 4500
Wire Wire Line
	5300 4050 5300 4450
Connection ~ 5300 4450
Wire Wire Line
	5400 4050 5400 4400
Connection ~ 5400 4400
Wire Wire Line
	6900 4050 6900 4150
Wire Wire Line
	6900 4150 4800 4150
Connection ~ 4800 4150
Wire Wire Line
	4900 4200 7000 4200
Wire Wire Line
	7000 4200 7000 4050
Connection ~ 4900 4200
Wire Wire Line
	5000 4250 7100 4250
Wire Wire Line
	7100 4250 7100 4050
Connection ~ 5000 4250
Wire Wire Line
	5100 4300 7200 4300
Wire Wire Line
	7200 4300 7200 4050
Connection ~ 5100 4300
Wire Wire Line
	5200 4350 7300 4350
Wire Wire Line
	7300 4350 7300 4050
Connection ~ 5200 4350
Wire Wire Line
	7400 4450 7400 4050
Connection ~ 5950 4450
Wire Wire Line
	7500 4400 7500 4050
Connection ~ 6450 4400
Wire Wire Line
	4050 4050 4050 4100
Wire Wire Line
	4050 4100 8000 4100
Wire Wire Line
	7700 4100 7700 4050
Wire Wire Line
	5600 4050 5600 4100
Connection ~ 5600 4100
Connection ~ 7700 4100
Wire Wire Line
	8050 4200 8000 4200
$Comp
L Conn_01x11_Female J6
U 1 1 5A31802A
P 5200 6500
F 0 "J6" H 5200 7100 50  0000 C CNN
F 1 "Conn_01x11_Female" H 5200 5900 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x11_Pitch2.54mm" H 5200 6500 50  0001 C CNN
F 3 "" H 5200 6500 50  0001 C CNN
	1    5200 6500
	0    1    1    0   
$EndComp
Wire Wire Line
	3650 3250 3650 3200
Wire Wire Line
	3650 3200 3750 3200
Wire Wire Line
	3750 3100 3750 3250
Wire Wire Line
	5300 3150 5300 3250
Wire Wire Line
	5300 3200 5200 3200
Wire Wire Line
	5200 3200 5200 3250
Wire Wire Line
	7300 3250 7300 3200
Wire Wire Line
	7300 3200 8700 3200
Wire Wire Line
	7400 3200 7400 3250
Wire Wire Line
	6750 4950 6800 4950
Wire Wire Line
	4900 5600 4900 6300
Wire Wire Line
	6800 4950 6800 5600
Wire Wire Line
	6800 5600 4900 5600
Wire Wire Line
	4800 6300 4800 5550
Wire Wire Line
	4800 5550 6300 5550
Wire Wire Line
	6300 5550 6300 4950
Wire Wire Line
	6300 4950 6250 4950
Wire Wire Line
	5000 6050 5000 6300
Wire Wire Line
	3750 4950 3800 4950
Wire Wire Line
	3800 4950 3800 6050
Wire Wire Line
	3800 6050 5000 6050
Wire Wire Line
	4250 4950 4300 4950
Wire Wire Line
	4300 4950 4300 6000
Wire Wire Line
	4300 6000 5100 6000
Wire Wire Line
	5100 6000 5100 6300
Wire Wire Line
	4750 4950 4850 4950
Wire Wire Line
	4850 4950 4850 5950
Wire Wire Line
	4850 5950 5200 5950
Wire Wire Line
	5200 5950 5200 6300
Wire Wire Line
	5250 4950 5300 4950
Wire Wire Line
	5300 4950 5300 6300
Wire Wire Line
	5400 6300 5400 5950
Wire Wire Line
	5400 5950 5800 5950
Wire Wire Line
	5800 5950 5800 4950
Wire Wire Line
	5800 4950 5750 4950
Wire Wire Line
	3750 3100 8800 3100
Wire Wire Line
	8800 3100 8800 6000
Wire Wire Line
	8800 6000 5500 6000
Wire Wire Line
	5500 6000 5500 6300
Connection ~ 3750 3200
Wire Wire Line
	5300 3150 8750 3150
Wire Wire Line
	8750 3150 8750 6050
Wire Wire Line
	8750 6050 5600 6050
Wire Wire Line
	5600 6050 5600 6300
Connection ~ 5300 3200
Wire Wire Line
	5700 6300 5700 6100
Wire Wire Line
	5700 6100 8700 6100
Wire Wire Line
	8700 6100 8700 3200
Connection ~ 7400 3200
Wire Wire Line
	4700 6300 4700 6250
Wire Wire Line
	4700 6250 3450 6250
Wire Wire Line
	3450 6250 3450 5150
Wire Wire Line
	3450 5200 6450 5200
Wire Wire Line
	6450 5200 6450 5150
Connection ~ 3450 5200
Wire Wire Line
	5950 5150 5950 5200
Connection ~ 5950 5200
Wire Wire Line
	5450 5150 5450 5200
Connection ~ 5450 5200
Wire Wire Line
	4950 5150 4950 5200
Connection ~ 4950 5200
Wire Wire Line
	4450 5150 4450 5200
Connection ~ 4450 5200
Wire Wire Line
	3950 5150 3950 5200
Connection ~ 3950 5200
$EndSCHEMATC
