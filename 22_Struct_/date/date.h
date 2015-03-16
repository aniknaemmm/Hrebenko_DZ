#ifndef DATE_H
#define DATE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
typedef struct Date_{
    int year, month, day;
}Date;
enum moth {ja=1,feb,march,aprel,mai,iyun,iyul,avgust,sentiab,octab,novemb,decemb};

bool visokYear(Date data);
bool chekNormalyEnterDate(Date data);
void enterDate(Date *data);
void showDate(Date data);
void addingDay(Date *date);
void convDate(Date *data);
int diffDateDay(Date firsdata,Date nextdata);
#endif // DATE_H

