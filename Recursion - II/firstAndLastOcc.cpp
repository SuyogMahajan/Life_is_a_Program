#include <iostream>
using namespace std;

// ::::::::::::::::::: Linear ::::::::::::::::::::::

int findFirstOcc(int *a, int n, int t)
{
    if (n <= 0)
        return -1;
    if (a[0] == t)
        return 0;
    int ans = findFirstOcc(a + 1, n - 1, t);
    return ans == -1 ? -1 : ans + 1;
}

int findLastOcc(int *a, int n, int t)
{
    if (n <= 0)
        return -1;
    int ans = findLastOcc(a + 1, n - 1, t);
    if (ans == -1)
    {
        if (a[0] == t)    return 0;
        else    -1;
    }
    else
    {  return ans + 1;
    }
    return -1;
}

// ::::::::::::::::: Binary Search :::::::::::::::::

int findFirstWithBinary(int *a, int s, int e, int t)
{
    if (s > e)
        return -1;

    int m = s + (e - s) / 2;
    int ans = -1;
    if (a[m] == t)
    {
        int k = findFirstWithBinary(a, s, m - 1, t);
        ans = k == -1 ? m : k;
    }
    else if (a[m] < t)
    {
        ans = findFirstWithBinary(a, m + 1, e, t);
    }
    else
    {
        ans = findFirstWithBinary(a, s, m - 1, t);
    }
    return ans;
}
int findLastWithBinary(int *a, int s, int e, int t)
{
    if (s > e)
        return -1;
    int m = s + (e - s) / 2;
    int ans = -1;
    if (a[m] == t)
    {
        int k = findLastWithBinary(a, m + 1, e, t);
        ans = k == -1 ? m : k;
    }
    else if (a[m] < t)
    {
        ans = findLastWithBinary(a, m + 1, e, t);
    }
    else
    {
        ans = findLastWithBinary(a, s, m - 1, t);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int t;
    cin >> t;
    cout << findLastWithBinary(a, 0, n - 1, t) << endl;
    
    return 0;
}
