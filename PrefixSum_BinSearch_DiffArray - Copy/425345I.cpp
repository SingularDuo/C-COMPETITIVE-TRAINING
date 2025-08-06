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
 * Generated on: 2025-07-05 20:19:40
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
#define vec(a,b,c,d) vector<a> b(c,d)

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;

void init() {
  //freopen("input.inp", "r", stdin);
  //freopen("output.out", "w", stdout);
  fast;
}

__TOISETHIVOI__ {
    init();
    int n; cin>>n;
    vec(int,a,n,0);
    for(int i = 0; i < n; i++)cin>>a[i];
    int q; cin>>q;
    while (q--) {
        int x;
        cin >> x;

        auto it1 = lower_bound(a.begin(), a.end(), x);
        auto it2 = upper_bound(a.begin(), a.end(), x);

        if (it1 == a.end() || *it1 != x) {
            cout << "-1 -1" << endl;
        } else {
            int first = distance(a.begin(), it1) + 1;
            int last = distance(a.begin(), it2) ; 
            cout << first << " " << last << endl;
        }
    }

    return 0;
}