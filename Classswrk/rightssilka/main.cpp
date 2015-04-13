#include <iostream>

using namespace std;

int main()
{   int a=10;
    int b=2;
    cout << a << "  "<< b << endl;
    a^=b;
    b^=a;
    a^=b;
    cout << a << "  "<< b << endl;
    return 0;
}

/*


 object A

double *(0xBEAF-addres) ar;
int (1000)  size;


 object B

double *(0xBEAF-addres) ar;
int (1000) size;


при создание констр копирования копировать память

конструктор копирпрования вызываеться
1) явный вызов конструктора копирования zuzu создание б на основе а - b(a);
2) передаём обьект по значениям  функция(инт х);
3) при возвращение обьекта из функции ( в ретурне вызывался конструктор копирования )

правые сслыки могут ссылаться на правые времменые обьекты(конструктор перемещения)
праввая ссылка обозночаеться &&

шаблоны
/----------
int abs(int x)
{
    return x<0?-x:x;
}



MACROS в языке си
#define ABS(x)  x<0?-x:x  //corectly (x)<0?-(x):(x)
        ABS(5)  5<0?-x:x
        ABS("HELLO WORLD") err

Шаблон в языке си ++
        template<typenameT>
        T abs(T x)
        {
            return x<0?-x:x
        }
инстанцирование шаблона момент когда нам понадобилась сама функция
компиляция наступить только при инстанцирование
        int a;
        cout<<abs(a);
        cout<<abs<long long int>(a);


        примерчик

        template<typename T>
        void swap(T &a, Tp &b)
        {
            T temp=a;
            a=b;
            b=temp;
        }

это обобщённое программирование



swap переменных местами
    a^=b;
    b^=a;
    a^=b;


    специализация

        template<>
        void swap<int>(int &a, int &b)
        {
            a^=b;
            b^=a;
            a^=b;
        }


        ///other

        template <int n>
        int f()
        {
            return n*f<n-1>();
        }

        пециализация
        template<>
        int f<0>()
        {
            return 1;
        }





*/
