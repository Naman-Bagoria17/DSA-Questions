int findPlatform(vector<int> &arr, vector<int> &dep)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int n = arr.size();
    int i = 0;
    int j = 0;
    int platformsInUse = 0;
    int minPlatforms = 0;
    while (i < n and j < n)
    {
        if (arr[i] <= dep[j])
        {
            platformsInUse++;
            i++;
        }
        else
        {
            platformsInUse--;
            j++;
        }
        minPlatforms = max(minPlatforms, platformsInUse);
    }
    return minPlatforms;
}
