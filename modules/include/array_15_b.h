#ifndef ARRAY_15_B_H_INCLUDED
#define ARRAY_15_B_H_INCLUDED
#define N 90
void randomArray(int mass[],int sizeN);
void coppyArray(int massEtalon[],int sizeN,int massCoppy[]);
//---TASK1------------------
int firstPlus(int mass[],int sizeN);
int lastMinus(int mass[],int sizeN);
void transfer(int mass[],int indexMinus, int indexPlus);
//----------------------------
//---TASK2--------------------
int chotny(int mass[],int sizeN,int chootnyMass[]);
int nochotny(int mass[],int sizeN,int nochotnyMass[]);
int maxNumberArray(int mass[],int n);
int minNumberArray(int mass[],int n);

//-----------------------------
//---TASK3--------------------
void maxTransferIndex(int mass[],int sizeN,int maxElentTransfer);
//---TASK4---------------------
void allTransferMaxadnMin(int mass[],int sizeN,int maxChot,int minNochot);
//---TASK5---------------------
int lastPolog(int chotnyMass[],int chotnySize,int userNumber);
int indexMass(int mass[],int sizeN,int numberChotniAndCratny);
//---TASK6---------------------
int serhNumb(int mass[],int sizeN,int userNumber);


#endif // ARRAY_15_B_H_INCLUDED