#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fi first
#define se second
using namespace std;

int main() {
    double x1, x2, v1, v2;
    cin >> x1 >> x2 >> v1 >> v2;

    if (v1 == v2) {
        if (x1 == x2) cout << "0.0000\n";
        else cout << "-1";
    } else {
        double t = (x2 - x1) / (v1 - v2);
        if (t >= 0) cout << fixed << setprecision(4)<<t;
        else cout << "-1";
    }

    return 0;
}
