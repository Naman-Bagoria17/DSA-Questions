// THIS were MY 2 BRUTE FORCE approaches
// 2nd brute force gave intution for optimal approach
// optimal approach on leetcode
class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
    {
        int n = startTime.size();
        int maxFreeTime = 0;
        vector<int> tempSt = startTime;
        vector<int> tempEnd = endTime;
        for (int i = 0; i < n; i++)
        {
            int freeTime = 0;
            for (int j = i; j < i + k; j++)
            {
                if (j >= n)
                    break;
                int st = tempSt[j];
                int fi = tempEnd[j];
                int nextSt = (j == n - 1 ? eventTime : tempSt[j + 1]);
                int endBef = (j == 0 ? 0 : tempEnd[j - 1]);
                int dur = fi - st;
                tempSt[j] = endBef;
                tempEnd[j] = tempSt[j] + dur;
                freeTime = nextSt - tempEnd[j];
                maxFreeTime = max(maxFreeTime, freeTime);
            }
            tempSt = startTime;
            tempEnd = endTime;
        }
        return maxFreeTime;
    }
};

int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
{
    int n = startTime.size();
    int maxFreeTime = 0;
    vector<int> durations;
    for (int i = 0; i < n; i++)
    {
        durations.push_back(endTime[i] - startTime[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int freeTime = 0;
        int endBef = (i == 0 ? 0 : endTime[i - 1]);
        int dur = 0;
        int j = 0;
        for (j = i; j < i + k; j++)
        {
            if (j >= n)
                break;
            dur += durations[j];
        }
        int stTime = endBef;
        int fiTime = stTime + dur;
        int nextSt = (j >= n ? eventTime : startTime[j]);
        freeTime = nextSt - fiTime;
        maxFreeTime = max(maxFreeTime, freeTime);
    }
    return maxFreeTime;
}
