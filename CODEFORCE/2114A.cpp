#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll x = stoll(s);

        // integer square‐root with rounding
        ll R = ll(sqrtl(x) + 0.5L);
        if (R*R != x) {
            cout << -1 << "\n";
        } else {
            // one valid choice is (0, R)
            cout << 0 << " " << R << "\n";
        }
    }
    return 0;
}
