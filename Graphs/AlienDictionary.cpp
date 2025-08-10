string findOrder(vector<string> &words)
{
    int n = words.size();
    if (n == 1)
    {
        string ans = "";
        unordered_set<char> s;
        for (auto ch : words[0])
            s.insert(ch);
        for (auto ch : s)
        {
            ans += string(1, ch);
        }
        return ans;
    }

    vector<vector<int>> graph(26);
    unordered_set<char> chars;

    // Build character set and adjacency list
    for (int i = 0; i < n - 1; i++)
    {
        string word1 = words[i], word2 = words[i + 1];
        int len1 = word1.size(), len2 = word2.size();
        int j = 0, k = 0;

        // Find first differing character
        while (j < len1 && k < len2)
        {
            chars.insert(word1[j]);
            chars.insert(word2[k]);
            if (word1[j] != word2[k])
            {
                graph[word1[j] - 'a'].push_back(word2[k] - 'a');
                break;
            }
            j++;
            k++;
        }

        // Check for invalid order (prefix condition)
        if (j < len1 && k == len2 && word1.substr(0, len2) == word2)
        {
            return "";
        }

        // Add remaining characters
        while (j < len1)
        {
            chars.insert(word1[j]);
            j++;
        }
        while (k < len2)
        {
            chars.insert(word2[k]);
            k++;
        }
    }

    // Topological sort using Kahn's algorithm
    vector<int> indegree(26, 0);
    for (int i = 0; i < 26; i++)
    {
        for (int neighbor : graph[i])
        {
            indegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (indegree[i] == 0 && chars.count('a' + i))
        {
            q.push(i);
        }
    }

    string result;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        result += ('a' + curr);

        for (int neighbor : graph[curr])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    // Check if all characters were included (no cycles)
    if (result.size() != chars.size())
    {
        return "";
    }

    return result;
}