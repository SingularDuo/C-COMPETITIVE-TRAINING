#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, p;
        cin >> n >> k >> p;
        
        if (k < -n * p || k > n * p) {
            cout << -1 << endl;
            continue;
        }
        int required_sum = abs(k);
        if (required_sum % p == 0) {
            cout << required_sum / p << endl;
        } else {
            cout << required_sum / p + 1 << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
