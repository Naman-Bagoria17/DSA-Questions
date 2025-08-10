void nearlySorted(vector<int> &arr, int k)
{
    // code
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size(), st = 0;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() == k + 1)
        {
            arr[st] = pq.top();
            pq.pop();
            st++;
        }
    }
    while (!pq.empty())
    {
        arr[st] = pq.top();
        pq.pop();
        st++;
    }
}