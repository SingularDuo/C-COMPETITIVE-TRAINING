#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
int a[1005][1005];
int dp[1005][1005];
void init(){
    freopen("ONESQ.INP", "r", stdin);
    freopen("ONESQ.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    int n, m;
    cin>>m>>n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    int maxx = INT_MIN;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (dp[i-1][j] > 0 && dp[i][j-1] > 0 && dp[i-1][j-1] > 0 && a[i][j] > 0)
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + a[i][j];
            else dp[i][j] = a[i][j];

            if (dp[i][j] > maxx) maxx = dp[i][j];
        }
    }
    cout<<maxx;
}