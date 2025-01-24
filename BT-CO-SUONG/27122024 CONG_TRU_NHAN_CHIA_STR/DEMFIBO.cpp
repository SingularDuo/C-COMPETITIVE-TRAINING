#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("DEMFIBO.INP", "r", stdin);
    freopen("DEMFIBO.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string cong(string a, string b) {
    ll len_a = a.size();
    ll len_b = b.size();
    ll len = max(len_a, len_b);
    vector<int> res(len + 1, 0);
    ll carry = 0;
    while (a.size() < len) a = "0" + a;
    while (b.size() < len) b = "0" + b;
    for (ll i = len - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        res[i + 1] = sum % 10;
        carry = sum / 10;
    }
    res[0] = carry;
    string result = "";
    bool leading_zero = true;
    for (int i = 0; i <= len; i++) {
        if (res[i] == 0 && leading_zero) continue;
        leading_zero = false;
        result += (res[i] + '0');
    }
    if (leading_zero) result = "0";
    return result;
}

const int maxn = 1005;
vector<string> fib(maxn, ""); 

void fibo() {
    fib[0] = "1";
    fib[1] = "1";    
    for (int i = 2; i < maxn; i++) {
        fib[i] = cong(fib[i - 1], fib[i - 2]);
        if (fib[i].size() > 210) break; 
    }
}

bool valid(string a, string b, string c) {
    ll len = max(max(a.size(), b.size()), c.size());
    while (a.size() < len) a = "0" + a;
    while (b.size() < len) b = "0" + b;
    while (c.size() < len) c = "0" + c;
    return (b >= a && b <= c);
}

int main() {
    init();
    fibo();
    string A, B;
    getline(cin, A);
    getline(cin, B);
    ll cnt = 0;
    for (int i = 0; i < maxn; i++) {
        if (valid(A, fib[i], B)) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
