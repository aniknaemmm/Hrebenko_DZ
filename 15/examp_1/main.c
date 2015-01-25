#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/Home_15_function_of_Numbers.h"
int main()
{   int number;
    printf("Hello world!\n");
    printf("pls enter your number:");
    scanf("%d",&number);
    printf("first function result %d\n"
           "next function result %d\n"
           "next next function result %d\n",numberDigits(number),allocation_of_the_first_number(number),separation_of_all_digits_except_the_first_number(number) );
    int nextNumber;
    printf("pls enter two number:");
    scanf("%d%d",&number,&nextNumber);
    printf("next next next function result %d\n",attributing_to_the_number_of_digits_at_the_end(number,nextNumber));
     printf("next next next next function result %d",cyclic_shift_numbers_including(number));
    return 0;

}
