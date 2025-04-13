#include <bits/stdc++.h>
using namespace std;

#define int long long
void init(){
    freopen("HCN.INP", "r", stdin);
    freopen("HCN.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
signed main() {
    init();
    int n;
    cin >> n;

    int x1[105], y1[105], x2[105], y2[105];

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    int max_chain = 0;

    for (int i = 0; i < n; i++) {
        int chain_length = 1;
        int lx1 = x1[i], ly1 = y1[i], lx2 = x2[i], ly2 = y2[i];
        int area1 = (lx2 - lx1) * (ly2 - ly1);

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            int nx1 = x1[j], ny1 = y1[j], nx2 = x2[j], ny2 = y2[j];
            int area2 = (nx2 - nx1) * (ny2 - ny1);

            if (nx1 <= lx1 && ny1 <= ly1 && nx2 >= lx2 && ny2 >= ly2 && area2 > area1) {
                chain_length++;
                lx1 = nx1, ly1 = ny1, lx2 = nx2, ly2 = ny2;
                area1 = area2;
            }
        }

        max_chain = max(max_chain, chain_length);
    }

    cout << max_chain;
}
