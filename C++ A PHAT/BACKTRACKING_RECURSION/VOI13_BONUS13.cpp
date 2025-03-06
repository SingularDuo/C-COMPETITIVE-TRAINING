#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KInG_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int dr[8] = {-1,-1,-1, 0,0, 1,1,1};
int dc[8] = {-1, 0, 1,-1,1,-1,0,1};
vector<ll> hau, ma, xe, tuong;

bool validcell(ll x, ll y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

vector<vector<ll>> field(8, vector<ll>(8, 0));

ll loang_hau(ll x, ll y) {
    ll res = 0;
    for (int i = 0; i < 8; i++) {
        ll nx = x + dr[i], ny = y + dc[i];
        while (validcell(nx, ny)) { 
            res += field[nx][ny];
            nx += dr[i];
            ny += dc[i];
        }
    }
    return res;
}

ll loang_xe(ll x, ll y) {
    ll res = 0;
    int dx[4] = {-1, 1, 0, 0}; 
    int dy[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        ll nx = x + dx[i], ny = y + dy[i];
        while (validcell(nx, ny)) {
            res += field[nx][ny];
            nx += dx[i];
            ny += dy[i];
        }
    }
    return res;
}

ll loang_tuong(ll x, ll y) {
    ll res = 0;
    int dx[4] = {-1, -1, 1, 1}; 
    int dy[4] = {-1, 1, -1, 1};

    for (int i = 0; i < 4; i++) {
        ll nx = x + dx[i], ny = y + dy[i];
        while (validcell(nx, ny)) {
            res += field[nx][ny];
            nx += dx[i];
            ny += dy[i];
        }
    }
    return res;
}

ll loang_ma(ll x, ll y) {
    ll res = 0;
    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int i = 0; i < 8; i++) {
        ll nx = x + dx[i], ny = y + dy[i];
        if (validcell(nx, ny)) {
            res += field[nx][ny];
        }
    }
    return res;
}

const int n = 8;
vector<vector<pair<int, int>>> placing;
vector<pair<int, int>> pieces;
vector<vector<bool>> board(n, vector<bool>(n, false));

void backtrack(int placed) {
    if (placed == 4) {
        placing.push_back(pieces);
        return;
    }
    
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (!board[row][col]) { 
                board[row][col] = true;
                pieces.push_back({row, col});
                backtrack(placed + 1);
                pieces.pop_back();
                board[row][col] = false;
            }
        }
    }
}

KInG_PHAT {
    fast;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        ll x, y, v;
        cin >> x >> y >> v;
        field[x - 1][y - 1] = v;
    }
    
    backtrack(0);
    ll max_able = LLONG_MIN;
    
    for (const auto& config : placing) {
        max_able = max(
            loang_hau(config[0].first, config[0].second) +
            loang_ma(config[1].first, config[1].second) +
            loang_xe(config[2].first, config[2].second) +
            loang_tuong(config[3].first, config[3].second),
            max_able
        );
    }

    cout << max_able;
}
