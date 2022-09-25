#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Sender.h"

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
	 readData();
}
