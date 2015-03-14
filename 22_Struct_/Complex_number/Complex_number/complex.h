#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Complex_{
    int re,im;
}Complex;


void enterComplexNumb(Complex *data);
void showComplexNumb(Complex data);
Complex summComplexNumb(Complex data_One,Complex data_two);
Complex nosummComplexNumb(Complex data_One,Complex data_two);
Complex multComplexNumb(Complex data_One,Complex data_two);
Complex desmComplex(Complex data_One,Complex data_two);

#endif // COMPLEX_H

