#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("GIFTS.inp", "r", stdin);
    freopen("GIFTS.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll res = LLONG_MIN;
    ll i = 0, j = n - 1;

    while (i < j) {
        ll sum = a[i] + a[j];
        if (sum <= x) {
            res = max(res, sum);
            i++;
        } else {
            j--;
        }
    }

    cout << res << endl;
    return 0;
}

/*
6 18
5 3 10 2 4 9
*/
