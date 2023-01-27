///////////////////////////////////////////////////////////////////////////
//                      Small Engine Rev Limiter                         //
//                                                                       //
//  This program runs on Arduino and measures RPM using alternator       //
//  pulses. See included wiring diagram. Code is fairly straight forward.//
//  Uses RTOS framework to create and schedule tasks.                    //
//                                                                       //
//  Last Modified: 1/27/2023 by Taylor Daniska                           //
///////////////////////////////////////////////////////////////////////////

#include <Seeed_Arduino_FreeRTOS.h>
#include <Wire.h>

#define  ERROR_LED_PIN  13
const int tachPin = 0;
const int ignPin = 1;
const int potPin = 3;

#define ERROR_LED_LIGHTUP_STATE  LOW 
#define SERIAL          SerialUSB

TaskHandle_t Handle_aTask;
TaskHandle_t Handle_bTask;
TaskHandle_t Handle_cTask;
TaskHandle_t Handle_monitorTask;

int tachHigh; 
int tachLow; 
float tachTotal; 
float frequency; 
int rpm;
int redline = 3500;
int potValue;
char input;

void myDelayUs(int us) {
    vTaskDelay(us / portTICK_PERIOD_US);
}

void myDelayMsUntil(TickType_t* previousWakeTime, int ms) {
    vTaskDelayUntil(previousWakeTime, (ms * 1000) / portTICK_PERIOD_US);
}

static void threadA(void* pvParameters) {
  while (1) {
    potValue = analogRead(potPin);
    redline = potValue * (5000 / 1023);

    delay(250);
  }
}

static void threadB(void* pvParameters) {
  while (1) {
    tachHigh = pulseIn(tachPin, HIGH);
    tachLow = pulseIn(tachPin, LOW);
    tachTotal = tachHigh + tachLow;

    frequency = 1000000 / tachTotal;
    rpm = frequency * 10;
    //rpm = 2000;

    if (rpm >= redline) {
      digitalWrite(ignPin, HIGH);
    } else {
      digitalWrite(ignPin, LOW);
    }

    delay(5);
  }

}

static void threadC(void* pvParameters) {
  while (1) {
    //if(Serial.available()){
        //input = Serial.read();
        //Serial.print("You typed: " );
        //Serial.println(input);
    //}

    //delay(1000);
  }
}

void taskMonitor(void* pvParameters) {
  SERIAL.println("Task Monitor: Started");

  while(1) {
    SERIAL.println("");
    SERIAL.println("******************************");
    SERIAL.println("*       [Task Monitor]       *");
    SERIAL.println("******************************");

    SERIAL.print("Redline: ");
    SERIAL.println(redline);

    SERIAL.print("RPM: ");
    SERIAL.println(rpm);

    SERIAL.println("******************************");

    delay(250); 
  }
}

void setup() {
  SERIAL.begin(115200);

  pinMode(tachPin, INPUT);
  pinMode(ignPin, OUTPUT);

  vNopDelayMS(1000); // prevents usb driver crash on startup, do not omit this
  while (!SERIAL) ;  // Wait for serial terminal to open port before starting program
    SERIAL.println("");
    SERIAL.println("******************************");
    SERIAL.println("*      [Program start]       *");
    SERIAL.println("******************************");
    vSetErrorLed(ERROR_LED_PIN, ERROR_LED_LIGHTUP_STATE);

    // Create the threads that will be managed by the rtos
    // Sets the stack size and priority of each task
    // Also initializes a handler pointer to each task, which are important to communicate with and retrieve nfo from tasks
    xTaskCreate(threadA,     "Task A",       256, NULL, tskIDLE_PRIORITY + 4, &Handle_aTask);
    xTaskCreate(threadB,     "Task B",       256, NULL, tskIDLE_PRIORITY + 3, &Handle_bTask);
    //xTaskCreate(threadC,     "Task C",       256, NULL, tskIDLE_PRIORITY + 2, &Handle_cTask);
    xTaskCreate(taskMonitor, "Task Monitor", 256, NULL, tskIDLE_PRIORITY + 1, &Handle_monitorTask);

    // Start the RTOS, this function will never return and will schedule the tasks.
    vTaskStartScheduler();

}

void loop(){}
