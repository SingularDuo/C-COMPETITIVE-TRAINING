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
  freopen("DT.inp", "r", stdin);
  freopen("DT.out", "w", stdout);
  fast;
}
void Sol(){
    int n,d,k;
    cin>>n>>d>>k;
    d%=n;
    if(d==0){
        cout<<k;
        return;
    }
    vector<int>a(1,1);
    int i=0;
    while(k!=i){
        i++;
        a.push_back(a.back()+d);
        if(a.back()>n){
            a.back()%=n;
        }
    }
    int as=0;
    for(auto &i:a){
        as+=i;
    }
    cout<<as;
}
__TOISETHIVOI__ {
    init();
    Sol();

    return 0;
}
