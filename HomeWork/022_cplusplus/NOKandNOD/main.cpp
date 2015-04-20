#include <iostream>

using namespace std;
template<typename T>
T NOD(T a, T b);
template<typename T>
T NOK(T a, T b);
template<typename T>
T NOD(T a, T b)
{
    while(a != b)
    {
        if(a > b)
            a -= b;
        else
            b -= a;
    }

    return a;
}
template<typename T>
T NOK(T a, T b)
{
    return a * b / NOD(a, b);
}
int main()
{
    double a = 5;
    double b = 15;
    cout<<"enter two number\n";

    cin>>a>>b;
    std::cout << NOD(a, b) << " " << NOK(a, b) << std::endl;
    return 0;
}
