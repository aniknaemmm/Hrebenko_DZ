#include <iostream>

using namespace std;


class A
{

public:
    //int getX()const;
    //void setX(int value);
    int &x();

private:

    //int x;
    int x_;
};
/*
int A::getX()const
{
    return x;
}
void A::setX(int value)
{
    x=value;
}
*/
int &A::x()
{
    return x_;
}

int main()
{
    /*
       A a;
       a.setX(5);

       cout << a.getX() << endl;

    */
    A a;
    a.x() = 5;
    cout << a.x() << endl;


    return 0;
}







/*#include <iostream>

using namespace std;

enum Sex{male,female};

class Persona
{
private:
    char name[128];
    int age;
    Sex sex;
public:
    char *whatIsYourNaen()const;
    int  howOldAreyou()const;
    void celebrateBirthday();
    Persona(char* name,int age,Sex sex);
};


int main()
{
    Persona vasia("Vasia Ivanov",22,male);
    cout<<vasia.whatIsYourNaen();




    cout << "Hello World!" << endl;




ooп основано на понятие обьектовъ
обьект совокупность данных и методов изменяющих эти данные
инкапсуляци в ед. заключены состояние и поведение
часто  но не всегда инкапсуляция связана с сокрытием данных но это не одно и тоже

класс совокупоность обьектов одного типа




    return 0;
}*/

