#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"

int a[1005][1005];
int dp[1005][1005];
void init(){
    freopen("HCN.INP", "r", stdin);
    freopen("HCN.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    int n, m;
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int maxx = INT_MIN;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(a[i][j] == 1){
                a[i-1][j] = 0;
                a[i][j-1] = 0;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(a[i][j] == 1)res++;
        }
    }
    cout<<res;
}
/*
5 5
1 1 0 0 1
1 1 0 0 1
0 0 0 0 1
0 0 0 0 0
1 1 0 1 1
*/