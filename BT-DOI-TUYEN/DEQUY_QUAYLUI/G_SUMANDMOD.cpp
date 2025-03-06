#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KInG_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void gen(const vector<int>& arr, vector<int>& currsum, int m) {
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        currsum.push_back(sum % m);
    }
}

KInG_PHAT {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mid = n / 2;
    vector<int> left(a.begin(), a.begin() + mid);
    vector<int> right(a.begin() + mid, a.end());
    vector<int> s1, s2;
    gen(left, s1, m);
    gen(right, s2, m);
    sort(s2.begin(), s2.end());

    int maxx = 0;
    for (int x : s1) {
        auto it = upper_bound(s2.begin(), s2.end(), m - 1 - x);
        if (it != s2.begin()) {
            it--;
            maxx = max(maxx, (x + *it) % m);
        }
    }

    cout << maxx << endl;
    return 0;
}
