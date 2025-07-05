/*
        _.-- ,.--.
      .'   .    '     /
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
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back

signed main() {
    fast;
    int n, k1, k2;
    cin >> n >> k1 >> k2;

    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        pq.push(abs(a[i] - b[i]));
    }

    int k = k1 + k2;
    while (k--) {
        int top = pq.top(); pq.pop();
        if (top > 0) top--;
        else top = 1;
        pq.push(top);
    }

    ll res = 0;
    while (!pq.empty()) {
        ll x = pq.top(); pq.pop();
        res += x * x;
    }

    cout << res << endl;
    return 0;
}
