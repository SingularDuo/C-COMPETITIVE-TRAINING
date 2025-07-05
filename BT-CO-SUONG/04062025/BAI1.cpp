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
#define fi first
#define se second
#define si size()
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define pb push_back

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;

void init() {
    freopen("BAI1.inp", "r", stdin);
    freopen("BAI1.out", "w", stdout);
    fast;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int sum = 0;
    int freq[10] = {};

    for (char c : s) {
        int d = c - '0';
        freq[d]++;
        sum += d;
    }

    if (freq[0] == 0 || sum % 3 != 0) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 9; i >= 0; i--)
        for (int j = 0; j < freq[i]; j++)
            cout << i;
    cout << '\n';

    return 0;
}
