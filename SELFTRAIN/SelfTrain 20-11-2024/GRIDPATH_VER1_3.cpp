#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 1e3; 
vector<pair<int, int>> path_vector; 
int b[maxn][maxn];

bool path(int x, int y, int n) {
    if (x == n - 1 && y == n - 1) { 
        path_vector.push_back({x, y}); // Lưu ô cuối vào đường đi
        return true;
    }
    if (x < n && y < n && b[x][y] == 1) { // Kiểm tra ô hợp lệ
        path_vector.push_back({x, y}); // Lưu vào đường đi
        b[x][y] = -1; // Đánh dấu ô đã đi qua

        if(path(x + 1, y, n)) return true; // Đi xuống
        if(path(x, y + 1, n)) return true; // Đi sang phải
        if(path(x-1, y , n)) return true; // Đi len
        if(path(x, y - 1, n)) return true; // Đi sang trai
        if(path(x+1, y+1, n)) return true;//Di xeo phai duoi
        if(path(x-1, y-1,n)) return true; //di xeo phai tren
        if(path(x-1,y+1,n)) return true;//di xeo trai len
        if(path(x+1, y-1,n))return true;//di xeo trai xuong
        path_vector.pop_back(); // Không tìm được đường, loại bỏ ô
    }
    return false;
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

    if (path(0, 0, n)) {
        for (auto c : path_vector) {
            cout << c.first + 1 << " " << c.second + 1 << endl;
        }
    } else {
        cout << "-1" << endl; 
    }

    return 0;
}
