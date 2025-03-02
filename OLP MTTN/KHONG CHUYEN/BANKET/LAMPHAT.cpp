#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT
{
    fast;
    double n, p;
    cin >> n >> p;
    vector<long double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll k; cin >> k;
    double res = p;
    for (int i = 0; i < n; i++)res *= (1.0 + a[i] / 100.0);
    cout <<fixed<<setprecision(k)<<res<<endl;
}
