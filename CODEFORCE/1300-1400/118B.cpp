#include <iostream>
#include <vector>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long
#define int long long
#define TOISETHIVOI signed main()

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> res;

    ll last = 1;
    vector<ll> size_of_stage = {1};

    for (ll i = 1; i <= n; i++) {
        last += 2;
        size_of_stage.push_back(last);
    }

    int idx = size_of_stage.size() - 2;
    while (idx >= 0) {
        size_of_stage.push_back(size_of_stage[idx]);
        idx--;
    }

    for (auto curr : size_of_stage) {
        vector<ll> sub(curr);
        ll l = 0, r = curr - 1;
        ll start = 0;
        while (l <= r) {
            sub[l] = start;
            sub[r] = start;
            start++;
            l++; r--;
        }
        res.push_back(sub);
    }
    ll space = n*2;
    bool up = true;
    for (const auto& row : res) {
        for(int i=0; i < space; i++)cout<<" ";
        for (int j = 0; j < row.size(); j++) {
            if(j == row.size()-1)cout<<row[j];
            else cout << row[j] << " ";
        }
        if(space == 0)
        {
            up = false;
        }
        if(up && space != 0)space-=2;
        else if(!up) space +=2;
        
        cout << endl;
    }
}

TOISETHIVOI {
    fast;
    bool multitest = false;

    if (multitest) {
        int t;
        cin >> t;
        while (t--) {
            solve();
        }
    } else {
        solve();
    }

    return 0;
}
