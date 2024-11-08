#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

int dp[MAX_N + 1][MAX_M + 1];  
int a[MAX_N + 1], b[MAX_N + 1]; 
void init(){
    freopen("CAYKHE.inp", "r", stdin);
    freopen("CAYKHE.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    int N, M;  
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> a[i] >> b[i];  
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = 0;
        }
    }


    for (int i =1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (b[i] <= j) {  
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - b[i]] + a[i]);
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
            }
        }
    }

    cout << dp[N][M] << endl;

    return 0;
}
