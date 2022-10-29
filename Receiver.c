#include <stdio.h>
#include "Receiver.h"

int arrNumbers[MAX_VALUE_SENSOR_READINGS] = {0};
int pos = 0;
int newAvg = 0;
int newAvg1 = 0;                                               
long sum = 0;
int len = sizeof(arrNumbers) / sizeof(int);
int count = sizeof(readsensorvalue) / sizeof(int);
int arrOfNumbers[MAX_VALUE_SENSOR_READINGS];
int len1 = sizeof(arrOfNumbers) / sizeof(int);

/*********This Function generates Min Value*****************/
int getMinValue(int *arrOfNumbers)
{
    int min = arrOfNumbers[0];
    for(int i=0;i<len1;i++)
    {    
	if (arrOfNumbers[i] < min)
	min = arrOfNumbers[i];
    }
    return min;
}

/*********This Function generates Max Value*****************/
int getMaxValue(int *arrOfNumbers)
{
    int max=arrOfNumbers[0];	
    for (int i = 0; i<len1; i++) 
    {
	  if (arrOfNumbers[i] > max)
	  max = arrOfNumbers[i];
	}
    return max;
}

/*********This Function reading the sensors data*****************/
int readSensorData(int min,int max,int *readsensorvalue,int *readsensorvalue1)
{
    printf("\n**************Read Sensor Data**************\n");
        for(int i = min;i<max;i++)
        {
        scanf("%d,%d",&readsensorvalue[i],&readsensorvalue1[i]);
        printf("Read sensor data1:%d,Read sensor data2:%d\n",readsensorvalue[i],readsensorvalue1[i]);
        }
	return 0;
}
/*********This Function generates simple moving average*****************/
int simpleMovingAvg(int *arrNumbers, long *sum, int pos, int len, int nextNum)
{
  *sum = *sum - arrNumbers[pos] + nextNum;
   arrNumbers[pos] = nextNum;
  return *sum / len;
}
/*********This Function Displays the Last 5  Avg Values*****************/
int newAvgCalculate(int *readsensorvalue,int *readsensorvalue1)
{
    for(int i = 0; i < count; i++)
    {
    newAvg = simpleMovingAvg(arrNumbers, &sum, pos, len, readsensorvalue[i]);
    newAvg1 = simpleMovingAvg(arrNumbers, &sum, pos, len, readsensorvalue1[i]);
    if(i>=MAX_VALUE_SENSOR_READINGS-LAST_FIVE_SENSOR_READINGS)	     // Calculate the Last Avg Value
    printf("The new Average1 is %d,The new Average2 %d\n", newAvg,newAvg1);
    pos++;
    if (pos >= len)
        {
            pos = 0;
        }
    }
	return 0;
}
