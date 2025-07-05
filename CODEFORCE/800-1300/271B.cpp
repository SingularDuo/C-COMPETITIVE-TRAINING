#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int INF = 2e18;
const int MAXN = 1e6;

bool isprime[MAXN + 5];
int add[MAXN + 5];

void init() {
    fast;
}

void sieve() {
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= MAXN; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= MAXN; j += i)
                isprime[j] = false;
        }
    }
}

void to_add() {
    for (int i = 0; i <= MAXN; i++) {
        int x = 0;
        while (!isprime[i + x]) {
            x++;
        }
        add[i] = x;
    }
}


signed main() {
    init();
    sieve();
    to_add();

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> diff(n, vector<int>(m));

    int min_row = INF;
    for (int i = 0; i < n; i++) {
        int row_sum = 0;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            diff[i][j] = add[a[i][j]];
            row_sum += diff[i][j];
        }
        min_row = min(min_row, row_sum);
    }

    int min_col = INF;
    for (int j = 0; j < m; j++) {
        int col_sum = 0;
        for (int i = 0; i < n; i++) {
            col_sum += diff[i][j];
        }
        min_col = min(min_col, col_sum);
    }

    cout << min(min_row, min_col) << endl;
    return 0;
}
