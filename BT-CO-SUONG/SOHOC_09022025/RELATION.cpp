#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, k;
    cin >> n >> k;
    ll countk = n / k; // so nguyen chia het cho k
    ll countk2 = (k % 2 == 0) ? (n / (k / 2) - countk) : 0; // so nguyen chia het cho k/2

    ll result = 0;

    if (k % 2 == 1) {
        // K lẻ: Chỉ có một trường hợp là tất cả đều chia hết cho K
        result = countk * countk * countk;
    } else {a
        // K chẵn: Hai trường hợp
        result = countk * countk * countk + countk2 * countk2 * countk2;
    }

    cout << result << endl;
    return 0;
}
