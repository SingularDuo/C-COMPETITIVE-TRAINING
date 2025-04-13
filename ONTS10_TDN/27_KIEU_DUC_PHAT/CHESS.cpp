#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
void init()
{
    freopen("CHESS.INP", "r", stdin);
    freopen("CHESS.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool scp(int x) {
    int y = sqrt(x);
    return y * y == x;
}

signed main() {
    init();
    int n, m;
    cin >> n >> m;
    int maxx = n + m;

    while (!scp(maxx)) {
        maxx--;
    }

    cout << (int)sqrt(maxx) << endl;
    return 0;
}
