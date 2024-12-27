#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int a[1005][1005];
int h[1005][1005];
int dp[1005][1005];
int minn[1005][1005];

int main() {
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1) {
                h[i][j] = a[i][j];
            } else if (a[i][j] > 0 && a[i - 1][j] > 0) {
                h[i][j] = h[i - 1][j] + 1;
            } else if (a[i][j] > 0 && a[i - 1][j] == 0) {
                h[i][j] = 1;
            } else {
                h[i][j] = 0;
            }
        }
    }
    ll maxx = LLONG_MIN;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            for(int k = j+1; k<=n;k++){
                if(h[i][k] == 0) break;
                else{
                    ll curr = k * minn[i][k];
                    cout<<curr<<endl;
                    maxx = max(curr, maxx);
                }
            }
        }
    }
    cout<<maxx;

    cout << endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << minn[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
5 6
0 1 1 1 1 1
1 1 1 1 1 1
0 0 0 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1

0 1 1 1 1 1 
1 2 2 2 2 2 
0 0 0 3 3 3 
1 1 1 4 4 4 
2 2 2 5 5 5
*/
