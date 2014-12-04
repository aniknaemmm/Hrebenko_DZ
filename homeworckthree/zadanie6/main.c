#include <stdio.h>
#include <stdlib.h>

int main(){
    int l,x,rez;
    int p=0;
    printf("pls enter L>0 l=");
    scanf("\n%d",&l);
    printf("pls enter x<=L x=");
    scanf("\n%d",&x);
        for(p=0;rez<=l;p++){
                rez=1;
            for(int i=0;i<=p;i++){
                rez=rez*x;
            }
        }
    printf(" stepen p=%d\n",p-1);
    printf("x v p strepeni=%d<=L(L=%d)",rez/x,l);
    return 0;
}
