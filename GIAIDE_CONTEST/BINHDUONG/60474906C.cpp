/*
        _.-- ,.--.
      .'   .'     /
       @       |'..--------._
     /      \._/              '.
    /  .-.-                     \
   (  /    \                     \
   \      '.                  | #
    \       \   -.           /
     \       |    )._____.'   \
      "       |   /  \  |  \    )
    Kduckp       |   |./'  :__ \.-'
              '--'
*/
/*
 * Author: Kduckp
 * gend on: 2025-05-15 14:07:03
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
#define fi first
#define se second
#define si size()
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define pb push_back
#define TOISETHIVOI signed main()

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;

string s;
vector<string> res;
ll k;
ll ans = 0;
vector<string> fin;

string temp;

bool good(const string& expr, int k) {
    int sum = 0, num = 0;
    char sign = '+';
    size_t i = 0;

    if (expr[i] == '-') {
        sign = '-';
        i++;
    }

    while (i < expr.length()) {
        if (isdigit(expr[i])) {
            num = num * 10 + (expr[i] - '0');
        } else {
            sum += (sign == '+' ? num : -num);
            num = 0;
            sign = expr[i]; 
        }
        i++;
    }
    sum += (sign == '+' ? num : -num);

    return sum == k;
}

void gen(string curr, ll idx) {
    if (idx == curr.size()) {
        if(good(temp, k)) {
            res.push_back(temp);
        }
        return;
    }

    temp += curr[idx];
    gen(curr, idx + 1);
    temp.pop_back();

    if(idx > 0) {
        temp += '+';
        temp += curr[idx];
        gen(curr, idx + 1);
        temp.pop_back();
        temp.pop_back();
    }
    

    temp += '-';
    temp += curr[idx];
    gen(curr, idx + 1);
    temp.pop_back();
    temp.pop_back();
}

signed main() {
    fast;
    cin >> s >> k;
    gen(s, 0);

    ans = res.size();
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    
    cout << ans << endl;
    for (const auto &expr : res) {
        cout << expr << endl;
    }

    return 0;
}