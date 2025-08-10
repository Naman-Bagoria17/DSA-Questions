class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        int n = s.size();
        while (i < n and s[i] == ' ')
        {
            i++;
        }
        bool isNeg = false;
        if (i < n and (s[i] == '-' or s[i] == '+'))
        {
            isNeg = (s[i] == '-');
            i++;
        }
        int ans = 0; // if any leading zeroes or other symbol is encountered this loop will
                     // deal with it
        while (isdigit(s[i]))
        {
            int digit = s[i] - '0';
            if (ans > (INT_MAX - digit) / 10)
            {
                return isNeg ? INT_MIN : INT_MAX;
            }
            ans = ans * (10) + digit;
            i++;
        }
        return isNeg ? -ans : ans;
    }
};