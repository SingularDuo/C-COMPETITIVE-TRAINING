/*
        _.-- ,.--.
      .'   .'     /
       @       |'..--------._
     /      \._/              '.
    /  .-.-                     \
   (  /    \                     \
   \      '.                  | #
    \       \   -.           /
     :\       |    )._____.'   \
      "       |   /  \  |  \    )
    Kduckp       |   |./'  :__ \.-'
              '--'
*/
/*
 * Author: Kduckp
 * Generated on: 2025-05-30 23:03:47
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
#define fi first
#define se second
#define si size()
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define pb push_back
#define __TOISETHIVOI__ signed main()

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;

void init() {
  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);
  fast;
}

__TOISETHIVOI__ {
    //init();
    int n; cin>>n;
    vector<ll> a(n);
    int maxx = LLONG_MIN, pos = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i] >= maxx)
        {
            maxx = a[i];
            pos = i;
        }
    }
    vector<ll> mxR(n);
    mxR[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--)mxR[i] = max(mxR[i+1], a[i]);
    int q; cin>>q;
    vector<int> query(q);
    for(int i = 0; i < q; i++)cin>>query[i];
    vector<ll> pre(n);
    ll pf = 0;
    for(int i = n-1; i >= 0;i--)
    {
        pre[i] = mxR[i] - a[i] ;
        if(i + 1 < n)pre[i] += pre[i+1];

    }
    //for(auto& i : pre)cout<<i<<endl;
    for(int i = 0; i < q; i++)
    {
        int start = query[i] - 1;
        cout<<pre[start]<<endl;
    }
    return 0;
}
