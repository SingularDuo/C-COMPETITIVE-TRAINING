#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, ll> cnt;
    for (ll i = 0; i < n; ++i)cin >> a[i];
    for (ll i = 0; i < n; ++i) {
        ll current = -a[i];
        if (cnt.count(current)!=0) {
            cout << cnt[current] + 1 <<" "<< i + 1 << endl;
            return 0;
        }
        cnt[a[i]] = i;
    }
    cout << "-1 -1" << endl;
    return 0;
}
