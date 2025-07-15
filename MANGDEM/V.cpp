/*
        _.-- ,.--.
      .'   .'     /
       @       |'..--------._
     /      \._/              '.
    /  .-.-                     \
   (  /    \                     \
   \      '.                  | #
    \       \   -.           /
     :\       |    )._____.'   \
      "       |   /  \  |  \    )
    Kduckp       |   |./'       
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e6 + 5;
int cnt[N];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int c = 1; c * c <= n; c++) {
        for (int d = 1; c * d <= n; d++) {
            cnt[c * d]++;
        }
    }

    int res = 0;

    for (int a = 1; a * a <= n; a++) {
        for (int b = 1; a * b <= n; b++) {
            int s = a * b;
            if (n - s >= 0)
                res += cnt[n - s];
        }
    }

    cout << res << endl;
    return 0;
}
