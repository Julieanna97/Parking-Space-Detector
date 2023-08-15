#include "main.h"
#ifndef __PARKINGSPACEDETECTOR_H
#define __PARKINGSPACEDETECTOR_H


void controlParkingSpaceLEDs(bool available); /* function for parking space LEDs */
void initializeParkingSpaces(int parkingSpaces[], int numSpaces);
int parkVehicle(int parkingSpaces[], int numSpaces);


#endif