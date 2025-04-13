#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("POSZERO.inp","r",stdin);
    freopen("POSZERO.out","w",stdout);
    fast;
}
KING_PHAT
{
    init();
    fast;
    string s;
    cin>>s;
    auto it = upper_bound(s.begin(), s.end(), '0');
    if(it == s.end())cout<<s.size();
    else cout<<it-s.begin();
}