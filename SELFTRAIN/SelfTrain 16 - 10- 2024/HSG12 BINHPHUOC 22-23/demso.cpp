#include <bits/stdc++.h>
using namespace std;

void init() {
    freopen("khuvuichoi.inp", "r", stdin);
    freopen("khuvuichoi.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();

    long long a, b, c;
    cin >> a >> b >> c;
    long long check1 = b - a + 1;
    long long check2 = b / c - (a - 1) / c;
    long long check3 = check1 - check2;

    cout << check3<< endl;
    return 0;
}
