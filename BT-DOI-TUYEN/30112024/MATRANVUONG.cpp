#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int a[MAXN][MAXN];

int main() {
    int n;
    cin >> n;

    // Nhập ma trận
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Khởi tạo các tổng
    int tong_cheo_chinh = 0;
    int tong_cheo_phu = 0;
    int tong_sattren_cheochinh = 0;
    int tong_satduoi_cheochinh = 0;
    int tong_sattren_cheophu = 0;
    int tong_satduoi_cheophu = 0;
    int tong_tren_cheochinh = 0;
    int tong_duoi_cheophu = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Tính tổng đường chéo chính
            if (i == j) {
                tong_cheo_chinh += a[i][j];
            }

            // Tính tổng đường chéo phụ
            if (i + j == n - 1) {
                tong_cheo_phu += a[i][j];
            }

            // Tính tổng sát trên và sát dưới đường chéo chính
            if (j - i == 1) {
                tong_sattren_cheochinh += a[i][j];
            }
            if (i - j == 1) {
                tong_satduoi_cheochinh += a[i][j];
            }

            // Tính tổng sát trên và sát dưới đường chéo phụ
            if (i + j == n - 2) {
                tong_sattren_cheophu += a[i][j];
            }
            if (i + j == n) {
                tong_satduoi_cheophu += a[i][j];
            }

            // Tính tổng các phần tử nằm phía trên đường chéo chính
            if (i < j) {
                tong_tren_cheochinh += a[i][j];
            }

            // Tính tổng các phần tử nằm phía dưới đường chéo phụ
            if (i + j > n - 1) {
                tong_duoi_cheophu += a[i][j];
            }
        }
    }

    // Xuất kết quả
    cout << tong_cheo_chinh << endl;
    cout << tong_cheo_phu << endl;
    cout << tong_sattren_cheochinh + tong_satduoi_cheochinh << endl;
    cout << tong_sattren_cheophu + tong_satduoi_cheophu << endl;
    cout << tong_tren_cheochinh << endl;
    cout << tong_duoi_cheophu << endl;

    return 0;
}
