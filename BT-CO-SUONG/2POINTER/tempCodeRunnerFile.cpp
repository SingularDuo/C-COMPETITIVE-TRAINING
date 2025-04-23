#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
int n, k;
vector<ll> a;
KING_PHAT
{
    fast;
    cin>>n>>k;
    a.resize(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    int l = 0, r = k - 1;
    
    int sum =0;
    for(int i = 0; i < k; i++)sum+=a[i];
    int res = sum;
    while(r < n)
    {
        r++;
        sum = sum + a[r] - a[l];
        l++;
        res = max(res, sum);
    }
    cout<<res;

}