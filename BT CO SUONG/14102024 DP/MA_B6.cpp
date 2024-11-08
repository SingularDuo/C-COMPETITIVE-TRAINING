#include <bits/stdc++.h>

using namespace std;

void init() {
    freopen("MA_B6.inp", "r", stdin);
    freopen("MA_B6.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isprime(int x) {
    if (x <= 1) {
        return false;
    }
    if (x <= 3) {
        return true;
    }
    if (x % 2 == 0 || x % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

void inp() {
    int n;
    cin >> n;
    int counts = 0;
    for (int i = 5; i <= n; i *= 5) {
        counts += n / i;
    }

    cout << counts;
}

int main() {

    //init();
    inp();
    return 0;
}
