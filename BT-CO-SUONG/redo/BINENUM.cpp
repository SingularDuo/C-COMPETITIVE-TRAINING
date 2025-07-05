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

const int MAXPOW = 17;
ll binpow(int a, int b)
{
    int res =1;
    while(b > 0)
    {
        if(b % 2 == 1)res *= a;
        a*=a;
        b /= 2;
    }
    return res;
}
ll CountingTimeToZero(int n)
{
    ll res = 0;
    while(n > 0)
    {
        n -= binpow(2, (ll)log2(n));
        res++;
    }
    return res;
}
__TOISETHIVOI__ {
    //init();
    int n, x; cin>>n>>x;
    int res = 0;
    for(int i = 0; i <= n; i++)
    {

        if(CountingTimeToZero(i) == x)cout<<i<<" ";
    }
    return 0;
}
