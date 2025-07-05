#include <bits/stdc++.h>
using namespace std;

void init()
{
    freopen("TONG.INP", "r", stdin);
    freopen("TONG.OUT", "w", stdout);
}
string add(const string &A, const string &B) {
    string a = A, b = B;
    while (a.size() < b.size()) a = '0' + a;
    while (b.size() < a.size()) b = '0' + b;
    string res;
    int carry = 0;
    for (int i = a.size()-1; i >= 0; i--) {
        int s = (a[i]-'0') + (b[i]-'0') + carry;
        res.push_back(char('0' + (s % 10)));
        carry = s / 10;
    }
    if (carry) res.push_back(char('0' + carry));
    reverse(res.begin(), res.end());
    return res;
}

string sub(const string &A, const string &B) {
    string a = A, b = B;
    while (b.size() < a.size()) b = '0' + b;
    string res(a.size(), '0');
    int borrow = 0;
    for (int i = a.size()-1; i >= 0; i--) {
        int x = (a[i]-'0') - (b[i]-'0') - borrow;
        if (x < 0) { x += 10; borrow = 1; }
        else borrow = 0;
        res[i] = char('0' + x);
    }
    size_t pos = res.find_first_not_of('0');
    if (pos == string::npos) return "0";
    return res.substr(pos);
}

string multiply(const string &A, const string &B) {
    int n = A.size(), m = B.size();
    vector<int> tmp(n + m, 0);
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            tmp[i+j+1] += (A[i]-'0') * (B[j]-'0');
        }
    }
    for (int i = n+m-1; i > 0; i--) {
        if (tmp[i] >= 10) {
            tmp[i-1] += tmp[i] / 10;
            tmp[i] %= 10;
        }
    }
    string res;
    for (int v : tmp) res.push_back(char('0' + v));
    size_t pos = res.find_first_not_of('0');
    if (pos == string::npos) return "0";
    return res.substr(pos);
}

string div2(const string &A) {
    string res;
    int carry = 0;
    for (char c : A) {
        int x = carry*10 + (c - '0');
        res.push_back(char('0' + (x/2)));
        carry = x % 2;
    }

    size_t pos = res.find_first_not_of('0');
    if (pos == string::npos) return "0";
    return res.substr(pos);
}

signed main(){
    init();
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin >> n;

    string ntru = sub(n, "1");
    string nplus1  = add(n, "1");
    string nplus2  = add(n, "2");

    string t1 = multiply(n, ntru);
    string t2 = multiply(nplus1, nplus2);
    string te  = multiply(t1, t2);

    string res = div2(te);
    res = div2(res);

    cout << res << "\n";
    return 0;
}
