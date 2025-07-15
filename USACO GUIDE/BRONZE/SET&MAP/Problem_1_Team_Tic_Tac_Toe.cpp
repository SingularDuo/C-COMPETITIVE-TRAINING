/*
        _.-- ,.--.
      .'   .'     /
       @       |'..--------._
     /      \._/              '.
    /  .-.-                     \
   (  /    \                     \
   \      '.                  | #
    \       \   -.           /
     :\       |    )._____.'   \
      "       |   /  \  |  \    )
    Kduckp       |   |./'  :__ \.-'
              '--'
*/
/*
 * Author: Kduckp
 * Generated on: 2025-07-12 16:59:45
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vi>

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define EACH(x, a) for (auto& x : a)

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define YESNO(x) cout << ((x) ? "YES\n" : "NO\n")

#define bitcount(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)
#define mp make_pair

#define debug(x)
#define lb lower_bound
#define ub upper_bound

#define __TOISETHIVOI__ signed main()
#define vec(a, b, c, d) vector<a> b(c, d)
#define allin(a, x) (find(all(a), x) != (a).end())
#define vec2d(type, name, r, c, val) vector<vector<type>> name((r), vector<type>((c), (val)))
#define vec3d(type, name, x, y, z, val) vector<vector<vector<type>>> name((x), vector<vector<type>>((y), vector<type>((z), (val))))

const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = 2e18;
const int N = 2e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;

void name(const string &inFile, const string &outFile) {
    freopen(inFile.c_str(), "r", stdin);
    freopen(outFile.c_str(), "w", stdout);
}

void init() {
    fast;
    name("tttt.in", "tttt.out");
}

__TOISETHIVOI__ {
    init();

    vector<vector<char>> a(3, vector<char>(3));
    FOR(i, 3) {
        string s; cin >> s;
        FOR(j, 3) {
            a[i][j] = s[j];
        }
    }

    set<char> solo_win; // những con bò chiến thắng một mình
    set<pair<char, char>> team_win; // những cặp bò chiến thắng cùng nhau

    // mô tả 8 hàng/cột/chéo có thể tạo chiến thắng
    vector<vector<pii>> lines = {
        {mp(0,0), mp(0,1), mp(0,2)}, {mp(1,0), mp(1,1), mp(1,2)}, {mp(2,0), mp(2,1), mp(2,2)}, // hàng
        {mp(0,0), mp(1,0), mp(2,0)}, {mp(0,1), mp(1,1), mp(2,1)}, {mp(0,2), mp(1,2), mp(2,2)}, // cột
        {mp(0,0), mp(1,1), mp(2,2)}, {mp(0,2), mp(1,1), mp(2,0)}  // chéo
    };

    for (int i = 0; i < (int)lines.size(); ++i) {
        set<char> cows;
        for (int j = 0; j < 3; ++j) {
            int x = lines[i][j].first;
            int y = lines[i][j].second;
            cows.insert(a[x][y]);
        }
        if (cows.size() == 1) {
            solo_win.insert(*cows.begin());
        } else if (cows.size() == 2) {
            set<char>::iterator it = cows.begin();
            char c1 = *it;
            ++it;
            char c2 = *it;
            if (c1 > c2) swap(c1, c2);
            team_win.insert(mp(c1, c2));
        }
    }

    cout << solo_win.size() << endl;
    cout << team_win.size() << endl;

    return 0;
}
