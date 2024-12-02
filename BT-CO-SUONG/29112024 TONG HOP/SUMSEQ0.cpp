#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
void init() {
    freopen("SUMSEQ0.inp", "r", stdin);
    freopen("SUMSEQ0.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> prefix_count;
    prefix_count[0] = 1;

    int sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (prefix_count.count(sum)) {
            count += prefix_count[sum];
        }
        prefix_count[sum]++;
    }

    cout << count << endl;
    return 0;
}