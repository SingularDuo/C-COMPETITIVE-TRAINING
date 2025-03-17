#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl "\n"

void init() {
    freopen("SQRNUM.inp", "r", stdin);
    freopen("SQRNUM.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool scp(ll x) {
    if (x < 0) return false;
    ll k = sqrt(x);
    return k * k == x;
}

void factorize(int n, unordered_map<int, int>& factors) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) factors[n]++;
}

signed main() {
    //init();
    int n;
    cin >> n;
    vector<int> a(n);
    bool sub1 = false;
    int check = 1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        check *= a[i];
        if (check < 0 || check > 1e18) sub1 = false; 
    }

    if (sub1) { 
        ll res = 1;
        for (int i = 0; i < n; i++) {
            res *= a[i];
            if (scp(res)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        return 0;
    }
    unordered_map<int, int> prime_factors;
    for (int i = 0; i < n; i++) {
        factorize(abs(a[i]), prime_factors);
        bool isSquare = true;
        for (auto& p : prime_factors) {
            if (p.second % 2 != 0) {
                isSquare = false;
                cout<<"NO"<<endl;
                break;
            }
        }
        if (isSquare) cout << "YES" << endl;

    }

    return 0;
}
