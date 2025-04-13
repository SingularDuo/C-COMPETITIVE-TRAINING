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
    int l, r;
    cin >> l >> r;

    ll soluong = r - l + 1;

    ll tong = (r + l) * soluong / 2;
    ll a1 = (l % 13 == 0) ? l : (l / 13 + 1) * 13; 
    ll an = (r % 13 == 0) ? r : (r / 13) * 13; 

    if (a1 <= an) {
        ll n = (an - a1) / 13 + 1; 
        ll tong_boi_13 = (a1 + an) * n / 2; 
        tong -= tong_boi_13; 
    }

    cout << tong;
}
