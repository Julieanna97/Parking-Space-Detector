#include "main.h"

// Function to switch LEDs (Green/Red) according to vacancy status
void controlParkingSpaceLEDs(bool available)
{
  while (1)
  {
    if (available)
    {
      // Turn on LD2 ON pin (Green LED) and turn off LD2 OFF pin (Red LED)
      HAL_GPIO_WritePin(LD2_ON_GPIO_Port, LD2_ON_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LD2_OFF_GPIO_Port, LD2_OFF_Pin, GPIO_PIN_RESET);
    }
    else
    {
      HAL_GPIO_WritePin(LD2_ON_GPIO_Port, LD2_ON_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LD2_OFF_GPIO_Port, LD2_OFF_Pin, GPIO_PIN_SET);
    
    }

  }

}

// Function to initialize parking spaces as empty
void initializeParkingSpaces(int parkingSpaces[], int numSpaces)
{
    for (int i = 0; i < numSpaces; i++)
    {
        parkingSpaces[i] = 0;  // 0 represents an empty space
    }

}

// Function to park a vehicle in the first available space
int parkVehicle(int parkingSpaces[], int numSpaces)
{
    for (int i = 0; i < numSpaces; i++)
    {
        if (parkingSpaces[i] == 0)  // Check if the space is empty
        {
            parkingSpaces[i] = 1;   // Park the vehicle
            return i;               // Return the parking space index
        }
    }

    return -1;  // No available parking space

}