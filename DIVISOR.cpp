#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void phanTichNguyenTo(int n, map<int, int> &luuThuaSo) {
    while (n % 2 == 0) {
        luuThuaSo[2]++;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            luuThuaSo[i]++;
            n /= i;
        }
    }
    if (n > 2) {
        luuThuaSo[n]++;
    }
}

int main() {
    int m;
    cin >> m;
    map<int, int> luuThuaSo;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        phanTichNguyenTo(a, luuThuaSo);
    }
    long long soLuongUoc = 1;
    for (auto &it : luuThuaSo) {
        soLuongUoc = soLuongUoc * (it.second + 1) % MOD;
    }
    cout << soLuongUoc << endl;
    return 0;
}
