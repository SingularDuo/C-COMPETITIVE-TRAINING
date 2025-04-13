#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define MIN LLONG_MIN
#define MAX LLONG_MAX

KING_PHAT {
    fast;
    int n;
    cin >> n;
    vector<ll> a(n), f(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[i] = (i == 0) ? a[i] : f[i - 1] + a[i];
    }

    ll maxx = MIN;
    for (int mid = 0; mid < n; mid++) {
        ll left_val = f[mid];
        ll right_val = (mid < n - 1) ? f[n - 1] - f[mid] : 0;

        ll ex1 = -left_val + right_val;
        ll ex2 = -right_val + left_val;
        ll curr = max(ex1, ex2);
        maxx = max(maxx, curr);
    }

    cout << maxx << endl;
}
