#include <iostream>
using namespace std;

#define int long long
void solve()
{

    int n, p, a, b;
    cin >> n >> p >> a >> b;

    int low = 0, high = n;
    int ans = n;

    while (low <= high)
    {
        int m = (low + high) / 2;
        int x = min((n - 1) / 7 + 1, m * 2);

        x = m * a + x * b;
        if (x >= p)
        {
            ans = m;
            high = m - 1;
        }
        else
        {
            low = m + 1;
        }
    }

    cout << n - ans << endl;
}

signed main()
{

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
