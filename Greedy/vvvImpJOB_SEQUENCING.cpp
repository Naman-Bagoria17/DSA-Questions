struct Job
{
    int dl;
    int pr;
};
bool cmp(Job &j1, Job &j2)
{
    return j1.pr > j2.pr;
}
vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                          vector<int> &profit)
{
    int n = id.size();
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++)
    {
        jobs[i] = {deadline[i], profit[i]};
    }
    sort(jobs.begin(), jobs.end(), cmp);
    int max_deadline = *max_element(deadline.begin(), deadline.end());
    vector<int> slots(max_deadline, -1);
    vector<int> ans(2, 0);
    for (int i = 0; i < n; i++)
    {
        for (int s = jobs[i].dl - 1; s >= 0; s--)
        {
            if (slots[s] == -1)
            {
                slots[s] = 1;
                ans[0]++;
                ans[1] += jobs[i].pr;
                break;
            }
        }
    }
    return ans;
}
