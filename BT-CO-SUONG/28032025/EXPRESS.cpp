#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("EXPRESS.INP", "r", stdin);
    freopen("EXPRESS.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    ll res = LLONG_MIN;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1 ; j < n - 1; j++) {
            if(j == i +1)
            {
                ll val = a[i]*a[i+1]*a[i+2];
                ll sub_sum = sum - a[i] - a[i+1] - a[i+2] + val;
                res = max(res, sub_sum);
                continue;
            }
            ll val = a[i] * a[i + 1] + a[j] * a[j + 1];
            ll sub_sum = sum - (a[i] + a[i + 1] + a[j] + a[j + 1]) + val;
            res = max(res, sub_sum);
        }
    }

    cout << res;
}
