#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll x, y, m;
ll res = 0;

void gen(ll sum)
{
    if (sum > m) return;
    if(res == m)return;
    if(sum == m)
    {
        res = m;
        return;
    }
    res = max(res, (ll)sum);
    gen(sum + x);
    gen(sum + y);
}

int main()
{
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>x>>y>>m;
    gen(0);
    cout<<res;
    return 0;
}
