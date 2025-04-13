#include<bits/stdc++.h>

using namespace std;
#define int long long
pair<int, int> find(const vector<int>& a, const vector<int>& b) {
    vector<int> sa = a;
    vector<int> sb = b;
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());

    int i = 0, j = 0;
    int minn = INT_MAX;
    pair<int, int> res = {0, 0};

    while (i < sa.size() && j < sb.size()) {
        int curr = sa[i] + sb[j];
        int abss = abs(curr);

        if (abss < minn) {
            minn = abss;
            res = {sa[i], sb[j]};
        }

        if (curr < 0) {
            i++;
        } else {
            j++;
        }
    }

    return res;
}

signed main() {
    freopen("TROCHOI.inp", "r", stdin);
    freopen("TROCHOI.out", "w", stdout);
    int n;
    cin>>n;
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    for(int i = 0; i < n; i++)cin>>b[i];

    pair<int, int> result = find(a, b);
    cout << abs(result.first -result.second) << endl;

    return 0;
}
