#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"


int main() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    int min_diff = INT_MAX;

    for (int i = 0; i <= n - k; i++) {
        int diff = a[i + k - 1] - a[i];
        min_diff = min(min_diff, diff);
    }
    
    cout << min_diff << endl;
    return 0;
}
