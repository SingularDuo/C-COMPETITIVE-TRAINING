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
 * Generated on: 2025-05-16 18:07:25
*/

#include <bits/stdc++.h>
using namespace std;

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

const int MOD = 11;
const int INF = 2 * 1e18;

void init() {
      freopen("Cau2a.inp", "r", stdin);
      freopen("Cau2a.out", "w", stdout);
      fast;
}

bool scp(int x)
{
    int a = round(sqrt(x));
    return a * a == x;
}
__TOISETHIVOI__ {
    init();
    string s; cin>>s;
    ll res = 0;
    for(int i = 0; i < s.size(); i++)
    {
        res += (s[i] - '0');
    }
    if(scp(res))cout<<res;
    else cout<<res%MOD;
    return 0;
}