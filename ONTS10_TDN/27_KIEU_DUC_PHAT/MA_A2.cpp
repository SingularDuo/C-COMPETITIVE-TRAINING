#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int counts = 0;
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            if (i != N) counts += i;
            if (i != N / i && N / i != N) counts += N / i;
        }
    }

    cout << counts << endl;
    return 0;
}
