/***************************************************************************************************
                            ExploreEmbedded Copyright Notice    
****************************************************************************************************
 * File:   01-TaskSwitching
 * Version: 15.0
 * Author: ExploreEmbedded
 * Website: http://www.exploreembedded.com/wiki
 * Description: File contains the free rtos example to demonstarte the task switching.

This code has been developed and tested on ExploreEmbedded boards.  
We strongly believe that the library works on any of development boards for respective controllers. 
Check this link http://www.exploreembedded.com/wiki for awesome tutorials on 8051,PIC,AVR,ARM,Robotics,RTOS,IOT.
ExploreEmbedded invests substantial time and effort developing open source HW and SW tools, to support consider 
buying the ExploreEmbedded boards.
 
The ExploreEmbedded libraries and examples are licensed under the terms of the new-bsd license(two-clause bsd license).
See also: http://www.opensource.org/licenses/bsd-license.php

EXPLOREEMBEDDED DISCLAIMS ANY KIND OF HARDWARE FAILURE RESULTING OUT OF USAGE OF LIBRARIES, DIRECTLY OR
INDIRECTLY. FILES MAY BE SUBJECT TO CHANGE WITHOUT PRIOR NOTICE. THE REVISION HISTORY CONTAINS THE INFORMATION 
RELATED TO UPDATES.
 

Permission to use, copy, modify, and distribute this software and its documentation for any purpose
and without fee is hereby granted, provided that this copyright notices appear in all copies 
and that both those copyright notices and this permission notice appear in supporting documentation.
**************************************************************************************************/

#include <Arduino_FreeRTOS.h>

void setup()
{
  
  Serial.begin(9600);
  Serial.println(F("In Setup function"));

  /* Create two tasks with priorities 1 and 2. An idle task is also created, 
     which will be run when there are no tasks in RUN state */
//PRIORITY::: Higher number means higher priority, hence priority 0 is of the lowest priority

  xTaskCreate(MyTask1, "Task1", 100, NULL, 1, NULL); //Lowest Priority
  xTaskCreate(MyTask2, "Task2", 100, NULL, 2, NULL);
  xTaskCreate(MyTask1, "Task3", 100, NULL, 3, NULL);
  xTaskCreate(MyTask2, "Task4", 100, NULL, 4, NULL);
  xTaskCreate(MyTask1, "Task5", 100, NULL, 5, NULL);
  xTaskCreate(MyTask2, "Task6", 100, NULL, 6, NULL);
  xTaskCreate(MyTask1, "Task7", 100, NULL, 7, NULL);
  xTaskCreate(MyTask2, "Task8", 100, NULL, 8, NULL); //Highest prioity
  xTaskCreate(MyIdleTask, "IdleTask", 100, NULL, 0, NULL);
}


void loop()
{
  // DO nothing
}


/* Task1 with priority 1 */
static void MyTask1(void* pvParameters)
{
  while(1)
  {
    Serial.println(F("Task1"));
    vTaskDelay(100/portTICK_PERIOD_MS); //100 ms delay
  }
}


/* Task2 with priority 2 */
static void MyTask2(void* pvParameters)
{
  while(1)
  {    
    Serial.println(F("Task2"));
    vTaskDelay(150/portTICK_PERIOD_MS);
  }
}

/* Task3 with priority 3 */
static void MyTask3(void* pvParameters)
{
  while(1)
  {
    Serial.println(F("Task3"));
    vTaskDelay(100/portTICK_PERIOD_MS); //100 ms delay
  }
}


/* Task4 with priority 4 */
static void MyTask4(void* pvParameters)
{
  while(1)
  {    
    Serial.println(F("Task4"));
    vTaskDelay(150/portTICK_PERIOD_MS);
  }
}

/* Task5 with priority 5 */
static void MyTask5(void* pvParameters)
{
  while(1)
  {
    Serial.println(F("Task5"));
    vTaskDelay(100/portTICK_PERIOD_MS); //100 ms delay
  }
}


/* Task6 with priority 6 */
static void MyTask6(void* pvParameters)
{
  while(1)
  {    
    Serial.println(F("Task6"));
    vTaskDelay(150/portTICK_PERIOD_MS);
  }
}

/* Task7 with priority 7 */
static void MyTask7(void* pvParameters)
{
  while(1)
  {
    Serial.println(F("Task7"));
    vTaskDelay(100/portTICK_PERIOD_MS); //100 ms delay
  }
}


/* Task8 with priority 8 */
static void MyTask8(void* pvParameters)
{
  while(1)
  {    
    Serial.println(F("Task8"));
    vTaskDelay(150/portTICK_PERIOD_MS);
  }
}


/* Idle Task with priority Zero */ 
static void MyIdleTask(void* pvParameters)
{
  while(1)
  {
    Serial.println(F("Idle state"));
    delay(50);
  }
}
