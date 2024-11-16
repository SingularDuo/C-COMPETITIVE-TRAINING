#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 1005;
const int MOD = 1e9+7;
char a[maxn][maxn];
int dp[maxn][maxn];
int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n;i++){
        for(int j = 0; j< n;j++)
        {
            cin>>a[i][j];
        }
    }
    if(a[0][0] == '*'){
        cout<<"0";
        return 0;
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j< n;j++)
        {
            if(a[i][j] == '*')a[i][j] = 0;
            if(a[i][j] == '.')a[i][j] = 1;
        }
    }
    a[0][0] = 1;
    for(int i = 0; i < n;i++){
        for(int j = 0; j< n;j++)
        {
            dp[i][j] = (int)a[i][j];
        }
    }
    for(int i = 1; i < n; i++){
        if(dp[0][i] == 0){
            for(int j = i; j < n; j++){
                dp[0][j] = 0;
                break;
            }
        }
        else dp[0][i] = dp[0][i-1];
    }
    for(int i = 1; i < n; i++){
        if(dp[i][0] == 0){
            for(int j = i; j < n; j++){
                dp[j][0] = 0;
                break;
            }
        }
        else dp[i][0] = dp[i-1][0];
    }
    for(int i = 1; i < n;i++){
        for(int j = 1; j< n;j++)
        {
            if(dp[i][j] == 0){
                continue;
            }
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
            
        }
    }
    cout<<(dp[n-1][n-1])%MOD;

}