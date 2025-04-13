#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
vector<vector<ll>> a;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    cin >> k >> n;
    a.resize(n + 1);

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            a[x].push_back(j);
        }
    }

    /*for(auto&i : a)
    {
        for(auto&j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }*/
    ll res = 0;
    for (int i = 0; i <= k; i++) {
        if (a[i].empty()) continue;
        int val = a[i][0];

        for (int j = 0; j <= k+1; j++) {
            if (j == i || a[j].empty()) continue;
            bool ok = true;

            for (size_t idx = 0; idx < a[j].size(); idx++) {
                if (a[j][idx] > a[i][idx]) {
                    ok = false;
                    break;
                }
            }
            if (ok) res++;
        }
    }

    cout << res << endl;
    return 0;
}
