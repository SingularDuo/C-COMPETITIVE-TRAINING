#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // Processing queries
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--; // Convert to 0-based indexing

        // Tracking mismatches
        vector<int> mismatches;
        for (int i = l; i <= r; i++) {
            if (p[i] != k) {
                mismatches.push_back(p[i]);
            }
        }

        if (mismatches.empty()) {
            cout << 0 << "\n"; // No reordering needed
        } else if (mismatches.size() > 1) {
            cout << -1 << "\n"; // Impossible to reorder for binary search
        } else {
            cout << 1 << "\n"; // Only one reorder needed
        }
    }

    return 0;
}
