int readSensorData(int min,int max,int *readsensorvalue,int *readsensorvalue1);
void displaySensorData(int min,int max,int *readsensordata);
int simpleMovingAvg(int *arrNumbers, long *sum, int pos, int len, int nextNum);
int newAvgCalculate(int *readsensorvalue,int *readsensorvalue1);
extern int getMinValue(int *arrOfNumbers);
extern int getMaxValue(int *arrOfNumbers);
#define MAX_VALUE_SENSOR_READINGS 50
#define LAST_FIVE_SENSOR_READINGS 5
extern int readsensorvalue[MAX_VALUE_SENSOR_READINGS];
extern int readsensorvalue1[MAX_VALUE_SENSOR_READINGS];


