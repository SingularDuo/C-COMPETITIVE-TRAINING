#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a)); 

    int l = 0, res = n;
    for (int r = 2; r < n; r++) {
        while (l < r - 1 && a[l] + a[l + 1] <= a[r]) l++;
        res = min(res, n - (r - l + 1));
    }

    cout << res;
}

signed main() {
    fast;
    int t;
    cin >> t; 
    while (t--) {
        sol(); 
        cout << endl;
    }
    return 0;
}
