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
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int bal = 0;
  for (int i = 1; i + 1 < n; i++) {
    if (s[i] == '(') bal++;
    else bal--;
    if (bal < 0) {
      cout << "YES\n";
      return;
    }
  }
  if (bal == 0) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
void init() {
  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);
  fast;
}

__TOISETHIVOI__ {
    //init();
    int t; cin>>t;
    while(t--)
    {
        solve();
    }


    return 0;
}
