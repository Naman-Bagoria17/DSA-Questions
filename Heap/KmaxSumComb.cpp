vector<int> maxCombinations(int n, int K, vector<int> &A, vector<int> &B)
{
    // code here
    //[7,5,3,2]
    //[4,2,2,1] here first pair is 11 and next are 9,9 then we can 7 and 2 form a max pair so it means any number from A can form pair with any number from B. it may be the case the for now an element is smaller and later it forms a max pair with some other number. So we need to push sum in the priority queue with index of elements in the both arrays. And also a set need to be maintained vis bcz it may be possible that same pair is pushed in two different scenarios.
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({A[0] + B[0], {0, 0}});
    set<pair<int, int>> vis;
    vis.insert({0, 0});
    vector<int> ans;

    while (K-- && !pq.empty())
    {
        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();
        int sum = curr.first;
        int first = curr.second.first;
        int second = curr.second.second;
        ans.push_back(sum);
        if (first + 1 < n && !vis.count({first + 1, second}))
        {
            pq.push({A[first + 1] + B[second], {first + 1, second}});
            vis.insert({first + 1, second});
        }
        if (second + 1 < n && !vis.count({first, second + 1}))
        {
            pq.push({A[first] + B[second + 1], {first, second + 1}});
            vis.insert({first, second + 1});
        }
    }

    return ans;
}