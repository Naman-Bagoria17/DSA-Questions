#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *links[26];
    bool containsChar(char ch)
    {
        return this->links[ch - 'a'] != nullptr;
    }

    void putChar(char ch, Node *node)
    {
        this->links[ch - 'a'] = node;
    }

    Node *getChar(char ch)
    {
        return this->links[ch - 'a'];
    }
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Node *root = new Node();
    int ans = 1;

    for (int i = 0; i < s.size(); i++)
    {
        Node *node = root;
        for (int j = i; j < s.size(); j++)
        {
            if (!node->containsChar(s[j]))
            {
                ans++;
                node->putChar(s[j], new Node());
            }
            node = node->getChar(s[j]);
        }
    }
    return ans;
}