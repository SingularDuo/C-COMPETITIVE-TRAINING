#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    string s;
    cin >> s;
    char start = s[0];

    vector<vector<char>> rows(n, vector<char>(m));
    vector<vector<char>> columm(m, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rows[i][j] = a[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            columm[j][i] = a[i][j];
        }
    }
    for (auto &i : rows) {
        vector<char> current = i;
        for(int j = 0; j < current.size(); j++)
        {
            if(current[j] == start)
            {
                bool ap = true;
                ll idx = 0;
                for(int k = j; k < s.size(); k++)
                {
                    if(current[k] != s[idx])ap = false;
                    idx++;
                }
                if(ap)
                {
                    cout<<"YES";
                    return 0;
                }
            }
        }
    }
    for(auto& i : columm)
    {
        vector<char> current = i;
        for(int j = 0; j < current.size(); j++)
        {
            if(current[j] == start)
            {
                bool ap = true;
                ll idx = 0;
                for(int k = j; k < s.size(); k++)
                {
                    if(current[k] != s[idx])ap = false;
                    idx++;
                }
                if(ap)
                {
                    cout<<"YES";
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
    return 0;
}
