#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main() {
    freopen("EVENSUM.INP", "r", stdin);
    freopen("EVENSUM.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1, 0);
        vector<ll> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            prefix[i] = prefix[i - 1] + a[i];
        }

        ll res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if ((prefix[j] - prefix[i - 1]) % 2 == 0) {
                    res++;
                }
            }
        }

        cout << res << endl;
    }
}
