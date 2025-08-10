// MORE EFFICIENT APPROACH ON LEETCODE
string frequencySort(string s)
{
    unordered_map<char, int> m;
    for (auto ch : s)
    {
        m[ch]++;
    }

    // ith index will store all those characters that appears i times.
    // since appearance in string>=1. Thus size of vector is 1 extra.
    // if a string is aabbcc then index 2 will store abc or any other order like bac. As per given constraints, in our answer order of characters with
    // same frequency does not matter so we can append the same way as it is stored in bucket.
    vector<string> bucket(s.size() + 1, "");
    for (auto [ch, fr] : m)
    {
        bucket[fr] += ch;
    }

    string ans = "";
    for (int i = bucket.size() - 1; i > 0; i--)
    {
        int j = 0;
        while (j < bucket[i].size())
        {
            char c = bucket[i][j];
            ans += string(i, c);
            j++;
        }
    }
    return ans;
}
