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
 * Author: Kduckps
 * Generated on: 2025-05-13 22:32:10
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
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

vector<ll> value;
void gen_value(string s) {
    ll n = s.size();
    value.resize(n);
    
    if(s[0] == s[1])value[0] = 1;
    else value[0] = 0;    
    
    
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            value[i] = value[i - 1] + 1;
        } else {
            value[i] = value[i - 1];  
        }
    }
}

__TOISETHIVOI__ {
    //init();
    string s; cin>>s;
    gen_value(s);
    //for(auto& i : value)cout<<i<<" ";
    cout<<endl;
    int q; cin>>q;
    while(q--)
    {
        int a, b; cin>>a>>b;
        a--;
        b--;
        cout<<value[b] - value[a]<<endl;
    }
    return 0;

}