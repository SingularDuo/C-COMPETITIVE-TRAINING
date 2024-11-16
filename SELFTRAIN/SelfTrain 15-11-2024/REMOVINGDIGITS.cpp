#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int MOD = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    while (n > 0) {
        string s = to_string(n);
        char max_digit = *max_element(s.begin(), s.end());
        n -= (max_digit - '0');
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
/*
20
co the tru 2 hoac 0
18
co the tru 1 hoac 8
10
co the tru 1 hoac 0
9
chi co the tru 9
= 0
*/
/*
68
6868686868686868686868686868
*/