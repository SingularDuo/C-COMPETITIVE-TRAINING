#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define ll long long

void init() {
    freopen("TUYETCHIEU.inp", "r", stdin);
    freopen("TUYETCHIEU.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> last_used(1000001, -1); 
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (last_used[a[i]] != -1 && i - last_used[a[i]] <= k) {
            if (last == -1 || a[i] < last) {
                last = a[i];
            }
        }
        last_used[a[i]] = i; 
    }
    cout << last << endl;
    return 0;
}
