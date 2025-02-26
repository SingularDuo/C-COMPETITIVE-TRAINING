#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string s;
        cin >> s;
        int q;
        cin >> q;

        set<int> pos;

        for (int i = 0; i <= (int)s.size() - 4; i++)
        {
            if (s.substr(i, 4) == "1100")
                pos.insert(i);
        }

        while (q--)
        {
            int idx, val;
            cin>>idx>>val;
            idx--;

            for (int i = max(0LL, idx - 3); i <= idx; i++)
            {
                if (i + 3 < (int)s.size() && s.substr(i, 4) == "1100")
                    pos.erase(i);
            }

            s[idx] = (char)(val + '0');

            for (int i = max(0LL, idx - 3); i <= idx; i++)
            {
                if (i + 3 < (int)s.size() && s.substr(i, 4) == "1100")
                    pos.insert(i);
            }

            cout << (pos.empty() ? "NO" : "YES") << endl;
        }
    }
}
