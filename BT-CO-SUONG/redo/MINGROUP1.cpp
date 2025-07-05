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
    //init()
;    int n, cnt = 0; cin>>n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
      cin>>a[i];
      if(a[i] == 1)
      {
        cnt++;
      }
    }
    vector<ll> f(n);
    if(a[0] == 0)f[0] = 1;
    else f[0] = 0;
    for(int i = 1; i < n; i++)
    {
      f[i] = f[i-1];
      if(a[i] == 0)f[i]++;
    }
    ll res =  LLONG_MAX;
    for(int i =0; i <= n - cnt; i++)
    {
      ll v = f[i + cnt] - f[i];
      res = min(res, v);
    }
    if(res == LLONG_MAX)
    {
      cout<<-1;
    }
    cout<<res;

    return 0;
}
