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
    vector<ll> a(n);
    int minn = LLONG_MAX;
    int max = maxxxx();
    for(int i =0; i < n; i++)
    {
        cin>>a[i];
        minn = min(minn, a[i]);
    }
    sort(a.begin(), a.end());
    vector<ll> sorted_A(n);
    for(int i = 0; i < n; i++)
    {
        sorted_A[i] = minn;
        minn++;
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != sorted_A[i])res++;
    }
    cout<<res;
}
// count()
// 6 6 7 7 8 9 10 11 11
// 6 7 8 9 10 11 12 13 14 day kq
// 