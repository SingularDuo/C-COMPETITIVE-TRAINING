#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}
int countMultiples(int n, int a, int b, int c) {
    long long ab = lcm(a, b);
    long long ac = lcm(a, c);
    long long bc = lcm(b, c);
    long long abc = lcm(ab, c);
    long long countAB = n / ab;
    long long countAC = n / ac;
    long long countBC = n / bc;
    long long countABC = n / abc;
    return countAB + countAC + countBC - 3 * countABC;
}
int main() {
    int n, a, b, c;
    while (cin >> n >> a >> b >> c) {
        cout << countMultiples(n, a, b, c) << endl;
    }
    return 0;
}
