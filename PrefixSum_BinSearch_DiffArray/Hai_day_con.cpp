#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    faster;
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> mark(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mark[i] = 0;
    }
    vector<ll> f(n + 1, 0);
    for (int i = 0; i < n; i++) f[i + 1] = f[i] + a[i];
    
    if (k == 1) {
        sort(a.begin(), a.end());
        ll maxx = a[n - 1];
        ll minn = a[0];
        cout << maxx - minn;
        return 0;
    }
    
    //find max
    ll maxx = LLONG_MIN;
    for (int i = 0; i + k <= n; i++)
    {
        ll val = f[i + k] - f[i];
        if (maxx < val)
        {
            maxx = val;
            memset(&mark[0], -1, n * sizeof(ll));
            memset(&mark[i], 0, k * sizeof(ll));
        }
    }
    //find min
    ll minn = LLONG_MAX;
    for (int i = 0; i + k <= n; i++)
    {
        ll val = f[i + k] - f[i];
        if (minn > val)
        {
            bool good = true;
            for (int j = i; j < i + k; j++)
            {
                if (mark[j] == 0) good = false;
            }
            if (good) minn = val; 
        }
    }

    cout << maxx - minn;;
}
