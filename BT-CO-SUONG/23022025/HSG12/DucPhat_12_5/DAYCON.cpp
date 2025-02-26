#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("DAYCON.INP","r",stdin);
    freopen("DAYCON.OUT","w",stdout);
    fast;
}
KING_PHAT 
{
    init();

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bool found = false;
    for (int l = 0; l < n; l++) {
        int sum = 0;
        for (int r = l; r < n; r++) {
            sum += a[r];
            if (sum == m) {
                found = true;
                for (int i = l; i <= r; i++) {
                    cout << a[i] << " ";
                }
                cout << endl;
            }
        }
    }

    if (!found) cout <<"0"<<endl;
}
