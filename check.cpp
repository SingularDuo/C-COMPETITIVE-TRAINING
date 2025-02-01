#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll countdiv3(const vector<ll>& dongdu) {
    map<ll, ll> cnt = {{0, 0}, {1, 0}, {2, 0}};
    ll res = 0;
    for (ll num : dongdu) {
        cnt[num]++;
    }
    res += (cnt[0] * (cnt[0] - 1)) / 2;  
    res += cnt[1] * cnt[2];             
    return res;
}

void sol() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> dongdu(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dongdu[i] = a[i] % 3;
    }
    ll res = countdiv3(dongdu);
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sol();
    return 0;
}
