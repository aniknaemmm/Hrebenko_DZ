#include <iostream>
#include <cstdlib> // вот вот вот
#include <iomanip>
using namespace std;

int main()
{
    int a;
    cout << "Hello world!" << endl;//можно без std
    cout<< hex<<12<<endl;
    //поле вывода
    cout.width(5);
    cout.fill('*');//заполнение пустого места перед числом
    cout<< 12<<endl;
    cout.precision(2);//количество значащих цифр

    cout<<dec<<setw(5)<<12<<endl;
    cout<<setw(5)<<12<<endl;

    cin>>a;
    cout<<a<<endl;
    cerr<<"erroe"<<endl;//stderr ошибок


    /*пергрузка функций
        сигнатура функций  название!!!! и получаемые типы
        компилятор различает функии по сигнатурам соответственно получаеться эфф перегрузки функций
        /-------------
        параметры по умолчанию
            void foo(int a,int b=5);
        нельзя теперь сделать
            void foo(int x);
        !параметр по умолчанию можно написать только 1 раз
        /-------------------------
        ссылки
        ссылка обязана быть сразу проинициалезированнна
        ссылка не меняеться
        ссылка упрощение записи передачи по указателю т.е. синтакситческий сахар
        int x,&a=x;
        void push(Node *&top) //передача указателя по ссылке
        есть и правые ссылки
        /--------
        структура
        struct Person{
            int age;
            ......
        };

        Person vasia;

        настоящих структур в с++ не существует


    */

    //    выделение памяти
        int *array = nullptr;
        array = new int[5]();//заполняеться нулём< в скобках только без параметров
        //в этом случае вызов с конструктором()
        //new при невозможности выделения памяти кидает в исключения
       //------
        //немасивное выделение памяти
        /*
            Node *p=nullptr;
            p=new Node;
            delete p;
            p=nullptr;
        */
       //---------
       //         ДЗ
       //скопипастить две програмки с С на С++



        delete [] array;
        array=nullptr;








    return 0;
}


/*пространство имён
    никогда не раскрывать пространство имён в заголовочных файлах и до подключения всех инклудов


вывод cout<<"hello \n";
      cout<<'A';
      cout<< 12;
      cout<< a << b;
вывод в 16
    cout<<hex<< 12;
*/

