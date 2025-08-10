#include<bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &mat)
{
    int n = mat.size();
    int top = 0;        // 0th person
    int bottom = n - 1; // last person
    while (top < bottom)
    {
        // if both know each other or nobody knows the other
        // then both cannot be a celebrity
        if ((mat[top][bottom] and mat[bottom][top]) or (mat[top][bottom] == 0 and mat[bottom][top] == 0))
        {
            top++;
            bottom--;
        }

        // if top knows bottom then top cannot be a celebrity
        else if (mat[top][bottom])
        {
            top++;
        }

        // if bottom knows top then bottom cannot be a celebrity
        else if (mat[bottom][top])
        {
            bottom--;
        }
    }
    // in case top and bottom crosses each other
    if (top > bottom)
        return -1;

    // if top==bottom check that top(th) person is a celebrity or not
    for (int i = 0; i < n; i++)
    {
        if (i == top)
            continue;
        if (mat[top][i] == 0 and mat[i][top] == 1)
            continue;
        return -1;
    }
    return top;
}
