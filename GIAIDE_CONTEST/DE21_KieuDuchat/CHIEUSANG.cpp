#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define int long long
const int INF = 1e18;

bool sigma(int d, const vector<ll>& a, const vector<ll>& b) {
    int n = a.size();
    int m = b.size();
    vector<ll> sorted_b = b;
    sort(sorted_b.begin(), sorted_b.end());

    for (int i = 0; i < n; i++) {
        ll lower = a[i] - d;
        ll upper = a[i] + d;
        auto it = lower_bound(sorted_b.begin(), sorted_b.end(), lower);
        if (it == sorted_b.end() || *it > upper) return false;
    }
    return true;
}

signed main() {
    freopen("CHIEUSANG.INP", "r", stdin);
    freopen("CHIEUSANG.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    int mx = LLONG_MIN;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        mx = max(mx, a[i]);
    }
    for(int i = 0; i < m; i++) 
    {
        cin>>b[i];
        mx = max(mx, b[i]);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int left = 0, right = 2*mx, res = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (sigma(mid, a, b)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << res << endl;
}
