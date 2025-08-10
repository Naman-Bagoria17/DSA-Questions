string smallestNumber(int s, int d)
{
    if (s < 1 or 9 * d < s)
        return "-1";
    string ans(d, '0');
    s -= 1;
    int i;
    for (i = d - 1; i >= 0; i--)
    {
        if (s >= 9)
        {
            ans[i] = '9';
            s -= 9;
        }
        else
        {
            ans[i] = '0' + s;
            break;
        }
    }
    ans[0] += 1;
    return ans;
}
