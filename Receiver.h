extern int readsensorvalue[5];
extern int readsensorvalue1[5];
extern int arrNumbers[5] = {0};
extern int pos = 0;
extern int newAvg = 0;
extern int newAvg1 = 0;
extern long sum = 0;
extern int len = sizeof(arrNumbers) / sizeof(int);
extern int count = sizeof(readsensorvalue) / sizeof(int);
extern int sampleValue[5] = {1,2,3,4,5};
extern int sampleValue1[5] = {1,2,3,4,5};

void readSensorData(int min,int max,int *readsensorvalue,int *readsensorvalue1);
void displaySensorData(int min,int max,int *readsensordata);
int simpleMovingAvg(int *arrNumbers, long *sum, int pos, int len, int nextNum);
void newAvgCalculate(int *readsensorvalue,int *readsensorvalue1);
