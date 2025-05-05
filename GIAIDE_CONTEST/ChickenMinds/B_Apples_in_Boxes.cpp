#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, arr, size, value) vector<type> arr(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;
#define min(a,b) min((ll)a, (ll)b)
#define max(a,b) max((ll)a, (ll)b)

bool multitest = false;

void init() {
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}

void sol() {
    int t;
    cin >> t;
    
    while (t--) {
        int ele, limit;
        cin >> ele >> limit;
        int minn = 1e9, maxx = 0, totalSum = 0;
        map<int, int> frequency;

        for (int index = 1; index <= ele; index++) {
            int current;
            cin >> current;
            minn = min(minn, current);
            maxx = max(maxx, current);
            frequency[current]++;
            totalSum += current;
        }

        if (maxx - minn > limit + 1 || (maxx - minn == limit + 1 && frequency[maxx] > 1)) {
            cout << "Jerry" << '\n';
            continue;
        } else if (totalSum % 2) {
            cout << "Tom" << '\n';
        } else {
            cout << "Jerry" << '\n';
        }
    }
}

KING_PHAT {
    fast;
    if (multitest) {
        int t;
        cin >> t;
        while (t--) {
            sol();
        }
    } else {
        sol();
    }
    return 0;
}
