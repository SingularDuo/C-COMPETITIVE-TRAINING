#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define fast ios_base::sync_with_stdio(0);
#define endl "\n"
void init(){
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);
    fast;
}
signed main()
{
    fast;
    init();
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        map<int, int, greater<int>> pos; 

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]] = i; 
        }
        set<int> removed; 
        bool turnandy = false; 

        while (!pos.empty()) {
            auto it = pos.begin(); 
            int maxx = it->first;
            int poss = it->second;
            pos.erase(it); 
            vector<int> xoa;
            for (auto& p : pos) {
                if (p.second > poss) {
                    xoa.push_back(p.first);
                }
            }
            for (int v : xoa) {
                pos.erase(v);
            }

            turnandy = !turnandy;
        }
        if (turnandy) {
            cout << "BOB" << endl;
        } else {
            cout << "ANDY" << endl;
        }
    }
    return 0;
}
