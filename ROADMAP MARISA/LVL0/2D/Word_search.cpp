#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT
{
    fast;
    int n, m;
    string s;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    cin >> s;
    ll sai = s.size();
    vector<vector<char>> row, column;

    for (int i = 0; i < n; i++)
    {
        vector<char> current;
        for (int j = 0; j < m; j++) current.push_back(a[i][j]);
        row.push_back(current);
    }

    for (int i = 0; i < m; i++)
    {
        vector<char> current;
        for (int j = 0; j < n; j++) current.push_back(a[j][i]); 
        column.push_back(current);
    }

    for (int i = 0; i < row.size(); i++)
    {
        vector<char> current = a[i];
        for (int j = 0; j < current.size(); j++)
        {
            string curr = "";
            if (j + sai > current.size()) break;
            for (int k = j; k < j + sai; k++)
            {
                curr = curr + current[k];
            }
            if (curr == s)
            {
                cout << "YES";
                return 0;
            }
            curr = "";
            for (int k = j + sai - 1; k >= j; k--) curr = curr + current[k];
            if (curr == s)
            {
                cout << "YES";
                return 0;
            }
        }
    }

    for (int i = 0; i < column.size(); i++) 
    {
        vector<char> current = column[i];
        for (int j = 0; j < current.size(); j++) 
        {
            string curr = "";
            if (j + sai > current.size()) break;
            for (int k = j; k < j + sai; k++) 
            {
                curr = curr + current[k];
            }
            if (curr == s) 
            {
                cout << "YES";
                return 0;
            }
            curr = "";
            for (int k = j + sai - 1; k >= j; k--) 
            {
                curr = curr + current[k];
            }
            if (curr == s) 
            {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO"; 
    return 0;
}
