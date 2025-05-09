#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define pb push_back
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
// #define gcd(a, b) __gcd((ll)a, (ll)b)

void init()
{
    freopen("NUMBER.INP", "r", stdin);
    freopen("NUMBER.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

signed main()
{
    init();
    int a, b;
    cin>>a>>b;
    cout<<round(__gcd(a, b))*2<<endl;
}