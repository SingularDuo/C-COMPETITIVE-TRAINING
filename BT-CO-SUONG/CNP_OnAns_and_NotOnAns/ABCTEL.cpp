#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int maxn = 1e6;
vector<ll> a(maxn, 0), f(maxn, 0), frad(maxn, 0);
void init()
{
    freopen("ABCTEL.INP", "r",stdin);
    freopen("ABCTEL.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
signed main()
{
    init();
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int val, idx;
        cin >> val >> idx;
        a[idx] = val;
    }
    for (int i = 1; i <= maxn; i++)f[i] = f[i - 1] + a[i];
    for (int i = 1; i <= maxn; i++)
    {
        int left = max(1LL, i - k);
        int right = min(maxn, i + k);
        frad[i] = f[right] - f[left - 1];
    }
    sort(frad.begin(), frad.end(), greater<ll>());
    cout<<frad[0];
    return 0;
}

/*
4 3
4 7
10 15
2 2
5 1
*/
