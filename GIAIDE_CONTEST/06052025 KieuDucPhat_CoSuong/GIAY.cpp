#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
#define all(x) x.begin(), x.end()

void init()
{
    freopen("GIAY.INP", "r", stdin);
    freopen("GIAY.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

signed main()
{
    init();
    int k, n;
    cin >> k >> n;
    
    if (k == 0) {
        cout << n;
        return 0;
    }
    
    int total_cells = (1LL << k);
    int cell = 1, curr = 1;
    for (int i = 0; i < k; i++) {
        cell*=2;
        int half = total_cells / 2;
        
        if (n <= half) {
            n = half - n + 1;
            curr = cell - curr + 1;
        } else {
            n -= half;
        }
        
        total_cells /= 2;
    }
    
    cout << cell - curr +1;
    return 0;
}
