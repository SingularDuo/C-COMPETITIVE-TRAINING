#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, a, b, c, d;
    cin >> x >> a >> b >> c >> d;
    int res = 0;

    if (x <= 50) {
        res = x * a;
    } else if (x <= 100) {
        res = 50 * a + (x - 50) * b;
    } else if (x <= 150) {
        res = 50 * a + 50 * b + (x - 100) * c;
    } else {
        res = 50 * a + 50 * b + 50 * c + (x - 150) * d;
    }

    cout << res;
    return 0;
}
