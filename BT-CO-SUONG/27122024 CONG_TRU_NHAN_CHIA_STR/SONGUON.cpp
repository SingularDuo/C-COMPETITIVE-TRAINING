#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
void init(){
    freopen("SONGUON.inp", "r", stdin);
    freopen("SONGUON.out", "w", stdout);
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

string tinhsonguon(string a) {
    string res = a;
    ll len = a.size();
    for (ll i = 0; i < len; i++) {
        char current = a[i];
        string current_str(1, current);
        res = cong(res, current_str);
    }
    return res;
}

string tru(const string& a, const string& b) {
    string result = "";
    int borrow = 0, diff = 0;
    int n1 = a.length(), n2 = b.length();
    for (int i = 0; i < n1; i++) {
        int digit1 = a[n1 - 1 - i] - '0';
        int digit2 = (i < n2) ? b[n2 - 1 - i] - '0' : 0;

        diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = char(diff + '0') + result;
    }
    
    while (result.length() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }

    return result;
}
bool cmp(string a, string b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a <= b;
}
int main() {
    init();
    string s, maxx, minn;
    getline(cin, s);
    
    string determine = "900";
    if (s >= determine) {
        minn = tru(s, determine);
    } else {
        minn = "1";
    }
    maxx = cong(s, determine);
    while (cmp(minn, maxx)) {
        if (tinhsonguon(minn) == s) {
            cout << minn;
            return 0;
        } else {
            string can = "1";
            minn = cong(minn, can);
        }
    }
    cout << "0";
    return 0;
}
