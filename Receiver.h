void readSensorData(int min,int max,int *readsensorvalue,int *readsensorvalue1);
void displaySensorData(int min,int max,int *readsensordata);
int simpleMovingAvg(int *arrNumbers, long *sum, int pos, int len, int nextNum);
void newAvgCalculate(int *readsensorvalue,int *readsensorvalue1);
int getMinValue(int *arrOfNumbers);
int getMaxValue(int *arrOfNumbers);
extern int min,max;
