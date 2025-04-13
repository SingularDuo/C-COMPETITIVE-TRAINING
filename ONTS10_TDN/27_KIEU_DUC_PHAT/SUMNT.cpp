#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Duyệt từng vị trí i để kiểm tra xem có phải đỉnh không
    for (int i = 1; i < n - 1; i++) {
        bool trai = true, phai = true;

        // Kiểm tra dãy tăng từ 0 -> i
        for (int j = 0; j < i; j++) {
            if (a[j] >= a[j + 1]) {
                trai = false;
                break;
            }
        }

        // Kiểm tra dãy giảm từ i -> n-1
        for (int j = i; j < n - 1; j++) {
            if (a[j] <= a[j + 1]) {
                phai = false;
                break;
            }
        }

        if (trai && phai) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
