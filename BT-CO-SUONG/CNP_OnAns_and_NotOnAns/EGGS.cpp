#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("EGGS.INP", "r", stdin);
    freopen("EGGS.OUT", "w", stdout);
    fast;
}
bool isvalid(int m, int size, vector<int>& a)
{
    int cell_count = 1; 
    ll current_size = size; 

    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] > size) return false; 
        if(current_size >= a[i])
        {
            current_size -= a[i];
        }
        else
        {
            cell_count++; 
            current_size = size - a[i]; 
            if(cell_count > m) return false; 
        }
    }
    return true;
}

KING_PHAT
{
    init();
    fast;
    int n, m;
    cin>>n>>m;
    vector<ll> a(n);
    int minn = LLONG_MIN, maxx = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        minn = max(minn, a[i]);
        maxx += a[i];
    }
    int res = LLONG_MAX;
    while(minn <= maxx)
    {
        int mid = (minn+maxx)/2;
        if(isvalid(m, mid, a))
        {
            maxx = mid -1;
            res = min(res, mid);
        }
        else minn = mid + 1;
    }
    cout<<minn;

    
}