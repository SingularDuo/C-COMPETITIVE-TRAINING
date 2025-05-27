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
 * Generated on: 2025-05-14 13:39:11
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
    freopen("BAI2.inp", "r", stdin);
    freopen("BAI2.out", "w", stdout);
    fast;
}

__TOISETHIVOI__ {
     init();

    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    string res = "";
    for(auto& str : s) {
        map<char, int> cnt;
        for(int j = 0; j < str.size(); j++) {
            cnt[str[j]]++;
        }

        ll highest_freq = LLONG_MIN;
        char best_char = '\0';
        for(auto& p : cnt) {
            if(p.second > highest_freq) {
                highest_freq = p.second;
                best_char = p.first;
            }
        }
        res += best_char;
    }

    cout << res;
    return 0;
}