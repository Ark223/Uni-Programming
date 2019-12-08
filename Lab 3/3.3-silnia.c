
long wynik;

int SilniaInt(int n)
{
    int a = 1;
    while (n > 0) { a *= n; n--; }
    return a;
}

long SilniaLong(int n)
{
    long a = 1;
    while (n > 0) { a *= n; n--; }
    return a;
}

long long SilniaLongLong(int n)
{
    long long a = 1;
    while (n > 0) { a *= n; n--; }
    return a;
}

int SilniaRecursive(int n)
{
    return n < 2 ? 1 : n * SilniaRecursive(n - 1);
}
