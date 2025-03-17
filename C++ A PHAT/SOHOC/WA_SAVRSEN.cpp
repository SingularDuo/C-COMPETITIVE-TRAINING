#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

const int maxn = 1e7 + 5;
vector<int> sumDiv(maxn, 0);
vector<int> prefixSum(maxn, 0);

void tonguoc() {
    for (int i = 1; i < maxn; i++) {
        for (int j = i * 2; j < maxn; j += i) {
            sumDiv[j] += i; 
        }
    }
    for (int i = 1; i < maxn; i++) {
        prefixSum[i] = prefixSum[i - 1] + abs(i - sumDiv[i]);
    }
}

int main() {
    fast;
    tonguoc();

    int a, b;
    cin >> a >> b;
    cout << prefixSum[b] - prefixSum[a - 1] << '\n';

    return 0;
}
