#include "date.h"

int main(void)
{
    Date youDate, tempDate;

    enterDate(&youDate);
    showDate(youDate);
    tempDate=youDate;
    addingDay(&tempDate);
     showDate(tempDate);
     printf("\n\nffff -%d\n\n",diffDateDay(youDate,tempDate));

    return 0;
}

