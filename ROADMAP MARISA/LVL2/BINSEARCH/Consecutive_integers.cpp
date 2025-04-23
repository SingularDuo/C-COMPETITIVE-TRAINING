
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
 
    int res = INT_MAX;
    int l = 0, r = 0;
 
    while (r < a.size()) {
        if (a[r] - a[l] <= n - 1) {
            int current = n - (r - l + 1);
            res = min(res, current);
            r++;
        } else {
            l++;
        }
    }
 
    cout << res << "\n";
    return 0;
}