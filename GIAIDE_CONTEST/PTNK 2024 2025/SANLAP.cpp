#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

vector<vector<int>> a;
vector<vector<int>> lien_thong;
map<int, int> lien_thong_size;

int n, m, comp_id = 1;

bool ValidCell(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void BFS(int r, int c) {
    queue<pii> Q;
    Q.push({r, c});
    lien_thong[r][c] = comp_id;
    int count = 1;

    while (!Q.empty()) {
        pii front = Q.front();
        int x = front.first, y = front.second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dr[i], ny = y + dc[i];
            if (ValidCell(nx, ny) && a[nx][ny] == 1 && lien_thong[nx][ny] == 0) {
                Q.push({nx, ny});
                lien_thong[nx][ny] = comp_id;
                count++;
            }
        }
    }
    lien_thong_size[comp_id] = count;
    comp_id++;
}

int find() {
    int max_area = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 1 && lien_thong[i][j] == 0) {
                BFS(i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0) {
                set<int> ke;
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dr[k], ny = j + dc[k];
                    if (ValidCell(nx, ny) && a[nx][ny] == 1) {
                        ke.insert(lien_thong[nx][ny]);
                    }
                }
                int new_area = 1;
                for (int comp : ke) {
                    new_area += lien_thong_size[comp];
                }
                max_area = max(max_area, new_area);
            }
        }
    }

    return max_area;
}

int main() {
    cin >> n >> m;
    a.assign(n, vector<int>(m));
    lien_thong.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    cout << find() << endl;
    return 0;
}
