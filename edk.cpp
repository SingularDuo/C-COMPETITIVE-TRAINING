/*
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⡿⢿⡿⠿⠿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⡿⣿⣿
⣿⣿⣿⣿⠿⠿⢿⣿⣿⠟⣋⣭⣶⣶⣞⣿⣶⣶⣶⣬⣉⠻⣿⣿⡿⣋⣉⠻⣿⣿⣿
⣿⢻⣿⠃⣤⣤⣢⣍⣴⣿⢋⣵⣿⣿⣿⣿⣷⣶⣝⣿⣿⣧⣄⢉⣜⣥⣜⢷⢹⢇⢛
⡏⡦⡁⡸⢛⡴⢣⣾⢟⣿⣿⣿⢟⣾⣧⣙⢿⣿⣿⣿⣿⣿⣿⣿⢩⢳⣞⢿⡏⢷⣾
⣷⣵⡇⣗⡾⢁⣾⣟⣾⣿⡿⣻⣾⣿⣿⣿⡎⠛⡛⢿⣿⡟⣿⣿⡜⡜⢿⡌⠇⢾⣿
⣿⣿⠁⣾⠏⣾⣿⣿⣽⣑⣺⣥⣿⣿⣿⣿⣷⣶⣦⣖⢝⢿⣿⣿⣿⡀⠹⣿⣼⢸⣿
⣿⣿⢰⡏⢡⣿⣿⠐⣵⠿⠛⠛⣿⣿⣿⣿⣿⠍⠚⢙⠻⢦⣼⣿⣿⠁⣄⣿⣿⠘⣿
⣿⣿⢸⢹⢈⣿⣿⠘⣡⡞⠉⡀⢻⣿⣿⣿⣿⢃⠠⢈⢳⣌⣩⣿⣿⠰⠿⢼⣿⠀⣿
⣿⠿⣘⠯⠌⡟⣿⡟⣾⣇⢾⡵⣹⣟⣿⣿⣿⣮⣓⣫⣿⣟⢿⣿⢿⡾⡹⢆⣦⣤⢹
⣅⣛⠶⠽⣧⣋⠳⡓⢿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣫⣸⠏⡋⠷⣛⣫⡍⣶⣿
⣿⡿⢸⢳⣶⣶⠀⡇⣬⡛⠿⣿⣿⣿⣿⣿⣿⣿⠿⢟⣉⣕⡭⠀⢺⣸⣽⢻⡅⣿⣿
⣿⡇⣾⡾⣰⡯⠀⡗⣯⣿⣽⡶⠶⠂⢠⣾⣿⠐⠚⠻⢯⣿⠇⠎⡀⣳⣿⣼⡃⣿⣿
⣿⡇⣟⣇⡟⣧⠀⡗⣿⣿⡿⢡⢖⣀⠼⢟⣻⣤⣔⢦⢸⣿⢀⢆⢡⣿⣯⢹⡃⣿⣿
⣿⡇⡏⣿⡾⣸⣿⣇⠸⠟⣋⣼⣼⣿⢻⣿⣿⢿⣟⢾⣌⠫⠈⣶⣿⡿⣩⡿⢃⣿⣿
⣿⣷⡀⠻⡷⢪⢧⡙⠰⣾⣿⣿⣾⡽⣾⣿⡿⣺⣵⣾⣿⡇⡜⣽⠟⢷⣪⣴⣿⣿⣿
⣿⣿⣿⣾⣿⠏⣤⡁⣷⣽⣿⣿⣿⣿⣷⣶⣿⣿⣿⣿⣿⣱⠸⣱⣦⠙⣿⣿⣿⣾⣿

Created on : hh/mm/ss/dd/mm/yy by kduckp


*/

/*
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC target("popcnt")
#pragma GCC target("sse4")
#pragma GCC target("sse4.2")
#pragma GCC target("fma")
#pragma GCC target("bmi,bmi2,lzcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
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
#define FOR(i, n) for (int i = 1; i <= (n); ++i)
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
#define debug(x)
#define lb lower_bound
#define ub upper_bound
#define __TOISETHIVOI__ signed main()
#define vec(a, b, c, d) vector<a> b(c, d)

    const int MOD = 1e9 + 7;
    const int MOD2 = 998244353;
    const int INF = 2e18;
    const int N = 2e5 + 5;
    const int LOG = 20;
    const double PI = acos(-1);
    const double EPS = 1e-9;

void init() {
    fast;
}

void solve() {
    // your code here
}

__TOISETHIVOI__ {
    init();
    solve();
    return 0;
}