#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("XAUDX.inp", "r", stdin);
    freopen("XAUDX.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool isDX(string s) {
    string s3 = s;
    reverse(s3.begin(), s3.end());
    return s == s3; 
}

int main() {
    init();
    string s;
    getline(cin, s);
    int n = s.length();
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string c = s.substr(i, j - i + 1);
            if (isDX(c)) {
                int current = c.size();
                maxx = max(maxx, current);
            }
        }
    }
    cout << maxx << endl;
    return 0;
}
