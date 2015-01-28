#include <stdio.h>
#include <stdlib.h>

int numberDigits(int numberUser)
{
    int tempNumber=numberUser;
    int rez=0;
    if (tempNumber==0) rez=1;
    while(tempNumber)
    {
        rez+=1;
        tempNumber/=10;
    }
    return rez;
}

int allocation_of_the_first_number(int numberUser)
{
    int tempNumber=numberUser;
    int rez=0;
    if(tempNumber/10==0) rez=numberUser;
    while(tempNumber/=10)
    {
        rez=tempNumber;
    }

    return rez;
}


int separation_of_all_digits_except_the_first_number(int numberUser)
{
    int tempNumber=1;
    int rez=0;
    if (numberUser==0) rez=0;
    while(tempNumber <= numberUser)
    {
        tempNumber *= 10;
    }
    tempNumber/= 10;
    rez=numberUser % tempNumber;
    return rez;
}

int attributing_to_the_number_of_digits_at_the_end(int firstNumberUser,int nextNumberUser)
{
    int tempNumber=1;
    int rez=0;

    for(int i=0; i<numberDigits(nextNumberUser); i++)
    {
        tempNumber*=10;
    }
    tempNumber*=firstNumberUser;
    rez=tempNumber+nextNumberUser;


    return rez;
}

int cyclic_shift_numbers_including(int numberUser)
{

    int rez;
 rez=separation_of_all_digits_except_the_first_number(numberUser)*10+allocation_of_the_first_number(numberUser);

    return rez;
}

