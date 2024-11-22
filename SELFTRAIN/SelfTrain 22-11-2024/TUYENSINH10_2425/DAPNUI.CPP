#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> b = a; 
    int cnt = INT_MAX;
    for (int i = 0; i < n; i++) {
        int curr = i;
        if (curr == 0) continue;
        int curr_cnt = 0;
        for (int j = 0; j <= curr; j++) {
            if (j + 1 < n && a[j] >= a[j + 1]) {
                while (a[j] >= a[j + 1]) {
                    a[j + 1]++;
                    curr_cnt++;
                }
            }
        }
        for (int k = curr + 1; k < n; k++) {
            if (k + 1 < n && a[k] <= a[k + 1]) {
                while (a[k] <= a[k + 1]) {
                    a[k]++;
                    curr_cnt++;
                }
            }
        }
        bool trai = true;
        bool phai = true;
        for (int j = 0; j <= curr; j++) {
            if (a[j] >= a[j + 1] && j + 1 < n) trai = false;
        }
        for (int k = curr + 1; k < n; k++) {
            if (k + 1 < n && a[k] <= a[k + 1]) phai = false;
        }
        if (trai && phai) {
            cnt = min(cnt, curr_cnt);
            a = b;
        } else {
            a = b;
        }
    }
    cout << cnt;
    return 0;
}
