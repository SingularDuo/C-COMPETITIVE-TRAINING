#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int a[105][105];
int f[105][105];

void init() {
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int maxn = 1e5;
const int MOD = 1e9 + 7;
bool isprime[maxn + 1];

void sieve() {
    for (int i = 0; i <= maxn; i++) isprime[i] = true;
    isprime[1] = isprime[0] = false;
    for (int i = 2; i * i <= maxn; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
}

bool valid(int i, int j, int m, int n) {
    return (i <= m && j <= n && i >= 1 && j >= 1);
}

int main() {
    init();
    sieve();
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    f[1][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            if (valid(i - 1, j, m, n) && isprime[abs(a[i - 1][j] - a[i][j])]) {
                f[i][j] += f[i - 1][j];
            }
            if (valid(i, j - 1, m, n) && isprime[abs(a[i][j - 1] - a[i][j])]) {
                f[i][j] += f[i][j - 1];
            }
            f[i][j] %= MOD;
        }
    }
    cout << f[m][n] << endl;
    return 0;
}
/*
5 6
1 4 8 6 2 9
6 9 12 15 8 4
8 12 2 4 13 4
7 5 7 9 11 9
8 6 8 9 14 16
*/