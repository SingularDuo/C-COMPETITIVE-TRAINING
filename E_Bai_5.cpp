#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define KING_PHAT signed main()

KING_PHAT {
    faster;
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<ll> prefixsum(N);
    for (int i = 0; i < N; i++) {
        prefixsum[i] = A[i] - (i + 1);
    }
    
    while (Q--) {
        ll K;
        cin >> K;
        
        auto it = lower_bound(prefixsum.begin(), prefixsum.end(), K);
        int idx = it - prefixsum.begin();
        
        if (idx == 0) {
            cout << K << "\n";
        } else {
            cout << A[idx - 1] + (K - prefixsum[idx - 1]) << "\n";
        }
    }
    
    return 0;
}