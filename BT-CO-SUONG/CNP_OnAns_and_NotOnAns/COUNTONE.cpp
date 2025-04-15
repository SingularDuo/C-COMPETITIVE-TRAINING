#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("COUNTONE.inp", "r", stdin);
    freopen("COUNTONE.out", "w", stdout);
    fast;
}
KING_PHAT
{
    init();
    fast;
    int n;
    bool exist1 = false;
    cin >> n;
    vector<int> a(n);
    for(int i =0 ;i < n; i++)
    {
        cin >> a[i];
        if(a[i] == 0)a[i] = LLONG_MAX;
        if(a[i] == 1) exist1 = true;
    }
    if(!exist1)
    {
        cout << 0;
        return 0;
    }
    sort(a.begin(), a.end());
    int res = 0;
    for(int i = 0; i < n; i ++)
    {
        if(a[i] == 1)res++;
        else break;
    }
    cout<<res;

}