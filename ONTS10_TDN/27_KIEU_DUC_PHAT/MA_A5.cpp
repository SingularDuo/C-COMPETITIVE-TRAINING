#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("MA_A5.inp", "r", stdin);
    freopen("MA_A5.out", "w", stdout);

    long long a, b, c;
    cin >> a >> b >> c;

    long long counts = (b / c) - ((a - 1) / c);

    cout << counts << endl;
    return 0;
}
