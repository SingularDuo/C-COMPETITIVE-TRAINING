#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void xoanoc(int n, int m, vector<vector<int>>& arr) {
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    int value = 1;

    while (top <= bottom && left <= right) {
        // Đi từ trái sang phải
        for (int i = left; i <= right; i++) {
            arr[top][i] = value++;
        }
        top++; // Giảm hàng trên

        // Đi từ trên xuống dưới
        for (int i = top; i <= bottom; i++) {
            arr[i][right] = value++;
        }
        right--; // Giảm cột phải

        // Đi từ phải sang trái (nếu còn hàng)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                arr[bottom][i] = value++;
            }
            bottom--; // Giảm hàng dưới
        }

        // Đi từ dưới lên trên (nếu còn cột)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                arr[i][left] = value++;
            }
            left++; // Tăng cột trái
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    xoanoc(n, n, arr);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }

    return 0;
}
