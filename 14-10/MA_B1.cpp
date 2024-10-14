#include <bits/stdc++.h>
using namespace std;
void init() {
    freopen("MA_B1.inp", "r", stdin);
    freopen("MA_B1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int tim(long long n) {
    int count = 0;

    if (n % 2 == 0) {
        count++;
        while (n % 2 == 0) {
            n /= 2;
        }
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            count++;
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    if (n > 1) {
        count++;
    }

    return count;
}

int main() {
    init();
    long long N;
    cin >> N;
    cout <<tim(N) << endl;
    return 0;
}
