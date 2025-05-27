#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define int long long

void init()
{
    freopen("GIFT.inp", "r", stdin);
    freopen("GIFT.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
signed main() 
{
    init();
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> dp(n, 1); 

    int res = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] >= a[j] + k) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }   

    cout << res << endl;
    return 0;
}
