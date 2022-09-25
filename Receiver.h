int readsensorvalue[5];
int readsensorvalue1[5];
int arrNumbers[5] = {0};
int pos = 0;
int newAvg = 0;
int newAvg1 = 0;
long sum = 0;
int len = sizeof(arrNumbers) / sizeof(int);
int count = sizeof(readsensorvalue) / sizeof(int);
int sampleValue[5] = {1,2,3,4,5};
int sampleValue1[5] = {1,2,3,4,5};

void readSensorData(int min,int max,int *readsensorvalue,int *readsensorvalue1);
void displaySensorData(int min,int max,int *readsensordata);
int simpleMovingAvg(int *arrNumbers, long *sum, int pos, int len, int nextNum);
void newAvgCalculate(int *readsensorvalue,int *readsensorvalue1);
