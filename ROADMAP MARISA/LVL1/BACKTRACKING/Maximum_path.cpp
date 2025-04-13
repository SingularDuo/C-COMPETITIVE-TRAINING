#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
vector<vector<ll>> a(4, vector<ll>(4, 0));
ll maxx = LLOMG_MIN;
bool ValidCell(int r, int c) {
    return (r >= 0 && r < 4 && c >= 0 && c < 4); 
}
void gen(ll current_val, ll curr_x, ll curr_y)
{
    if(curr_x == 3 && curr_y == 3)
    {
        maxx = max(maxx,, current_val);
    }
    for(int i = curr_x; i < 4; i++)
    {
        for(int j = curr_y; j < 4; j++)
    }
}
KING_PHAT
{
    fast;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cin>>a[i][j];
        }
    }

}