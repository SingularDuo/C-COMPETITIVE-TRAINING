#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
const int MOD = 1e9 + 7;
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
    if(n == 1 && m == 1)
    {
        if(a == b){
            cout<<2;
            return 0;
        }
        cout<<"3";
        return 0;
    }
    else if(a == b)
    {
        int max_value = a*(n+m);
        cout<<(n+m) % MOD;
        return 0;
    }
    else if( m == 1){
        cout<<n * 2;
        return 0;

    }
    else if( n <= 10 && m <= 10)
    {
        gen(0,n,m);
        cout<<sums.size() % MOD<<endl;
        return 0;
    }
    gen(0, n, m);
    cout << sums.size() % MOD << endl;
    return 0;
}
