#include <bits/stdc++.h>
string postfixToPrefix(string &s)
{
    // Write your code here.
    stack<string> st;
    int i = 0;
    while (s[i])
    {
        if (isalpha(s[i]))
            st.push(string(1, s[i]));
        else
        {
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            st.push(s[i] + v2 + v1);
        }
        i++;
    }
    return st.top();
}