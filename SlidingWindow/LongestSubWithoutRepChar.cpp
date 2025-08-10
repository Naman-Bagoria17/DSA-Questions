// This approach is little complicated
// I have done more simple on Leetcode
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;
        unordered_map<char, int> m; // to store last position where this char was found
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (m.find(s[i]) != m.end() and start <= m[s[i]])
            {
                // eg-'abba' after reaching last 'a' start should not be updated
                // to last occurence of 'a'+1 bcz that substring will have 2 'b'
                // therefore if we once have started from a particular position,
                // we should not go back.
                start = m[s[i]] + 1;
            }
            m[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};