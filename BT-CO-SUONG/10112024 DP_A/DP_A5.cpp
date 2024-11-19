#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll current_sum = a[0];
    ll max_sum = a[0];
    for (int i = 1; i < n; i++) {
        current_sum = max(a[i], current_sum + a[i]);
        max_sum = max(max_sum, current_sum);
    }
    cout << max_sum << endl;
    return 0;
}
