#include <bits/stdc++.h>
using namespace std;

bool soam(const string &num) {
    return num[0] == '-';


string removeLeadingZeros(const string &num) {
    string result = num;
    while (result.length() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }
    return result;
}

string tru(const string &a, const string &b); 

string cong(string a, string b) {
    if (soam(a) && soam(b)) {
        return "-" + cong(a.substr(1), b.substr(1));
    }
    if (soam(a)) return tru(b, a.substr(1));
    if (soam(b)) return tru(a, b.substr(1));

    int len_a = a.size();
    int len_b = b.size();
    int len = max(len_a, len_b);
    vector<int> res(len + 1, 0);
    int carry = 0;

    while (a.size() < len) a = "0" + a;
    while (b.size() < len) b = "0" + b;

    for (int i = len - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        res[i + 1] = sum % 10;
        carry = sum / 10;
    }
    res[0] = carry;

    string result = "";
    for (int i = 0; i <= len; i++) {
        result += (res[i] + '0');
    }
    result = removeLeadingZeros(result);
    return result;
}

string tru(const string &a, const string &b) {
    if (soam(a) && soam(b)) {
        return tru(b.substr(1), a.substr(1));
    }
    if (soam(a)) return "-" + cong(a.substr(1), b);
    if (soam(b)) return cong(a, b.substr(1));

    if (a < b) return "-" + tru(b, a);

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
    result = removeLeadingZeros(result);
    return result;
}

string divideByTwo(const string &num) {
    bool negative = soam(num);
    string absNum = negative ? num.substr(1) : num;

    string result = "";
    int carry = 0;

    for (char digit : absNum) {
        int current = carry * 10 + (digit - '0');
        result += (current / 2) + '0';
        carry = current % 2;
    }

    result = removeLeadingZeros(result);
    if (negative && carry != 0) {
        result = tru(result, "1");
    }
    return negative ? "-" + result : result;
}

int main() {
    string a, b;
    cin >> a >> b;

    string tong = cong(a, b);
    string hieu = tru(a, b);
    string res1 = divideByTwo(tong);
    string res2 = divideByTwo(hieu);

    cout << res1 << endl;
    cout << res2;
}
