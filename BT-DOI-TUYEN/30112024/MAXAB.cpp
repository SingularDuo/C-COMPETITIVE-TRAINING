#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    int n;
    cin >> n;
    int a[101][101];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int tong = INT_MIN; 
    int top = 0, left = 0;
    int size = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int currtong = 0;
            for (int k = 1; i + k - 1 < n && j + k - 1 < n; k++) {
                bool val = true; 
                for (int l = 0; l < k; l++) {
                    if (a[i + l][j + k - 1] == 0 || a[i + k - 1][j + l] == 0) {
                        val = false;
                        break;
                    }
                }
                if (!val) break;
                for (int l = 0; l < k; l++) currtong += a[i + l][j + k - 1];
                for (int l = 0; l < k - 1; l++) currtong += a[i + k - 1][j + l]; 
                if (currtong > tong) {
                    tong = currtong;
                    top = i;
                    left = j;
                    size = k;
                }
            }
        }
    }
    if (tong != INT_MIN) {
        cout << tong << endl;
    }
    return 0;
}
