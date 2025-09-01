#include <bits/stdc++.h>
class Node
{
public:
    Node *links[26];
    int cntEnd;
    int cntPref;

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
    int getEnd()
    {
        return this->cntEnd;
    }
    int getPref()
    {
        return this->cntPref;
    }
    void incEnd()
    {
        this->cntEnd++;
    }

    void incPref()
    {
        this->cntPref++;
    }

    void reducePref()
    {
        this->cntPref--;
    }
    void deleteEnd()
    {
        this->cntEnd--;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsChar(word[i]))
            {
                node->putChar(word[i], new Node());
            }
            node = node->get(word[i]);
            node->incPref();
        }
        node->incEnd();
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsChar(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsChar(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPref();
    }

    void erase(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            node = node->get(word[i]);
            node->reducePref();
        }
        node->deleteEnd();
    }
};
