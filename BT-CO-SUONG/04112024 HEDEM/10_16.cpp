#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("10_16.inp", "r", stdin);
    freopen("10_16.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    ll n;
    cin >> n;
    vector<int> vec;
    while (n > 0) {
        ll a = n % 16;
        vec.push_back(a);
        n /= 16;
    }
    for (ll i = vec.size() - 1; i >= 0; i--) {
        if (vec[i] < 10) {
            cout << vec[i];
        } else {
            cout << char('A' + vec[i] - 10);
        }
    }
    cout << endl;
    return 0;
}
