#include <bits/stdc++.h>
using namespace std;
long long lcm(long long a, long long b) {
    return (a / __gcd(a, b)) * b;
}
int main() {
    freopen("MA_A7.inp", "r", stdin);
    freopen("MA_A7.out", "w", stdout);

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    auto div = [](long long x, long long y) {
        return x / y;
    };

    long long lcm_cd = lcm(c, d);
    long long cnt = div(b, c) - div(a - 1, c)
                     + div(b, d) - div(a - 1, d)
                     - div(b, lcm_cd) + div(a - 1, lcm_cd);

    cout << cnt << endl;
    return 0;
}
