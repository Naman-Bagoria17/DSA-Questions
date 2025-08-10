vector<int> arrayRankTransform(vector<int> &arr)
{
    vector<int> temp = arr;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        pq.push({arr[i], i});
    }
    int rank = 0, last = INT_MAX;
    ;
    while (!pq.empty())
    {
        auto [ele, idx] = pq.top();
        pq.pop();
        if (ele != last)
        {
            arr[idx] = ++rank;
        }
        else
            arr[idx] = rank;
        last = ele;
    }
    return arr;
}
