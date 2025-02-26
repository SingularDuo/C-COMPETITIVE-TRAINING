#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);

    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> cnt(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > 1) {
            res += cnt[i] - 1;
        }
    }

    cout << res;
    return 0;
}
