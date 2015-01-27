int rand()
{
    static int x=1;
    int a=4096, c=150889, m=714025;
    x = ((a * x) + c) % m;
    return x;
}
