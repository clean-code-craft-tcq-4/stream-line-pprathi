#include <stdio.h>
#include <stdlib.h>
#include "Sender.h"

void generateSenderData(tst_BatteryParameters *ptr_BatteryParam){
	for(int index = 0; index < NUM_OF_READINGS; index++){
		ptr_BatteryParam->temperature[index] = (rand()%(TEMP_MAX - TEMP_MIN + 1)) + TEMP_MIN;
		ptr_BatteryParam->soc[index] = (rand()%(SOC_MAX - SOC_MIN + 1)) + SOC_MIN;
	}
}

status_en displaySenderData(tst_BatteryParameters BatteryParam){
	status_en returnStatus_en = FAILURE;
	int index = 0;
	for(index = 0; index < NUM_OF_READINGS; index++){
		printf("\nTemperature: %.f, SOC: %.f",BatteryParam.temperature[index],BatteryParam.soc[index]);
	}
	if (index == NUM_OF_READINGS){
		returnStatus_en = SUCCESS;
	}
	return returnStatus_en;
}

status_en sendBatteryParameters(void){
	tst_BatteryParameters BatteryParam;
	status_en returnStatus_en = FAILURE;

	generateSenderData(&BatteryParam);
	returnStatus_en = displaySenderData(BatteryParam);
	return returnStatus_en;
}
