#include <stdio.h>
#include <stdlib.h>

int main(){

  int chas,min,sec;
  chas=1;
  min=19;
  sec=13;
  printf("%02d:%02d:%02d\n",chas,min,sec);
  printf("%02d:%02d:%02d\n",chas*2,min*2,sec*2);
  printf("%02d:%02d:%02d\n",chas*3,min*3,sec*3);

  return 0;
    }
