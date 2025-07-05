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
  freopen("XTS.inp", "r", stdin);
  freopen("XTS.out", "w", stdout);
  fast;
}
void Sol(){
    int n,m,k;
    char c1,c2;
    cin>>n>>c1>>m>>c2>>k;
    if(c1=='R'){
        if(k >= n)cout<<n;
        else cout<<k;
    }
    else if(c2=='R'){
        if(k >= n)cout<<k-n;
        else cout<<0;
    }
}
__TOISETHIVOI__ {
    init();
    Sol();
    return 0;
}
