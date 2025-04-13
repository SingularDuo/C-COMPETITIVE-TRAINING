#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int n, m, q;
vector<vector<ll>> a;

struct queries
{
    int type, idx_i, idx_j;
};

KING_PHAT
{
    fast;
    cin >> n >> m >> q;
    a.resize(n, vector<ll>(m)); 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    vector<queries> query(q);
    for (int i = 0; i < q; i++) 
    {
        cin >> query[i].type >> query[i].idx_i >> query[i].idx_j;
    }
    for(auto& i : query)
    {
        if(i.type == 1)
        {
            int r1 = i.idx_i - 1;
            int r2 = i.idx_j - 1;
            for(int j = 0; j < m; j++) 
            {
                swap(a[r1][j], a[r2][j]);
            }
        }
        else if(i.type == 2)
        {
            int c1 = i.idx_i - 1;
            int c2 = i.idx_j - 1;
            for(int j = 0; j < n; j++) 
            {
                swap(a[j][c1], a[j][c2]);
            }
        }
    }
    for(auto&i : a)
    {
        for(auto& j : i) cout << j << " ";
        cout << endl;
    }

    return 0;
}
