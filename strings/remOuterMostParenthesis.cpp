//there is a space efficient approach on leetcode
string removeOuterParentheses(string s)
{
    int n = s.size();
    vector<bool> erase(n);
    stack<int> open;
    int lastOpen = -1;
    int i = 0;
    while (s[i])
    {
        if (s[i] == '(')
        {
            if (lastOpen == -1)
            {
                lastOpen = i;
                erase[i] = true;
            }
            else
                open.push(i);
        }
        else
        {
            if (!open.empty())
            {
                open.pop();
            }
            else
            {
                erase[i] = true;
                lastOpen = -1;
            }
        }
        i++;
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (!erase[i])
        {
            ans.push_back(s[i]);
        }
    }
    s = ans;
    return s;
}
