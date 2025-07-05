#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 1005;

int freq[MAX];

//to hop vui vl
int C(int n, int k) {
    if (n < k) return 0;
    if (k == 2) return n * (n - 1) / 2;
    if (k == 3) return n * (n - 1) * (n - 2) / 6;
    return 0;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        freq[x]++;
    }

    int res = 0;
    for (int x = 0; x <= 1000; x++) {
        for (int y = x; y <= 1000; y++) {
            int z = x + y;
            if (z > 1000) continue;
            if (!freq[x] || !freq[y] || !freq[z]) continue;

            if (x == y && y == z) {
                // (x, x, x)
                res += C(freq[x], 3);
            }
            else if (x == y && y != z) {
                // (x, x, z)
                res += C(freq[x], 2) * freq[z];
            }
            else if (x < y && y == z) {
                // (x, y, y)
                res += freq[x] * C(freq[y], 2);
            }
            else if (x < y && z != x && z != y) {
                // (x, y, z)
                res += freq[x] * freq[y] * freq[z];
            }
        }
    }

    cout << res << '\n';
}
