#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define endl  "\n"

vector<char> nguyen = {'a', 'e', 'i', 'o', 'u'};
signed main()
{
    //freopen("09B.INP", "r", stdin);
    //freopen("09B.out", "w", stdout);
    string s;
    cin >> s;

    vector<int> phu_pos, nguyen_pos;

    for (int i = 0; i < s.size(); i++) {
        bool phu = true;
        for (char c : nguyen) {
            if (s[i] == c) {
                phu = false;
                break;
            }
        }
        if (phu) {
            phu_pos.push_back(i);
        } else {
            nguyen_pos.push_back(i);
        }
    }

    int res = 0;
    for (int nguyen_idx : nguyen_pos) {
        auto it = lower_bound(phu_pos.begin(), phu_pos.end(), nguyen_idx);
        if (it != phu_pos.end()) {
            //cout<<nguyen_idx<<" "<<*it<<" "<<distance(it, phu_pos.end())<<endl;
            res += distance(it, phu_pos.end());
        }
    }
    for(int phu_idx : phu_pos)
    {
        auto it = lower_bound(nguyen_pos.begin(), nguyen_pos.end(), phu_idx);
        if( it != nguyen_pos.end())
        {
            res += distance(it, nguyen_pos.end());
        }
    }

    cout << res << endl;
    return 0;
}