#include <bits/stdc++.h>
using namespace std;
long long lcm(long long a, long long b) {
    return (a / __gcd(a, b)) * b;
}
int main() {
    freopen("MA_A6.inp", "r", stdin);
    freopen("MA_A6.out", "w", stdout);

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long lcm_cd = lcm(c, d);
    long long counts = (b / lcm_cd) - ((a - 1) / lcm_cd);

    cout << counts << endl;
    return 0;
}
