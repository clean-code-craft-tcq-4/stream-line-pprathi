void readSensorData(int min,int max,int *readsensorvalue,int *readsensorvalue1);
void displaySensorData(int min,int max,int *readsensordata);
int simpleMovingAvg(int *arrNumbers, long *sum, int pos, int len, int nextNum);
void newAvgCalculate(int *readsensorvalue,int *readsensorvalue1);
extern int getMinValue(int *arrOfNumbers);
extern int getMaxValue(int *arrOfNumbers);
extern int readsensorvalue[5];
extern int readsensorvalue1[5];


