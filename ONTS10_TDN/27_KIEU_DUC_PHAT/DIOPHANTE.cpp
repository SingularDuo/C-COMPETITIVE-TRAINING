#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"

void init()
{
    freopen("DIOPHANTE.INP", "r", stdin);
    freopen("DIOPHANTE.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

signed main() {
    init();
    int a, b, c;
    cin >> a >> b >> c;

    int counts = 0;
    for (int x = 1; x <= c / a; x++) {
        int remain = c - x * a;
        if (remain % b == 0) {
            int y = remain / b;
            if (y > 0) counts++;
        }
    }

    cout << counts << endl;
}
