#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
void init(){
    freopen("MPILOT.INP", "r", stdin);
    freopen("MPILOT.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int n, k;
vector<vector<ll>> a(k+1, vector<ll>(n+1));
signed main()
{
    //init();
    cin>>k>>n;
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n;j++)cin>>a[i][j];
    }



}
