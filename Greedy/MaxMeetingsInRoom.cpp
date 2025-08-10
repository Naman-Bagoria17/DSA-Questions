#include <bits/stdc++.h>
using namespace std;

int maxMeetings(vector<int> &start, vector<int> &end)
{
    vector<Meet> meets;
    for (int i = 0; i < start.size(); i++)
    {
        Meet meet;
        meet.st = start[i];
        meet.fi = end[i];
        meets.push_back(meet);
    }
    int ans = 0;
    int lastFin = -1;
    sort(meets.begin(), meets.end(), cmp);
    for (int i = 0; i < meets.size(); i++)
    {
        if (meets[i].st > lastFin)
        {
            ans++;
            lastFin = meets[i].fi;
        }
    }
    return ans;
}
