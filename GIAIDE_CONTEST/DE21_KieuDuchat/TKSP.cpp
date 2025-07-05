#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define int long long
#define endl "\n"

signed main(){
    freopen("TKSP.INP", "r", stdin);
    freopen("TKSP.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    ll total = (ll)n * (n + 1) / 2;
    vector<int> cnt(mx+1, 0);
    ll count_bad = 0;
    int l = 0;
    for(int r = 0; r < n; r++){
        cnt[a[r]]++;
        while(cnt[a[r]] >= k){
            cnt[a[l]]--;
            l++;
        }
        count_bad += (r - l + 1);
    }
    cout << (total - count_bad) << "\n";
    return 0;
}
