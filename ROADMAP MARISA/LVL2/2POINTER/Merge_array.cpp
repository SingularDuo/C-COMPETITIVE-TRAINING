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
    int n;
    cin>>n;
    vector<ll>a(n * 2);
    for(int i = 0; i < a.size();i++)cin>>a[i];
    sort(a.begin(), a.end());
    for(auto i : a)cout<<i<<" ";
}