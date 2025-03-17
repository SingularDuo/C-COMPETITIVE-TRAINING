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
    int n, x;
    cin>>n>>x;
    vector<ll> price(n), page(n);
    for(int i = 0; i < n;i++)cin>>price[i];
    for(int i = 0; i < n; i++) cin>>page[i];
    vector<ll> dp(n+1); // so phan tu it nhat can de dat duoc tong i
    for(int i = 0)
}