#define NUM_OF_READINGS			50
#define TEMP_MIN			0
#define TEMP_MAX			45
#define SOC_MIN				20
#define SOC_MAX				80

typedef struct{
   float temperature[NUM_OF_READINGS];
   float soc[NUM_OF_READINGS];
}tst_BatteryParameters;

typedef enum{
	SUCCESS,
	FAILURE
}status_en;

void generateSenderData(tst_BatteryParameters *ptr_BatteryParam);
void displaySenderData(status_en *ptr_operationStatus_en, tst_BatteryParameters BatteryParam);
status_en sendBatteryParameters(void);
