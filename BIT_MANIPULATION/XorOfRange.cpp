// explanation on notebook
//  code on gfg
int f(int n)
{
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    if (n % 4 == 3)
        return 0;
    return n;
}
int findXOR(int l, int r)
{
    // complete the function here
    return f(r) ^ f(l - 1);
}
