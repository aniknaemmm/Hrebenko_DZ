#include "../include/compotibility.h"
#include <stdio.h>
int programmEnter(int *arrayTempMemoryProgramm)
{
    int numberCommandLine=0,tempCommand;
    printf("\ngo govnokodit'\n");
    do
    {
        printf("%02d::",numberCommandLine);
        scanf("%d",&tempCommand);
        if(tempCommand!=-9999&&(tempCommand<9999&&tempCommand>-9999))
        {
            arrayTempMemoryProgramm[numberCommandLine]=tempCommand;
        }
        else if(tempCommand==-9999)
        {
            printf("you enter -99999 \nthe end\n...............");
            universalClear();
            return 0;
        }
        else
        {
            numberCommandLine--;
            printf("error command line\n");
        }
    }
    while(++numberCommandLine<=100);
    printf("memory is full \nupgrade your virtual machine");
    return 1;
}

void runProgramm(int *arrayTempMemoryProgramm)
{
    int tempCommand,operand,stepRun=0,acamulator=0;
    do
    {

        tempCommand=arrayTempMemoryProgramm[stepRun]/100;
        operand=arrayTempMemoryProgramm[stepRun]%100;
        switch(tempCommand)
        {
        case 10:
            printf("enter you number \"operation\"[%d]::");
            scanf("%d",&arrayTempMemoryProgramm[operand]);
            break;
        case 11:
            printf("%d",arrayTempMemoryProgramm[operand]);
            break;
        case 20:
            acamulator=arrayTempMemoryProgramm[operand];
            break;
        case 21:
            arrayTempMemoryProgramm[operand]=acamulator;
            break;
        case 30:
            acamulator+=arrayTempMemoryProgramm[operand];
            break;
        case 31:
            acamulator-=arrayTempMemoryProgramm[operand];
            break;
        case 32:
            acamulator/=arrayTempMemoryProgramm[operand];
            break;
        case 33:
            acamulator*=arrayTempMemoryProgramm[operand];
            break;
        case 40:
            stepRun=operand-1;
            break;
        case 41:
            if(acamulator < 0)stepRun = operand-1;
            break;
        case 42:
            if(acamulator == 0) stepRun = operand-1;
            break;
        case 43:
            printf("\nthe end");
            break;
        }
        stepRun++;
    }
    while(tempCommand!=43);
}

