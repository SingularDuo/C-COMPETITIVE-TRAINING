#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

vector<ll> pttsnt(ll n) {
    vector<ll> fac; 
    if (n <= 1) return fac;
    if (n % 2 == 0) {
        fac.push_back(2);
        while (n % 2 == 0) {
            n /= 2;
        }
    }
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            fac.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        fac.push_back(n);
    }
    return fac;
}

bool check(const vector<ll>& a, const vector<ll>& b) {
    if (a.size() != b.size()) return false;
    vector<ll> sorted_a = a, sorted_b = b;
    sort(sorted_a.begin(), sorted_a.end());
    sort(sorted_b.begin(), sorted_b.end());
    for (size_t i = 0; i < sorted_a.size(); i++) {
        if (sorted_a[i] != sorted_b[i]) return false;
    }
    return true; // Chuyển từ `false` sang `true` để đúng logic
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll cnt = 0;
    for (ll i = a; i <= b; i++) {
        for (ll j = i + 1; j <= b; j++) {
            vector<ll> factors_a = pttsnt(i);
            vector<ll> factors_b = pttsnt(j);
            if (check(factors_a, factors_b)) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

