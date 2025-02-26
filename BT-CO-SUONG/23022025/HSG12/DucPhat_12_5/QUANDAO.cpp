#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("QUANDAO.INP","r",stdin);
    freopen("QUANDAO.OUT","w",stdout);
    fast;
}
const int M = 1000;
int n, a[M][M];

void fw() {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][k] && a[k][j]) a[i][j] = 1;
}

int dem() {
    bool d[M] = {};
    int c = 0;
    for (int i = 0; i < n; i++)
        if (!d[i]) {
            c++;
            for (int j = 0; j < n; j++)
                if (a[i][j]) d[j] = 1;
        }
    return c;
}

KING_PHAT {
    init();
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    fw();
    cout << dem() << "\n";
}
