#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define endl "\n"

const int sub1 = 1e4;
signed main()
{
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    if (n <= sub1) {
        ll res = 0;

        for (int i = 0; i < n; i++) {
            ll sum = 0;
            string curr = "";
            if(s[i] == '0')res++;
            for (int j = i; j < n; j++) {
                sum += s[j] - '0';
                curr += s[j];

                if (sum % 3 == 0 && curr.size() >= 2) {
                    string check = curr.substr(curr.size() - 2);

                    if (check == "25" || check == "50" || check == "75" ||check == "00" ) {
                        res++;
                    }
                }
            }
        }
        cout << res;
        return 0;
    }

    return 0;
}
