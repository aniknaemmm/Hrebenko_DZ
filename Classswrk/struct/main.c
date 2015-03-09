#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Persona
{
    char name[128];
    int age;
    enum Sex {male,female} sex;
    double tall;
};

int main()
{
    struct Persona vasia,petia={"petia ivanov",24,male,1.74};
    vasia=petia;
    strcpy(vasia.name,"vasia ivanov");
    vasia.tall=1.76;
    struct Persona *p;
    p=&vasia;
    (*p).tall-=0.01;
    p->tall-=0.0 1;
/*
    typedef Persona_{


    }Persona;*/


    printf("Hello world!\n");
    return 0;
}


