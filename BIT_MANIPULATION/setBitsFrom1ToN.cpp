// EXPLANATION ON NOTEBOOK
int highestPowerOf2ltn(int n)
{
    int x = 0;
    while ((1 << (x + 1)) <= n)
    {
        x++;
    }
    return x;
}
int countSetBits(int n)
{
    if (n == 0)
        return 0;

    int x = highestPowerOf2ltn(n);
    int bitsFrom_0_to_2_raise_xminus1 = (1 << (x - 1)) * x;
    int msbsFrom_raise_x_to_n = n - (1 << x) + 1;
    int remaining = n - (1 << x);
    return bitsFrom_0_to_2_raise_xminus1 + msbsFrom_raise_x_to_n + countSetBits(remaining);
}
