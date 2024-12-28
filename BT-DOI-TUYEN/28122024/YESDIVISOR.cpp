#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> soUoc(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            soUoc[j]++;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (soUoc[i] <= k) res++;
    }
    cout << res << endl;
    return 0;
}
