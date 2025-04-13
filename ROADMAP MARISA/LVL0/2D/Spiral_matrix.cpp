#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int n, m;

void print(vector<vector<ll>>& a) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) { 
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1));

    ll cur = 1;
    int i = 1, j = 1, idx = 0;
    while (cur <= n * m) {
        a[i][j] = cur++;

        int ni = i + dx[idx];
        int nj = j + dy[idx];

        if (ni < 1 || ni > n || nj < 1 || nj > m || a[ni][nj] != 0) {
            idx = (idx + 1) % 4;
        }

        i += dx[idx];
        j += dy[idx];
    }

    print(a);
}