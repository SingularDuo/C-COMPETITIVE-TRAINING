#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define endl "\n"

signed main()
{
    string s; 
    cin >> s;
    string res = "";

    for(int i = 0; i < s.size(); i++)
    {
        int cnt = 1;
        while(i + 1 < s.size() && s[i] == s[i + 1])
        {
            cnt++;
            i++;
        }
        if (cnt != 1) {
            res += to_string(cnt) + s[i];
        }
        else res += s[i];
    }
    
    cout << res;
}
