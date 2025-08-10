void print_divisors(int n)
{
    vector<int> v;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (n / i != i)
            {
                v.push_back(n / i);
            }
        }
    }
    int s = v.size();
    for (int i = s - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
}
