// UNDERSTAND HUFFMAN ENCODING. QUESTION IS EASY
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

class cmp
{
public:
    bool operator()(Node *a, Node *b)
    { // this means a will come after b in priority queue if a>b which
        // creates a minHeap
        return a->val > b->val;
    }
};

class Solution
{
public:
    void traverse(Node *root, string temp, vector<string> &ans)
    {
        if (!root->left and !root->right)
        {
            ans.push_back(temp);
            return;
        }
        traverse(root->left, temp + "0", ans);
        traverse(root->right, temp + "1", ans);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        // Code here
        int n = f.size();
        priority_queue<Node *, vector<Node *>, cmp> pq;
        for (auto ele : f)
        {
            Node *newNode = new Node(ele);
            pq.push(newNode);
        }

        while (pq.size() > 1)
        {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();
            Node *parent = new Node(a->val + b->val);
            parent->left = a;
            parent->right = b;
            pq.push(parent);
        }

        Node *root = pq.top();
        vector<string> ans;
        traverse(root, "", ans);
        return ans;
    }
};