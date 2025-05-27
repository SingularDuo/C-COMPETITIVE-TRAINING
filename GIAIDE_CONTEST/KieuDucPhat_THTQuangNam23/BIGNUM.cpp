#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
void init()
{
    freopen("BIGNUM.inp", "r", stdin);
    freopen("BIGNUM.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void remove_letters(string &s) {
    string temp = "";
    for (char c : s) {
        if (isdigit(c)) temp += c;
    }
    s = temp;
}

signed main() {
    init();
    string s;
    cin >> s;
    int k;
    cin >> k;
    remove_letters(s);
    if (s.size() <= k) {
        return 0;
    }

    int to_delete = s.size() - k;
    string result = "";

    for (char c : s) {
        while (!result.empty() && result.back() < c && to_delete > 0) {
            result.pop_back();
            to_delete--;
        }
        result.push_back(c);
    }

    result = result.substr(0, k);

    cout << result << endl;
    return 0;
}
