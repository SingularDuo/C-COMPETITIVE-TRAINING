#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("DOANPHU.inp", "r", stdin);
    freopen("DOANPHU.out", "w", stdout);
    fast;
}
signed main() {
    init();
    int n;
    cin >> n; 
    vector<int> marking(1000, 0);
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        for (int j = a; j < b; j++) {
            marking[j]++;
        }
    }
    int maxx = *max_element(marking.begin(), marking.end());
    int cnt = 0;
    for (int frequency : marking) {
        if (frequency == maxx) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}