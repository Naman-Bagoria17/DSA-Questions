#include <bits/stdc++.h>
using namespace std;
// TC-O(n),SC-O(n)
vector<int> stock_span(vector<int> v)
{
    stack<int> s;
    vector<int> span(v.size(), 1);
    for (int i = 0; i < v.size(); i++)
    {
        while (!s.empty() && v[s.top()] <= v[i])
        {
            s.pop();
        }
        if (!s.empty())
        { // if this condition is true means we found PGE ka index for current element
            span[i] = i - s.top();
        }
        else
        {
            span[i] = i + 1;
        }
        s.push(i);
    }
    return span;
}
int main()
{
    vector<int> v = {10, 40, 60, 90, 80, 90};
    vector<int> span;
    span = stock_span(v);
    for (int i = 0; i < span.size(); i++)
    {
        cout << span[i] << " ";
    }
}