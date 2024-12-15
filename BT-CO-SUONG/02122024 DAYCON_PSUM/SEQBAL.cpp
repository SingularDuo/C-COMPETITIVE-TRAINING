#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
void init() {
    freopen("SEQBAL.INP", "r", stdin);
    freopen("SEQBAL.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    init();
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) a[i] = -1;
    }
    
    vector<ll> psum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + a[i];
    }
    
    unordered_map<ll, ll> prefix_count;
    prefix_count[0] = 0;  
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
        if (prefix_count.find(psum[i]) == prefix_count.end()) {
            prefix_count[psum[i]] = i;
        } else {
            int cnt = i - prefix_count[psum[i]];
            if (cnt > maxx) {
                maxx = cnt;
            }
        }
    }

    cout << maxx << endl;
    return 0;
}
