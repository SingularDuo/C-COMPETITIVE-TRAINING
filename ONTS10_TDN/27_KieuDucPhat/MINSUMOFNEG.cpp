#include <bits/stdc++.h>
using namespace std;
#define ll long long

using namespace std;

int find(const vector<int>& arr) {
    int minn = 0;
    int curr = 0;
    bool hasnegative = false;

    for (int num : arr) {
        if (num < 0) {
            hasnegative = true;
            curr += num;
            if (curr < minn) {
                minn = curr;
            }
        } else {
            curr = 0;
        }
    }

    return hasnegative ? minn : 0;
}

int main() {
    freopen("MINSUMOFNEG.inp", "r", stdin);
    freopen("MINSUMOFNEG.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cout << find(arr) << endl;
    }

    return 0;
}
