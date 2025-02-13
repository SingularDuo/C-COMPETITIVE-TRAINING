#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

vector<ll> factorize(ll n) {
    vector<ll> res;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n > 1) res.push_back(n);
    return res;
}

map<string, vector<ll>> I;

void itgroup(ll a, ll b) {
    for (int i = a; i <= b; i++) {
        vector<ll> factor = factorize(i);
        string s1 = "";
        set<ll> luu;
        for (int j = 0; j < factor.size(); j++) {
            luu.insert(factor[j]);
        }
        for (auto x : luu) {
            s1 += to_string(x);
        }
        if (luu.size() >= 2) {
            string spaced_s1 = "";
            for (int l = 0; l < luu.size(); l++) {
                spaced_s1 += to_string(*next(luu.begin(), l)) + ' ';
            }
            s1 = spaced_s1;
        }
        I[s1].push_back(i);
    }
}

int main() {
    ll a, b;
    cin >> a >> b;
    itgroup(a, b);
    ll cnt = 0;
    for (auto i : I) {
        for (auto num : i.second) {
        }
        ll curr = i.second.size();
        cnt += (curr*(curr-1))/2;
    }
    cout << cnt;
    return 0;
}
