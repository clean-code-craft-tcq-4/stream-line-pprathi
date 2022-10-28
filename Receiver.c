#include <stdio.h>
#include "Receiver.h"

int readsensorvalue[5];
int readsensorvalue1[5];
int arrNumbers[5] = {0};

int pos = 0;
int newAvg = 0;
int newAvg1 = 0;
long sum = 0;

int len = sizeof(arrNumbers) / sizeof(int);
int count = sizeof(readsensorvalue) / sizeof(int);

int arrOfNumbers[]={5,13,-12,3,25};


int len1 = sizeof(arrOfNumbers) / sizeof(int);

int getMinValue(int *arrOfNumbers)
{
    for(int i=0;i<len1;i++)
    {
		if (arrOfNumbers[i] < min)
			min = arrOfNumbers[i];
    }
    return min;
}


int getMaxValue(int *arrOfNumbers)
{
    for (int i = 0; i<len1; i++) 
    {
		if (arrOfNumbers[i] > max)
			max = arrOfNumbers[i];
	}
    return max;
}


void readSensorData(int min,int max,int *readsensorvalue,int *readsensorvalue1)
{
    printf("**************Read Sensor Data**************\n");
    if(readsensorvalue!=NULL)
    {
        for(int i = min;i<max;i++)
        {
       // scanf("%d,",&readsensorvalue[i]);
        printf("Read sensor data1:%d,Read sensor data2:%d\n",readsensorvalue[i],readsensorvalue1[i]);
        }
    }
}

int simpleMovingAvg(int *arrNumbers, long *sum, int pos, int len, int nextNum)
{
  *sum = *sum - arrNumbers[pos] + nextNum;
   arrNumbers[pos] = nextNum;
  return *sum / len;
}

void newAvgCalculate(int *readsensorvalue,int *readsensorvalue1)
{
    for(int i = 0; i < count; i++)
    {
    newAvg = simpleMovingAvg(arrNumbers, &sum, pos, len, readsensorvalue[i]);
    newAvg1 = simpleMovingAvg(arrNumbers, &sum, pos, len, readsensorvalue1[i]);
    printf("The new Average1 is %d,The new Average2 %d\n", newAvg,newAvg1);
    pos++;
    if (pos >= len)
        {
            pos = 0;
        }
    }
}
