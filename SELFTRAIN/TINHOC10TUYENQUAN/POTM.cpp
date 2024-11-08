#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
ll th1(const vector<ll>& a, int k, int x) {
    vector<ll> sub(a.begin(), a.begin() + x); 
    sort(sub.begin(), sub.end()); 
    ll cnt = 0;
    for (int i = 0; i < k; i++) {
        cnt += sub[i]; 
    }
    return cnt;
}
ll th2(const vector<ll>& a, int k, int x) {
    vector<ll> sub(a.begin(), a.begin() + x); 
    sort(sub.begin(), sub.end(), greater<ll>());
    ll cnt = 0;
    for (int i = 0; i < k; i++) {
        cnt += sub[i]; 
    }
    return cnt; 
}

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++)cin >> vec[i]; 
    for (int i = 0; i < q; i++) {
        ll t, x, k;
        cin >> t >> x >> k; 
        if (t == 1) cout << th2(vec, k, x) << endl; 
        else if (t == 0)cout << th1(vec, k, x) << endl;
    }
    return 0;
}
