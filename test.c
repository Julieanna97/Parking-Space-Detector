#include <stdio.h>

#define NUM_PARKING_SPACES 10

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

// Function to remove a parked vehicle from a specific space
void removeVehicle(int parkingSpaces[], int spaceIndex)
{
    if (spaceIndex >= 0 && spaceIndex < NUM_PARKING_SPACES)
    {
        parkingSpaces[spaceIndex] = 0;  // Mark the space empty
    }

}

// Function to display the status of parking spaces
void displayParkingStatus(int parkingSpaces[], int numSpaces)
{
    printf("Welcome!\nParking Status:\n");
    for (int i = 0; i < numSpaces; i++)
    {
        printf("Space %d: %s\n", i + 1, parkingSpaces[i] == 0 ? "Empty" : "Occupied");
    }


}

int main()
{
    int parkingSpaces[NUM_PARKING_SPACES];

    initializeParkingSpaces(parkingSpaces, NUM_PARKING_SPACES);

    parkVehicle(parkingSpaces, NUM_PARKING_SPACES);
    parkVehicle(parkingSpaces, NUM_PARKING_SPACES);
    parkVehicle(parkingSpaces, NUM_PARKING_SPACES);

    
    displayParkingStatus(parkingSpaces, NUM_PARKING_SPACES);

    removeVehicle(parkingSpaces, 0);

    displayParkingStatus(parkingSpaces, NUM_PARKING_SPACES);

    return 0;

}