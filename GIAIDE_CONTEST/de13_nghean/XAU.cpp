#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
void init()
{
	freopen("XAU.inp", "r", stdin);
	freopen("XAU.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

signed main() {
	//init();
    int l;
    string s;
    cin >> l >> s;

    int maxx = 0;

    for (int winSize = 1; winSize <= l / 2; winSize++) {
        unordered_set<string> seen;
        bool found = false;

        for (int i = 0; i + winSize <= l; i++) {
            string sub = s.substr(i, winSize);
            if (seen.find(sub) != seen.end()) {
                maxx = max(maxx, winSize);
                found = true;
                break; 
            }
            seen.insert(sub);
        }
    }

    cout << maxx << endl; 
    return 0;
}

