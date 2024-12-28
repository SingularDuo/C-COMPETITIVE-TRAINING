#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> even, odd;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            even.pb(a[i]);
        else
            odd.pb(a[i]);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    vector<ll> result;
    int i = 0, j = 0;
    bool iseven = true;
    while (i < even.size() || j < odd.size()) {
        if (iseven && i < even.size()) {
            result.pb(even[i++]);
            iseven = false;
        } else if (!iseven && j < odd.size()) {
            result.pb(odd[j++]);
            iseven = true;
        } else if (i < even.size()) {
            result.pb(even[i++]);
        } else if (j < odd.size()) { 
            result.pb(odd[j++]);
        }
    }
    for (int x : result) cout << x << " ";
}
