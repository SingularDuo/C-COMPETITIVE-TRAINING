#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
bool check_scp(ll n) {
    ll a = sqrt(n);
    return a * a == n;
}
ll find_diff(const vector<vector<ll>>& a) {
    map<ll, ll> count;

    for (const auto& row : a) {
        for (ll val : row) {
            if (val != 0) {
                count[val]++;
            }
        }
    }
    ll curr = 0, diff = -1;
    for (const auto& [k, val] : count) {
        if (val > curr) {
            curr = val;
            diff = k;
        }
    }

    return diff;
}
vector<vector<ll>> rotate(const vector<vector<ll>>& a, int n) {
    vector<vector<ll>> rotated(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[i][j] = a[n - i - 1][n - j - 1];
        }
    }
    return rotated;
}

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            ll b;
            cin >> b;

            if (b == 0) {
                a[i][j] = 0;
                continue;
            }

            if (check_scp(b)) {
                a[i][j] = sqrt(b) + 1;
            } else {
                a[i][j] = b;
            }
        }
    }
    ll diff = find_diff(a);
    vector<vector<ll>> x = rotate(a, n);
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            if (x[i][j] == 0) {
                if (j > 0) {
                    x[i][j] = x[i][j - 1] + diff;
                } else if (i > 0) {
                    x[i][j] = x[i - 1][n - 1] + diff;
                }
                if (check_scp(x[i][j])) {
                    x[i][j] = sqrt(x[i][j]) + 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



/*
3
0 10 5
11 0 20
15 10 5
*/