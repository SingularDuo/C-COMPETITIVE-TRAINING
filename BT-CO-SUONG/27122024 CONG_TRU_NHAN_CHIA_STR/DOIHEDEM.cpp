#include <bits/stdc++.h>
using namespace std;
#define str string
int a, b;

void init() {
    freopen("DOIHEDEM.inp", "r", stdin);
    freopen("DOIHEDEM.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

str nhan(const str &num, int multiplier) {
    int carry = 0;
    str result = "";

    for (int i = num.size() - 1; i >= 0; i--) {
        int digit = num[i] - '0';
        int product = digit * multiplier + carry;
        carry = product / 10;
        result = char((product % 10) + '0') + result;
    }

    if (carry > 0) result = char(carry + '0') + result;
    return result;
}

str cong(str a, str b) {
    size_t len_a = a.size(); 
    size_t len_b = b.size();
    size_t len = max(len_a, len_b);
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

    str result = "";
    bool leading_zero = true;
    for (size_t i = 0; i <= len; i++) {
        if (res[i] == 0 && leading_zero) continue;
        leading_zero = false;
        result += (res[i] + '0');
    }
    if (leading_zero) result = "0";
    return result;
}

str csa_10(str x) {
    str ans = "", curr;
    str to16 = "0123456789ABCDEF";
    for (size_t i = 0; i < x.size(); i++) { 
        ans = nhan(ans, a);
        for (int p = 0; p < 16; p++) {
            if (x[i] == to16[p]) {
                curr = "";
                while (p) {
                    curr = (char)(p % 10 + 48) + curr;
                    p /= 10;
                }
                break;
            }
        }
        ans = cong(ans, curr);
    }

    return ans;
}
str chuyenveb(const str &thapphan, int b) {
    str result = "";
    str value = thapphan;

    while (value != "0") {
        str quotient = "";
        int remainder = 0;

        for (char c : value) {
            int current = remainder * 10 + (c - '0');
            quotient += (current / b) + '0';
            remainder = current % b;
        }

        result = (char)((remainder < 10) ? '0' + remainder : 'A' + remainder - 10) + result;
        while (quotient.size() > 1 && quotient[0] == '0') quotient.erase(0, 1);
        value = quotient;
    }

    return result.empty() ? "0" : result;
}

int main() {
    init();
    str s;
    getline(cin, s);

    cin >> a >> b;

    str thapphan = csa_10(s);

    str result = chuyenveb(thapphan, b);
    cout << result << endl;
    return 0;
}
