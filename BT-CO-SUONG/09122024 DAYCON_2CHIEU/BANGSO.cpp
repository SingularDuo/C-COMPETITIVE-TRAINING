#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("BANGSO.INP", "r", stdin);
    freopen("BANGSO.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
int main() {
    init();
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1] = {0};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin>>a[i][j];
        }
    }
    int f[n+1][m+1] = {0};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            f[i][j] = a[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
        }
    }

    int maxx = INT_MIN, first = 0, sec = 0;
    for(int i = 3; i <= n; i++) {
        for(int j = 3; j <= m; j++) {
             
            int sum = f[i][j] - f[i-3][j] - f[i][j-3] + f[i-3][j-3];
            if(sum > maxx) {
                maxx = sum;
                first = i-2;
                sec = j-2;
            }
        }
    }
    cout << maxx << endl;
    cout << first << " " << sec << endl;
    return 0;
}
