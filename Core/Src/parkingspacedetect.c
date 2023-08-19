#include "main.h"

#define NUM_PARKING_SPACES 10
#define GPIO_PORT   GPIOA

// Function to switch LEDs (Green/Red) according to vacancy status
void controlParkingSpaceLEDs(bool available)
{
  while (1)
  {
    if (available)
    {
      // Turn on LD2 ON pin (Green LED) and turn off LD2 OFF pin (Red LED)
      HAL_GPIO_WritePin(GPIO_PORT, LD2_ON_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIO_PORT, LD2_OFF_Pin, GPIO_PIN_RESET);
    }
    else
    {
      HAL_GPIO_WritePin(GPIO_PORT, LD2_ON_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIO_PORT, LD2_OFF_Pin, GPIO_PIN_SET);
    
    }

  }

}

// Function to initialize parking spaces as empty
void initParkingSpaces(int parkingSpaces[], int numSpaces)
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
    printf("Welcome!\n Parking Status:\n");
    for (int i = 0; i < numSpaces; i++)
    {
        printf("Space %d: %s\n", i + 1, parkingSpaces[i] == 0 ? "Empty" : "Occupied");
    }


}


// Initialize ultrasonic sensor and its' properties
void initUltrasonicSensor(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable GPIOA clock

    GPIO_InitTypeDef GPIO_InitStruct;
    
    // Initialize trigger signal
    GPIO_InitStruct.Pin = TRIG_PIN_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIO_PORT, &GPIO_InitStruct);

    // Iitialize echo signal
    GPIO_InitStruct.Pin = ECHO_PIN_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIO_PORT, &GPIO_InitStruct);

}

float measureDistance(void)
{
    HAL_GPIO_WritePin(GPIO_PORT, TRIG_PIN_Pin, GPIO_PIN_RESET);
    delay_us(2);
    HAL_GPIO_WritePin(GPIO_PORT, TRIG_PIN_Pin, GPIO_PIN_SET);
    delay_us(10);
    HAL_GPIO_WritePin(GPIO_PORT, TRIG_PIN_Pin, GPIO_PIN_RESET);

    while (HAL_GPIO_ReadPin(GPIO_PORT, ECHO_PIN_Pin) == GPIO_PIN_RESET);
    uint32_t startTime = HAL_GetTick();

    while (HAL_GPIO_ReadPin(GPIO_PORT, ECHO_PIN_Pin) == GPIO_PIN_SET);
    uint32_t endTime = HAL_GetTick();

    // Calculate distance based on the speed of sound (approx. 343 m/s at room temperature)
    float distance = ((endTime - startTime) * 34300.0) / 2000000.0;


    return distance;

}


