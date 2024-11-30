#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int MAXN = 1000;
int a[MAXN][MAXN];
int main() {
    int m, n, k, l;
    cin >> m >> n >> k >> l;
    k--; 
    l--;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int j = 0; j < n; ++j) {
        swap(a[k][j], a[l][j]);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
