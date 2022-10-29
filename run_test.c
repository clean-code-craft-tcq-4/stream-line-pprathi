#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Sender.h"
#include "Receiver.h"

//Test Conditions
int sampleValue[50] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
int sampleValue1[50] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
int sampleValue2[50] = {-1,2,3,4,5,-6,7,8,9,10,11,12,-13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,-29,30,31,32,33,34,35,36,37,-38,39,40,41,-42,43,44,45,46,47,48,49,-50};

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
void unitTestReceiver()
{
	 int retValMin,retValMax;
	 retValMin = getMinValue(sampleValue);
	 assert(retValMin==1); //Test Min Value
         retValMax= getMaxValue(sampleValue);
	 assert(retValMax==50); // Test Max Value
	 retValMin = getMinValue(sampleValue2);
	 assert(retValMin==-50);  //Test Negative Value of min range
	 retValMax= getMaxValue(sampleValue2);
	 assert(retValMax==49);  //Test Postive Value of max range
         printf("min value=%d,max value=%d\n",retValMin,retValMax);
	 assert(readSensorData(0,50,sampleValue,sampleValue1)==0); //Test Read Sensor data
         assert(newAvgCalculate(sampleValue,sampleValue1)==0); // Test Last Avg of sensor data
}
int main(void) {
	 
	 sendBatteryParameters();
	 testfunctions();
         unitTestReceiver();
}
