void readSensorData(int min,int max,int *readsensorvalue,int *readsensorvalue1);
void displaySensorData(int min,int max,int *readsensordata);
int simpleMovingAvg(int *arrNumbers, long *sum, int pos, int len, int nextNum);
void newAvgCalculate(int *readsensorvalue,int *readsensorvalue1);
extern int getMinValue(int *arrOfNumbers);
extern int getMaxValue(int *arrOfNumbers);
#define MAX_VALUE_SENSOR_READING 50
extern int readsensorvalue[MAX_VALUE_SENSOR_READING];
extern int readsensorvalue1[MAX_VALUE_SENSOR_READING];


