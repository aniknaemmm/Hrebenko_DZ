#include "complex.h"

void enterComplexNumb(Complex *data){
    char temp;
    printf("enter to complex numb\nexmapl : re+i(im)\n");
    scanf("%d%ci%d",&data->re,&temp,&data->im);
    data->im*=temp=='+'?1:-1;
}


void showComplexNumb(Complex data){

    printf(" complex numb %d%ci%d \n",data.re,data.im>=0?'+':'-',abs(data.im));
}

Complex summComplexNumb(Complex data_One,Complex data_two){
    Complex result;
    result.im=data_One.im+data_two.im;
    result.re=data_One.re+data_two.re;
    return result;

}


Complex nosummComplexNumb(Complex data_One,Complex data_two){
    Complex result;
    result.im=data_One.im-data_two.im;
    result.re=data_One.re-data_two.re;
    return result;

}
Complex multComplexNumb(Complex data_One,Complex data_two){
    Complex result; // result=(re+i(im))*(re+i(im));
                    //result=re*re+re*i(im) + re*i(im)+i(im)*i(im);
    result.re=data_One.re*data_two.re-data_One.im*data_two.im;
    result.im=data_two.re*data_One.im+data_One.re*data_two.im;
return result;
}

Complex desmComplex(Complex data_One,Complex data_two){
    Complex result;
    result.re=((data_One.re*data_two.re+data_One.im*data_two.im)/(data_two.re*data_two.re+data_two.im*data_two.im));
    result.im=(data_One.im*data_two.re-data_One.re*data_two.im)/(data_two.re*data_two.re+data_two.im*data_two.im);
    return result;
}
