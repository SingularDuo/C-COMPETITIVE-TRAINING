#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KInG_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
const int n = 2e5 + 5; 
int a[n], b[n], ne[n];
void solve()
{
    int n, m, pos = 0;
    cin>>n>>m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--)
    {
        b[a[i]] = i;
        if (b[a[i] + 1]) ne[i] = b[a[i] + 1];
        if (a[i] == 1) pos = i;
    }
    for (int i = 1; i <= m; i++) b[a[i]] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!b[a[i]]) b[a[i]] = i;
        if (!ne[i]) ne[i] = b[a[i] + 1];
    }
    int ans = 0;
    cout<<endl;
    for (int i = 1; i <= m; i++)
    {
        if (ne[pos] < pos) ans++;
        pos = ne[pos];
    }
    cout << ans << endl;
}

KInG_PHAT
{
    fast;
    solve();
    return 0;
}