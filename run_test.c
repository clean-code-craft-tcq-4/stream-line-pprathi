#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Sender.h"
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
int sampleValue[5] = {1,2,3,4,5};
int sampleValue1[5] = {1,2,3,4,5};

void testfunctions(){
	tst_BatteryParameters BatteryParam;
	status_en retStatus = FAILURE;

	//Test generated data for battery paramters is within the range
	generateSenderData(&BatteryParam);
	assert(BatteryParam.temperature[20] <= TEMP_MAX);
	assert(BatteryParam.temperature[1] >= TEMP_MIN);
	assert(BatteryParam.soc[49] <= SOC_MAX);
	assert(BatteryParam.soc[15] >= SOC_MIN);

	//Test the Display interface
	displaySenderData(&retStatus, BatteryParam);
	assert( retStatus == SUCCESS);

	retStatus = sendBatteryParameters();
	assert( retStatus == SUCCESS);
}

int main(void) {
	//sendBatteryParameters();
	//testfunctions();
	 readSensorData(0,5,sampleValue,sampleValue1);
         newAvgCalculate(sampleValue,sampleValue1);
}
