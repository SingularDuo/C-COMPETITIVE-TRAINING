#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    freopen("ROAD.INP", "r", stdin);
    freopen("ROAD.OUT", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= k;
    }

    unordered_map<ll, int> prefix_map = {{0, -1}};
    ll prefix_sum = 0;
    int start = -1, max_length = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];
        if (prefix_map.count(prefix_sum)) {
            int length = i - prefix_map[prefix_sum];
            if (length > max_length) {
                max_length = length;
                start = prefix_map[prefix_sum] + 1;
            }
        } else {
            prefix_map[prefix_sum] = i;
        }
    }

    if (start == -1) {
        cout << 0 << endl;
    } else {
        cout << start + 1 << " " << max_length << endl;
    }

    return 0;
}
