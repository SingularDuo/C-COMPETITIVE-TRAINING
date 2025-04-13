#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool found = false;
        for (int i = 0; i < n; i++) {
            int need1 = 1, need0 = 3, need2 = 2, need3 = 1, need5 = 1;
            for (int j = i; j < n; j++) {
                if (a[j] == 1) need1--;
                else if (a[j] == 0) need0--;
                else if (a[j] == 2) need2--;
                else if (a[j] == 3) need3--;
                else if (a[j] == 5) need5--;

                if (need1 <= 0 && need0 <= 0 && need2 <= 0 && need3 <= 0 && need5 <= 0) {
                    cout << j + 1 << endl;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) cout << 0 << endl;
    }
}
