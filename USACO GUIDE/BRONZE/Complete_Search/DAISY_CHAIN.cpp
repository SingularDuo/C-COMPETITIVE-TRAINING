#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<ll> a, f;

int main() {
    cin >> n;
    a.resize(n);
    f.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            f[i] = a[i];
        } else {
            f[i] = f[i - 1] + a[i];
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ll sum;
            if (i == 0) {
                sum = f[j];
            } else {
                sum = f[j] - f[i - 1];
            }

            ll distance = j - i + 1;
            if (sum % distance != 0) continue;

            ll avg = sum / distance;
            for (int k = i; k <= j; k++) {
                if (a[k] == avg) {
                    res++;
                    break;
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}
