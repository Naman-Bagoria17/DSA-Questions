// THIS APPROACH IS NOT OPTIMAL
// OPTIMAL APPROACH ON LEETCODE
int nthUglyNumber(int n)
{
    int count = 0;
    int num = 1;
    while (true)
    {
        int i = num;
        while (i % 2 == 0)
        {
            i /= 2;
        }
        while (i % 3 == 0)
        {
            i /= 3;
        }
        while (i % 5 == 0)
        {
            i /= 5;
        }
        if (i == 1)
            count++;
        if (count == n)
            return num;
        num++;
    }
}
