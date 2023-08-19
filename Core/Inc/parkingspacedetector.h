#include "main.h"

#ifndef __PARKINGSPACEDETECTOR_H
#define __PARKINGSPACEDETECTOR_H


void controlParkingSpaceLEDs(bool available); /* function for parking space LEDs */
void initParkingSpaces(int parkingSpaces[], int numSpaces);
int parkVehicle(int parkingSpaces[], int numSpaces);
void removeVehicle(int parkingSpaces[], int spaceIndex);
void displayParkingStatus(int parkingSpaces[], int numSpaces);
void initUltrasonicSensor(void);
float measureDistance(void);


#endif