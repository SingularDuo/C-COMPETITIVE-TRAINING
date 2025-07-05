#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = (5 * 1e5) + 5;
const int MAX_A = 1005; 

int a[N], freq[MAX_A];

int get_median(int d) {
    int cnt = 0;
    if (d % 2 == 1) {
        int target = d / 2 + 1;
        for (int i = 0; i < MAX_A; i++) {
            cnt += freq[i];
            if (cnt >= target) return 2 * i; 
        }
    } else {
        int t1 = d / 2;
        int t2 = t1 + 1;
        int m1 = -1, m2 = -1;
        for (int i = 0; i < MAX_A; i++) {
            cnt += freq[i];
            if (cnt >= t1 && m1 == -1) m1 = i;
            if (cnt >= t2) {
                m2 = i;
                break;
            }
        }
        return m1 + m2; 
    }
    return 0;
}

signed main() {
    freopen("ATM.INP", "r", stdin);
    freopen("ATM.OUT", "w", stdout);
    fast;
    
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < d; i++) freq[a[i]]++;

    int res = 0;
    for (int i = d; i < n; i++) {
        int median2 = get_median(d); 
        if (a[i] >= median2) res++;

        freq[a[i - d]]--;
        freq[a[i]]++;
    }

    cout << res << '\n';
    return 0;
}
