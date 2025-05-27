#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define endl "\n"

signed main()
{
    freopen("COST.inp", "r", stdin);
    freopen("COST.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b; cin>>n>>a>>b;
    vector<int> box(n);
    for(int i = 0; i < n; i++)cin>>box[i];
    int minn = min(a, b);
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        if(box[i] == 2)res+= a + b;
        else res += minn;
    }
    cout<<res;
}