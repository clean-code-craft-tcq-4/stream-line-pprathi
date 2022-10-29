void readSensorData(int min,int max,int *readsensorvalue,int *readsensorvalue1);
void displaySensorData(int min,int max,int *readsensordata);
int simpleMovingAvg(int *arrNumbers, long *sum, int pos, int len, int nextNum);
void newAvgCalculate(int *readsensorvalue,int *readsensorvalue1);
extern int getMinValue(int *arrOfNumbers);
extern int getMaxValue(int *arrOfNumbers);
extern int readsensorvalue[5];
extern int readsensorvalue1[5];
extern int arrNumbers[5] = {0};
int pos = 0;
int newAvg = 0;
int newAvg1 = 0;                                               
long sum = 0;
int len = sizeof(arrNumbers) / sizeof(int);
int count = sizeof(readsensorvalue) / sizeof(int);
int arrOfNumbers[]={5,13,-12,3,25};
int len1 = sizeof(arrOfNumbers) / sizeof(int);

