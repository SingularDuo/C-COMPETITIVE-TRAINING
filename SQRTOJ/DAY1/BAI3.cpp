#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void init()
{
    freopen("MCOUNT.INP", "r", stdin);
    freopen("MCOUNT.OUT", "w", stdout);
    fast;
}
int n, x;
vector<int> a;
const int MOD = 1e9+7;
void generate_subsets(vector<int> &arr, vector<int> &sub, int x) {
    int size = arr.size();
    for (int mask = 0; mask < (1 << size); mask++) {
        int product = 1;
        bool valid = true;
        for (int j = 0; j < size; j++) {
            if (mask & (1 << j)) {
                if (product > x / arr[j]) {
                    valid = false;
                    break;
                }
                product *= arr[j];
            }
        }
        if (valid) sub.push_back(product);
    }
}

signed main() {
    init();
    fast;
    cin >> n >> x;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> left_half(a.begin(), a.begin() + n / 2);
    vector<int> right_half(a.begin() + n / 2, a.end());
    vector<int> left_subsets, right_subsets;
    generate_subsets(left_half, left_subsets, x);
    generate_subsets(right_half, right_subsets, x);
    sort(right_subsets.begin(), right_subsets.end());

    int res = 0;
    for (int val : left_subsets) {
        res += upper_bound(right_subsets.begin(), right_subsets.end(), x / val) - right_subsets.begin();
    }
    cout << (res-1)%MOD<< '\n'; 
}
