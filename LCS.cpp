#include<bits/stdc++.h>

using namespace std;

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

int main() {
    int n;
    cin>>n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    for(int i = 0; i < n; i++)cin>>b[i];

    pair<int, int> result = find(a, b);
    cout << result.first << result.second  << endl;

    return 0;
}
