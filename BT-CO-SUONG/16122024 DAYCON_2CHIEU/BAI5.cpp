#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 1e6+1;

void init() {
    freopen("BAI5.INP", "r", stdin);
    freopen("BAI5.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    //init();
    int n, f, s;
    cin >> n >> f >> s;
    string moves;
    cin.ignore();
    getline(cin, moves);
    if(n * n <= 1e6) {
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
            } 
            else if (moves[i] == 'R') {
                curr_s--; 
            } 
            else if (moves[i] == 'U') {
                curr_f++; 
            } 
            else if (moves[i] == 'D') {
                curr_f--; 
            }
        }
        cout << a[curr_f][curr_s] << endl;
        return 0;
    }
    ll start_val = (n * (f - 1)) + s;
    vector<ll> right_limit;
    vector<ll> left_limit;
    int i = 1;
    int currval = 1;
    int currval2 = n;
    
    while(i <= n) {
        left_limit.push_back(currval);
        right_limit.push_back(currval2);
        currval += n;
        currval2 += n;
        i++;
    }
    ll cuoi_dau = (n *(n-1)) + 1;
    ll cuoi_cuoi = n * n;
    int len = moves.size();
    for (int i = 0; i < len; i++) { 
        if (moves[i] == 'L') {
            if(find(right_limit.begin(), right_limit.end(), start_val) != right_limit.end()) {
                auto pos = find(right_limit.begin(), right_limit.end(), start_val) - right_limit.begin();
                start_val = left_limit[pos];
            } else {
                start_val++;
            }
        } else if (moves[i] == 'R') {
            if(find(left_limit.begin(), left_limit.end(), start_val) != left_limit.end()) {
                auto pos = find(left_limit.begin(), left_limit.end(), start_val) - left_limit.begin();
                start_val = right_limit[pos];
            } else {
                start_val--;
            }
        } 
        else if (moves[i] == 'U') {
            if(start_val >= cuoi_dau && start_val <= cuoi_cuoi){
                start_val = 1 + (start_val - cuoi_dau);
                continue;
            }
            else start_val += n;
        } 
        else if (moves[i] == 'D') {
                if(start_val >= 1 && start_val <= n){
                    start_val = (n*(n-1)+1)+(start_val-1);
                    continue;
                }
                else start_val %= n;
        }
    }
    cout << start_val << endl;
    return 0;
}