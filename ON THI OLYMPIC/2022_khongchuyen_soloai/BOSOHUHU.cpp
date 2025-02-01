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

bool scp(ll n) {
    ll s = sqrt(n);
    return s * s == n;
}

void kequalto2(vector<bool>& chinhphuong, map<int, vector<ll>>& factored, ll n) {
    for (auto& i : factored) {
        if (i.second.size() > 2) {
            ll newVal = 1;
            size_t j = 0;
            while (i.second.size() > 2) {
                newVal *= i.second[j];
                i.second.erase(i.second.begin());
            }
            i.second.push_back(newVal);
        }
    }
    ll cnt = 0;
    for (auto& i : factored) {
        bool ok = true;
        for (auto& j : i.second) {
            if (j > n) ok = false;
        }
        if (ok && i.second.size() == 2) cnt++;
    }
    cout << cnt << endl;
}

int main() {
    ll n, k;
    cin >> n >> k;
    if (k == 1) { // Test case k = 1
        ll cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (scp(i)) cnt++;
        }
        cout << cnt << endl;
        return 0;
    }

    vector<bool> chinhphuong(1e5);
    map<int, vector<ll>> factored;
    for (int i = 2; i <= 1e5; i++) {
        if (scp(i)) {
            chinhphuong[i] = true;
            factored[i] = factorize(i);
        }
    }

    if (k == 2) {
        kequalto2(chinhphuong, factored, n);
    }

    return 0;
}
