#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
const int maxn =1e6;

void Sang_so_luong_uoc()
{
    for(int i = 1; i*i <= maxn; ++i)
    {
        for (int j = i; j <= maxn/i ; ++j)
        {
            count_factor[i*j] += (1 + (i != j));
        }
    }
}
KING_PHAT
{
    fast;
    Sang_so_luong_uoc();
}