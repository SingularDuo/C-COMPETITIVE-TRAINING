#include <bits/stdc++.h>
using namespace std;

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
int main() {
    vector<vector<int>> a(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> res(3, vector<int>(3, 1));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] % 2 == 0) continue;
            else {
                res[i][j] = abs(res[i][j] - 1);
                for (int x = 0; x < 4; x++) {
                    int nx = i + dr[x];
                    int ny = j + dc[x];
                    if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                        res[nx][ny] = abs(res[nx][ny] - 1);
                    }
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << res[i][j];
        }
        cout << endl;
    }

    return 0; 
}
