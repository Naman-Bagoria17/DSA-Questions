// OPTIMAL APPROACH ON LEETCODE WITHOUT STACKS
bool checkValidString(string s)
{
    stack<int> op, st;
    int i = 0;
    while (s[i])
    {
        if (s[i] == '(')
        {
            op.push(i);
        }
        else if (s[i] == ')')
        {
            if (!op.empty())
            {
                op.pop();
            }
            else if (!st.empty())
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            st.push(i);
        }
        i++;
    }
    while (!op.empty() and !st.empty())
    {
        if (op.top() > st.top())
        {
            return false;
        }
        op.pop();
        st.pop();
    }
    return op.empty();
}