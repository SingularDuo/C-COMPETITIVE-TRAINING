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
    Kduckp       |   |./'
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> freq;
    unordered_set<int> st;

    int max_val = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
        st.insert(a[i]);
        max_val = max(max_val, a[i]);
    }

    int ans = 0;

    //max(a[i]) ≤ 5000 
    if (max_val <= 5000) {
        for (int i = 0; i < n; i++) {
            int ak = a[i];
            for (int d = 1; d <= 5000; d++) {
                if (st.count(ak - d) && st.count(ak + d)) {
                    ans++;
                    break;
                }
            }
        }
    }

    //max(a[i]) > 5000
    else {
        for (int k = 0; k < n; k++) {
            int ak = a[k];
            bool ok = false;
            for (auto& it : freq) {
                int ai = it.fi;
                int aj = 2 * ak - ai;

                if (aj == ai) {
                    if (freq[ai] >= 2) {
                        ok = true;
                        break;
                    }
                } else if (freq.count(aj)) {
                    ok = true;
                    break;
                }
            }
            if (ok) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
