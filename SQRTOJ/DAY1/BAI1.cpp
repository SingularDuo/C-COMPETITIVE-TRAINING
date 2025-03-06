#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("WOOD.INP", "r", stdin);
    freopen("WOOD.OUT", "w", stdout);
    fast;
}
int a, b, n, m;
set<int> sums;

void gen(ll sum, ll curra, ll currb) {
    if(sum != 0) sums.insert(sum);;
    if (curra > 0) gen(sum + a, curra - 1, currb);
    if (currb > 0) gen(sum + b, curra, currb - 1);
}

KING_PHAT {
    init();
    fast;
    cin>>a>>b>>n>>m;
    gen(0, n, m);
    cout << sums.size() << endl;
    return 0;
}
