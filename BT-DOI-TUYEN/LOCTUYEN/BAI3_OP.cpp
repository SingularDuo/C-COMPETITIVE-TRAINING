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

map<string, vector<ll>> index;

void itgroup(ll a, ll b) {
    for (int i = a; i <= b; i++) {
        vector<ll> factor = factorize(i);
        string s1 = "";
        set<ll> luu;
        for (int j = 0; j < factor.size(); j++) {
            luu.insert(factor[j]);
        }

        for (auto x : luu) {
            s1 = s1 + to_string(x);
        }
        
        if (luu.size() >= 2) {
            for (int l = 1; l < s1.size(); l++) {
                if (isdigit(s1[l])) {
                    s1.insert(s1.begin() + l, ' ');
                    l++;
                }
            }
        }
        index[s1].push_back(i);
    }
}

int main() {
    ll a, b;
    cin >> a >> b;
    itgroup(a, b);
    ll cnt = 0;
    for (auto i : index) {
        for (auto num : i.second) {
        }
        ll curr = i.second.size();
        cnt += (curr*(curr-1))/2;
    }
    cout<<cnt;
    return 0;
}
