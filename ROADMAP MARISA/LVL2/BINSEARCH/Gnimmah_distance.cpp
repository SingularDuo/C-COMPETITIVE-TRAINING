#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

signed main() {
    fast;
    string A, B;
    cin >> A >> B;

    int n = A.size(), m = B.size(), res = 0;

    for (int i = 0; i <= n - m; i++) {
        int count = 0;
        for (int j = 0; j < m; j++) {
            if (A[i + j] == B[j]) {x
                count++; 
            }
        }
        res += count; 
    }
            
    cout << res << endl;
    return 0;
}
