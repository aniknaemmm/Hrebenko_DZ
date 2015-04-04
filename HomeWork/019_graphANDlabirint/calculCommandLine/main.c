#include "calc.h"


int main(int argc,char** argv)
{
    if(strcmp(argv[1],"--help")==0||strcmp(argv[1],"-h")==0){
    printf("Command:\n-h  --help   print command\n-calc        use calc and exit\n");

    }
    else if(strcmp(argv[1],"-calc")==0){
    char virogenie[SIZE];
    Node *stack;
    initALL(&stack);
    Node *postFix;
    initALL(&postFix);
    Simvol result;
    fgets(virogenie,SIZE,stdin);
    toPostfix(&postFix,virogenie,&stack);
    dellList(&stack);
    //gogoPostfix(&postFix,&stack);
    chekTop(&result,stack);
    dellList(&stack);
    dellList(&postFix);
    printf("%.3f\n",result.numb);

    }



    return 0;
}

