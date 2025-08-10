// THIS APPROACH IS LEADING TO TLE ON LEETCODE
// OPTIMAL APPROACH IS ON LEETCODE
int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    long long ans = 0;
    bool isNeg = (dividend < 0) ^ (divisor < 0);
    long long absDividend = abs((long long)dividend);
    long long absDivisor = abs((long long)divisor);
    while (absDividend >= absDivisor)
    {
        ans++;
        absDividend -= absDivisor;
    }
    return isNeg ? -ans : ans;
}
