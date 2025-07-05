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
const int InF = 2 * 1e18;

void init() {
  freopen("TRONGSO.inp", "r", stdin);
  freopen("TRONGSO.out", "w", stdout);
  fast;
}
double calculate_weight(const string& s) {
    int sum = 0;
    int cnt = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            sum += ch - '0';
            cnt++;
        }
    }
    //cout<<s<<" "<<sum<<" "<<cnt<<endl;
    if (cnt == 0) return 0.0;
    return static_cast<double>(sum) / cnt;
}
__TOISETHIVOI__ {
    init();
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    double maxx = -1.0;
    string best_string;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        double weight = calculate_weight(s);
        if (weight > maxx) {
            maxx = weight;
            best_string = s;
        }
    }

    cout << best_string;
    return 0;
}
