#ifndef ARRAY_15_B_H_INCLUDED
#define ARRAY_15_B_H_INCLUDED
#define N 90
void randomArray(int mass[],int sizeN);
//----TASK1------------------
int firstPlus(int mass[],int sizeN);
int lastMinus(int mass[],int sizeN);
void transfer(int mass[],int indexMinus, int indexPlus);
//----------------------------
//---TASK2--------------------
int chotny(int mass[],int sizeN);
int nochotny(int mass[],int sizeN);
int maxNumberArray(int mass[],int n);
int minNumberArray(int mass[],int n);
int chootnyMass[N];
int nochotnyMass[N];
//-----------------------------
//--- TASK3--------------------
void maxTransferIndex(int mass[],int sizeN,int maxElentTransfer);



#endif // ARRAY_15_B_H_INCLUDED
