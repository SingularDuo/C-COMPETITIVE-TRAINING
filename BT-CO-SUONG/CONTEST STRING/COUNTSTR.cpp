#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
#define ll long long
const int mod = 1e9 + 7;
const int INF = 1e9;
int cnt[26];
int last[26];

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    memset(last, -1, sizeof last);
    ll res = 0;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < 26; c++)
        {
            if (s[r] != 'a' + c && last[c] != -1)
                res += last[c];
        }
        last[s[r] - 'a'] = r;
    }
    cout << res << "\n";
    return 0;
}
