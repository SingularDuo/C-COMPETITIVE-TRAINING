#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
const int MAX = 1005;
int a[MAX][MAX];
//
//void trau() {
//
//}
//
//void full() {
//
//}
//
//void solve() {
//    if(n <= 100) {
//        trau();
//    } else{
//        full();
//    }
//}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int currentval = a[i][j];
            bool isqueen = true;
            for (int k = 0; k < m; k++) {
                if (a[i][k] > currentval && k != j) {
                    isqueen = false;
                }
            }
            for (int k = 0; k < n; k++) {
                if (a[k][j] > currentval && k != i) {
                    isqueen = false;
                }
            }
            for (int k = 1; k < max(n, m); k++) {
                if (i - k >= 0 && j - k >= 0 && a[i - k][j - k] > currentval) {
                    isqueen = false;
                }
                if (i + k < n && j + k < m && a[i + k][j + k] > currentval) {
                    isqueen = false;
                }
            }
            for (int k = 1; k < max(n, m); k++) {
                if (i - k >= 0 && j + k < m && a[i - k][j + k] > currentval) {
                    isqueen = false;
                }
                if (i + k < n && j - k >= 0 && a[i + k][j - k] > currentval) {
                    isqueen = false;
                }
            }

            if (isqueen) {
                pos.push_back({i + 1, j + 1});
            }
        }
    }
    if (pos.empty()) {
        cout << endl;
        return 0;
    } else {
        sort(pos.begin(), pos.end());
        for (auto p : pos) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}
/*
5 6
3 5 6 8 19 7
1 3 4 6 7 12
13 15 17 50 5 7
25 3 2 6 8 9
5 8 5 8 6 9
*/
/*
5 5
2 3 14 5 1
3 2 1 4 5
2 9 3 6 7
4 2 7 9 2
4 6 4 6 8
*/
