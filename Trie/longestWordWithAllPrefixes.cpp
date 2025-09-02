class Node
{
public:
    Node *links[26];
    bool flag = false;

    bool containsChar(char ch)
    {
        return this->links[ch - 'a'] != nullptr;
    }

    void putChar(char ch, Node *node)
    {
        this->links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return this->links[ch - 'a'];
    }

    bool isEnd()
    {
        return this->flag;
    }

    void setEnd()
    {
        this->flag = true;
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsChar(word[i]))
            {
                node->putChar(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool containsAllPrefixes(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsChar(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
            if (!node->isEnd())
                return false;
        }
        return true;
    }
};
class Solution
{
public:
    string longestValidWord(vector<string> &words)
    {
        // code here
        int n = words.size();

        Trie *t = new Trie();
        for (int i = 0; i < n; i++)
        {
            t->insert(words[i]);
        }

        string longest = "";
        for (int i = 0; i < n; i++)
        {
            if (t->containsAllPrefixes(words[i]))
            {
                if (words[i].size() > longest.size())
                {
                    longest = words[i];
                }
                else if (words[i].size() == longest.size() && words[i] < longest)
                {
                    longest = words[i];
                }
            }
        }

        return longest;
    }
};
