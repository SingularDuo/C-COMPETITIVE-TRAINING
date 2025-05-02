#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

void sol() {
    string s;
    int k;
    cin >> s >> k;

    string result = "";
    int keep = s.size() - k;
    
    for (char c : s) {
        while (!result.empty() && result.back() < c && k > 0) {
            result.pop_back();
            k--;
        }
        result.push_back(c);
    }

    // Resize the result to maintain exactly 'keep' characters
    result.resize(keep);
    
    cout << result << endl;
}

KING_PHAT {
    fast;
    sol();
    return 0;
}
