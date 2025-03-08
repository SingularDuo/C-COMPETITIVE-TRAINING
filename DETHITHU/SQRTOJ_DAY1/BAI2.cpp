#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int maxn = 1e6;
const int dr[4] = {0, -1, 0, 1};
const int dc[4] = {-1, 0, 1, 0};
int n, m;
bool ValidCell(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}
ll calculate(ll i, ll j, const vector<vector<ll>>& a){
    ll res = a[i][j];
    ll val1=0,val2=0,val3=0,val4=0;
    for(int i = 0; i < n; i++){
        ll nx = i + dr[i], ny = j + dc[i];
        if(ValidCell(nx, ny)){
            res += a[nx][ny];
        }
    }
    return res;
}

signed main()
{


    cin>>n>>m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
    }
    ll pos1 = 0, pos2 = 0, maxx = LLONG_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++){
            ll curr = calculate(i,j,a);
            if(curr > maxx)
            {
                pos1 = i;
                pos2 = j;
                maxx = curr;
            }
        }
    }
    cout<<pos1<<pos2;


}
