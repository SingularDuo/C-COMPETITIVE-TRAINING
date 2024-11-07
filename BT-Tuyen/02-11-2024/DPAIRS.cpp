#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++) cin >> vec[i];
    map<ll, ll> freq;
    for (ll c : vec) freq[c]++;
    ll cnt = 0;
    for (auto &entry : freq) {
        ll num = entry.first;
        ll count = entry.second;
        
        ll target = num - k;
        
        if (freq.count(target)) {
            if (k == 0) {
                cnt += (count * (count - 1)) / 2;
            } else {
                cnt += count * freq[target];
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
