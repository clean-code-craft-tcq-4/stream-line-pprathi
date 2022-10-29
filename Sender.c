#include <stdio.h>
#include <stdlib.h>
#include "Sender.h"

void generateSenderData(tst_BatteryParameters *ptr_BatteryParam){
	//generate data for Battery parameters
	for(int index = 0; index < NUM_OF_READINGS; index++){
		ptr_BatteryParam->temperature[index] = (rand()%(TEMP_MAX - TEMP_MIN + 1)) + TEMP_MIN;
		ptr_BatteryParam->soc[index] = (rand()%(SOC_MAX - SOC_MIN + 1)) + SOC_MIN;
	}
}

void displaySenderData(status_en *ptr_operationStatus_en, tst_BatteryParameters BatteryParam){
	*ptr_operationStatus_en = FAILURE;
	int index = 0;
	//Print BaterryParameters data to console
	for(index = 0; index < NUM_OF_READINGS; index++){
		printf("\nTemperature: %.f, SOC: %.f",BatteryParam.temperature[index],BatteryParam.soc[index]);
	}
	*ptr_operationStatus_en = SUCCESS;
}

status_en sendBatteryParameters(void){
	tst_BatteryParameters BatteryParam;
	status_en operationStatus_en = FAILURE;
	//Generate data for Battery parameters and print to console
	generateSenderData(&BatteryParam);
	displaySenderData(&operationStatus_en, BatteryParam);
	return operationStatus_en;
}
