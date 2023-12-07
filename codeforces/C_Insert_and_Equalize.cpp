#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define mod2 998244353
#define endl '\n'
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define print(x)              \
    {                         \
        for (auto v : x)      \
        {                     \
            cout << v << ' '; \
        }                     \
        cout << endl;         \
    }
#define printp(x)                                      \
    {                                                  \
        for (auto v : x)                               \
        {                                              \
            cout << v.first << ':' << v.second << ' '; \
        }                                              \
        cout << endl;                                  \
    }                                                  \
    ,
#define printv(x)        \
    {                    \
        for (auto v : x) \
        {                \
            print(v)     \
        }                \
    }

void solve() {
      int n;
        cin >> n;

        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        if (n == 1)
        {
            cout << 1 << endl;
            return;
        }

        sort(all(v));
        vector<int> diff(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            diff[i] = v[n - 1] - v[i];
        }

        // we got our x
        int d = v[1] - v[0];
        for (auto x : diff)
        {
            d = __gcd(d, x);
        }
        int ans = 0;
        // now we have to insert a number in array
        for (auto x : diff)
        {
            ans += (x / d);
        }

        int last = v[n - 1] - d;
        int j = n - 2;
        while (j >= 0 && last == v[j])
        {
            last -= d;
            j--;
        }

        if (j >= 0)
        {
            ans += (v[n - 1] - last) / d;
        }
        else
        {
            ans += n;
        }

        cout << ans << endl;
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