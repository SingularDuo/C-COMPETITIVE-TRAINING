#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"

const int SUB1 = 5 * 1e3;

signed main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n <= SUB1) {
        ll res = 0;
        set<pair<int, int>> appear;
        for (int i = 0; i < n; i++) {
            int curr1 = 0, curr2 = 0;
            for (int j = i; j < n; j++) {
                if (a[j] == 1) curr1++;
                else curr2++;
                if (curr1 == curr2 && !appear.count({i, j})) {
                    res++;
                    appear.insert({i, j});
                }
            }
        }
        cout << res;
        return 0;
    }


    vector<int> pref(n + 1, 0);
    map<int, int> cnt;
    cnt[0] = 1; 
    int res = 0;

    for (int i = 1; i <= n; i++) {
        int val = (a[i - 1] == 1 ? 1 : -1);
        pref[i] = pref[i - 1] + val;
        cnt[pref[i]]++;
        res += (cnt[pref[i]] * (cnt[pref[i]] - 1))/2;
    }

    cout << res;
}
