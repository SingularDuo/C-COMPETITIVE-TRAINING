#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll a[505][505];
ll f[505][505];
void init(){
    freopen("CATBANH.INP", "r", stdin);
    freopen("CATBANH.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    ll n, k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>a[i][j];
        }
    }
    if(k == 1){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin>>a[i][j];
            }
        }
        ll maxx = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                ll upper = 0, right = 0;
                if(i-1 >= 1)    upper = a[i-1][j];
                if(j + 1 <= n)  right = a[i][j+1];
                ll curr_val = a[i][j] + right + upper;
                maxx = max(maxx, curr_val);
            }
        }
        cout<<maxx;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            f[i][j] += a[i][j] + f[i][j-1];
        }
    }
    ll maxx = LLONG_MIN;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ll line = 0;
            ll currsum = 0;
            ll sub = 0;
            if(i - k >= 1 && j + k <= n){
                for(int l = k; l >= 0; l--){
                currsum += f[i - line][j+(k - sub)] - f[i - line][j-1];
                line++;
                sub++;
                }
            }

            maxx = max(maxx, currsum);
        }
   }
   cout<<maxx;
    
}
