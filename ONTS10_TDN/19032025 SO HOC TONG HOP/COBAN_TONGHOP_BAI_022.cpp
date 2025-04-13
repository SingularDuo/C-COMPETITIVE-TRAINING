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
    int n, k;
    cin >> n >> k;
    vector<ll> w(n);
    
    for (int i = 0; i < n; i++) 
        cin >> w[i];

    ll day = 0;
    for (int i = 0; i < n; i++) {
        day += (w[i] + k - 1) / k; 
    }

    cout << (day + 1) / 2 << endl; 
}
