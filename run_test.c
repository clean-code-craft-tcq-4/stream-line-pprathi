#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Sender.h"
#include "Receiver.h"

int sampleValue[50] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
int sampleValue1[50] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};

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
         int retValMin = getMinValue(sampleValue);
         int retValMax= getMaxValue(sampleValue);
         printf("min value=%d,max value=%d",retValMin,retValMax);
	 readSensorData(0,50,sampleValue,sampleValue1);
         newAvgCalculate(sampleValue,sampleValue1);
}
