#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n, m, res = 0;

void sol(int n, int m) {
    vector<int> a(n);
    map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int max_able = m - a[i];
        if (a[i] == -1) continue;
        for(int j = 1; j < max_able; j++){
            if(a[j] == a[i])
            {
                res += cnt[j]-1;
            }
            else res += cnt[j];
        }
        a[i] = -1;
    }

    cout << res << endl;
}

signed main() {
    cin >> n >> m;
    sol(n, m);
}
