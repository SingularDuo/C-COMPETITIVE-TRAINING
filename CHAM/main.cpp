#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int MAX = 1005;
int a[MAX][MAX];
//
//void trau() {
//
//}
//
//void full() {
//
//}
//
//void solve() {
//    if(n <= 100) {
//        trau();
//    } else{
//        full();
//    }
//}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    ll res = 0;
    ll start = 1;
    int digits = 1;

    while (start <= n) {
        ll end = start * 10 - 1;
        if (n < end) end = n;

        ll count = end - start + 1;
        res += count * digits;
        start *= 10;
        digits++;
    }

    cout << res << endl;
    return 0;
}
/*
5 6
3 5 6 8 19 7
1 3 4 6 7 12
13 15 17 50 5 7
25 3 2 6 8 9
5 8 5 8 6 9
*/
/*
5 5
2 3 14 5 1
3 2 1 4 5
2 9 3 6 7
4 2 7 9 2
4 6 4 6 8
*/
