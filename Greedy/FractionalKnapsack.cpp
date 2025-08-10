//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// class implemented

struct Item
{
    int value;
    int weight;
};

bool cmp(Item i1, Item i2)
{
    double v2wi1 = static_cast<double>(i1.value) / i1.weight;
    double v2wi2 = static_cast<double>(i2.value) / i2.weight;
    return v2wi1 > v2wi2;
}
class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        vector<Item> items;
        for (int i = 0; i < val.size(); i++)
        {
            Item item;
            item.value = val[i];
            item.weight = wt[i];
            items.push_back(item);
        }
        sort(items.begin(), items.end(), cmp);
        double ans = 0;
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].weight <= capacity)
            {
                ans += items[i].value;
                capacity -= items[i].weight;
            }
            else
            {
                double factor = static_cast<double>(capacity) / items[i].weight;
                ans += (factor * items[i].value);
                break; // If maximum V/W vaale ka fraction uthana pr raha hai
                // to aage kuchh utha hi ni paoge
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--)
    {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number)
        {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends