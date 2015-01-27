int rand()
{

    int m = 5695, a = 5, c = 3999;
    static int x=1;
    x = ((a * x) + c) % m;
    return x;
}
