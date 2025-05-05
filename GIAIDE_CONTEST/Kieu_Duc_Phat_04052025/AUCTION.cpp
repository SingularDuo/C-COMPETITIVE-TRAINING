
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
void init()
{
    freopen("AUCTION.inp", "r", stdin);
    freopen("AUCTION.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool normalcheck(int x) {
    if (x <= 1) return false;
    if (x == 2 || x == 3 || x == 5) return true;
    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0) return false;

    for (int i = 5; i * i <= x; i += 6) { 
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}

bool ispalin(int x)
{
    string s = to_string(x);
    string sub = s;
    reverse(s.begin(), s.end());
    return sub == s;
}
signed main()
{
    //init();
    int res = 0, a,b;
    cin>>a>>b;
    for(int i = a; i <= b; i++)
    {
        if(ispalin(i) && normalcheck(i))res++;
    }   
    cout<<res<<endl;
    return 0;
}