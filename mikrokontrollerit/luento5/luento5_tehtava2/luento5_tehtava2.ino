#include <Arduino_FreeRTOS.h>

volatile long int counter = 0;

void TaskSerialReadAndAdd(void *pvParameters);
void TaskSubstractAndPrint(void *pvParameters);

// the setup function runs once when you press reset or power the board
void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  //aseta(1);
  Serial.println("Aloitetaan.");


  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }

  // Now set up two tasks to run independently.
  xTaskCreate(
    TaskSerialReadAndAdd,
    "SerialReadAndAdd", // custom name
    128,  // Stack size
    NULL,
    1,  // Priority 3 is highest, 0 lowest
    NULL );

  xTaskCreate(
    TaskSubstractAndPrint,
    "SubstractAndPrint",
    128,  // Stack size
    NULL,
    2,  // Priority
    NULL );

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/
void TaskSerialReadAndAdd(void *pvParameters) {
  (void) pvParameters;

  while(1) {
    counter += Serial.parseInt();
  }
}

void TaskSubstractAndPrint(void *pvParameters) {
  (void) pvParameters;

  while(1) {
    if (counter > 0) {
      Serial.print("Current counter: ");Serial.println(counter);
    }
    counter--;
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}