#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("BAI5.INP", "r",stdin);
    freopen("BAI5.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    int n, f, s;
    cin >> n >> f >> s;
    string moves;
    cin.ignore();
    getline(cin, moves); 

    ll a[n + 1][n + 1];
    ll run = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { 
            a[i][j] = run;
            run++;
        }
    }
    int curr_f = f; 
    int curr_s = s;

    int len = moves.size();
    for (int i = 0; i < len; i++) { 
        if (moves[i] == 'L') {
            curr_s++; 
        } else if (moves[i] == 'R') {
            curr_s--; 
        } else if (moves[i] == 'U') {
            curr_f++; 
        } else if (moves[i] == 'D') {
            curr_f--; 
        }
    }
    cout << a[curr_f][curr_s] << endl;

    return 0;
}
