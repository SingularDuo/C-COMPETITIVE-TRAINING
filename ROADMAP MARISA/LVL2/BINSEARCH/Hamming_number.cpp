#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

set<ll> hamming;

void gen_hamming(ll limit) {
    queue<ll> q;
    q.push(1);

    while (!q.empty()) {
        ll current = q.front();
        q.pop();

        if (current > limit) break;
        if (hamming.count(current)) continue; 

        hamming.insert(current);
        q.push(current * 2);
        q.push(current * 3);
        q.push(current * 5);
    }
}
bool is_hamming(ll x) {  
    while (x % 2 == 0) x /= 2;  
    while (x % 3 == 0) x /= 3;  
    while (x % 5 == 0) x /= 5;  
    return x == 1;              
}

KING_PHAT {
    fast;

    ll limit = 1e18; 
    gen_hamming(limit);

    vector<ll> hamming_vector(hamming.begin(), hamming.end());
    int m;
    cin >> m;

    while (m--) {
        int n;
        cin >> n; 
        if (!is_hamming(n)) { 
            cout << -1 << endl;
            continue;
        }
        auto it = lower_bound(hamming_vector.begin(), hamming_vector.end(), n);
        cout << (it - hamming_vector.begin() + 1) << endl;  
    }
}
