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

struct Position {
    int layer;
    int stt;

    bool is_left_side(int len) {
        return stt <= len/2;
    }
};

__TOISETHIVOI__ {
    //init();
    int k, x;
    cin >> k >> x;

    Position nowPos = {1, x};
    Position newPos;

    int n = (1 << k);
    int n_layer = 1;
    for(int i =  1; i <= k; i++) {
        if(nowPos.is_left_side(n) == false) {
            newPos.layer = n_layer + nowPos.layer;
            newPos.stt = nowPos.stt - n/2;
        } else {
            newPos.layer = n_layer - nowPos.layer + 1;
            newPos.stt = n/2 - nowPos.stt + 1;
        }

        nowPos = newPos;
        n /= 2;
        n_layer *= 2;
    }

    cout << nowPos.layer << endl;
    return 0;
}
