#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 1e3; 
vector<pair<int, int>> path_vector; 
vector<vector<pair<int, int>>> all;
int b[maxn][maxn];

void path(int x, int y, int n) {
    if (x == n - 1 && y == n - 1) { 
        path_vector.push_back({x, y}); // Lưu ô cuối vào đường đ
        all.push_back(path_vector);
        path_vector.pop_back(); // xoa di xem con di duoc duong khac ko
        return; // Added return to stop further recursion
    }
    if (x < n && y < n && b[x][y] == 1) { // Kiểm tra ô hợp lệ
        path_vector.push_back({x, y}); // Lưu vào đường đi
        b[x][y] = -1; // Đánh dấu ô đã đi qua
        if(x+1<n && b[x+1][y] == 1) path(x + 1, y, n); // Đi xuống
        if(y+1<n && b[x][y+1] == 1) path(x, y + 1, n); //Đi sang phải
        if(x+1<n && b[x-1][y] == 1) path(x - 1, y, n); // Đi len
        if(y+1<n && b[x][y-1] == 1) path(x, y - 1, n);//di sang trai
        if(x+1 < n && y + 1 < n && b[x+1][y+1] == 1)path(x+1,y+1,n);// di xeo phai xuong
        if(x-1 < n && y - 1 < n && b[x-1][y-1] == 1)path(x-1,y-1,n); //di xeo trai len
        if(x-1 < n && y + 1 < n && b[x-1][y+1] == 1)path(x-1,y+1,n); //di xeo phai len
        if(x+1 < n && y - 1 < n && b[x+1][y-1] == 1)path(x+1, y-1, n);//di xeo trai xuong
        b[x][y] = 1;
        path_vector.pop_back(); // Không tìm được đường, loại bỏ ô
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char input;
            cin >> input;
            if (input == '.') {
                b[i][j] = 1; // Ô có thể đi qua
            } else {
                b[i][j] = 0; // Ô bị chặn
            }
        }
    }

    path(0, 0, n);

    if (!all.empty()) {
        for (const auto& path : all) {
            for (const auto& pos : path) {
                cout <<"{"<< pos.first + 1 << "," << pos.second + 1<<"}" << " ";
            }
            cout << endl;
        }
    } else {
        cout << "-1" << endl; 
    }

    return 0;
}
/*

4
....
.##.
..#.
....

*/