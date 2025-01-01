#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
void init(){
    freopen("M_mu_n.INP","r", stdin);
    freopen("M_mu_n.OUT", "w", stdout);
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

string nhan(string s1, string s2) {
    if (s1 == "0" || s2 == "0") return "0";

    if (s2.size() > s1.size()) swap(s1, s2);

    string res = "0";
    for (int i = s2.size() - 1; i >= 0; i--) {
        string s3 = "";
        int carry = 0;
        for (int j = s1.size() - 1; j >= 0; j--) {
            int kq = (s2[i] - '0') * (s1[j] - '0') + carry;
            carry = kq / 10;
            kq %= 10;
            s3 = to_string(kq) + s3;
        }
        if (carry > 0) {
            s3 = to_string(carry) + s3;
        }
        s3.append(s2.size() - 1 - i, '0');
        res = cong(res, s3);
    }
    return res;
}

int main() {
    init();
    str s1, s2;
    getline(cin, s1);
    int n;
    cin >> n;

    str res = s1;
    while (n > 1) {
        res = nhan(res, s1);
        n--;
    }
    cout << res;

    return 0;
}
