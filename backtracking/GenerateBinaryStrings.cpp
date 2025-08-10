void Helper(int n, vector<string> &ans, string &s)
{
    if (s.size() == n)
    {
        ans.push_back(s);
        return;
    }
    s.push_back('0');
    Helper(n, ans, s);
    s.pop_back();
    if (s.empty() or s.back() != '1')
    {
        s.push_back('1');
        Helper(n, ans, s);
        s.pop_back();
    }
}
vector<string> generateBinaryStrings(int num)
{
    vector<string> ans;
    string s;
    Helper(num, ans, s);
    return ans;
}
