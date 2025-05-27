#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define pb push_back
#define endl "\n"
#define min(a, b) min((ll)a, ll(b))
#define max(a, b) max((ll)a, ll(b))
#define __gcd(a, b) __gcd((ll)a, ll(b))
#define sqrt(a) (ll)sqrt((ll)a)
void init()
{
    freopen("UOC.INP", "r", stdin);
    freopen("UOC.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define sqrt(a) (ll)sqrt((ll)a)
bool scp(int x)
{
    int a = round(sqrt(x));
    return a*a==x;
}
signed main()
{
    init();
    int n;
    cin>>n;
    int le = 0, chan = 0;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        if(scp(a)) le++;
        else chan++;
    }
    cout<<chan<<endl<<le;
}
