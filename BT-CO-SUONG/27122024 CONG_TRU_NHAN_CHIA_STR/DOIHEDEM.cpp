#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

void init(){
    freopen("DOIHEDEM.inp", "r", stdin);
    freopen("DOIHEDEM.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int comparee(const str &a, const str &b) {
    if (a.length() > b.length()) return 1;
    if (a.length() < b.length()) return -1;
    return a.compare(b);
}

str tru(const str &a, const str &b) {
    str result = "";
    int borrow = 0;
    int n1 = a.length(), n2 = b.length();

    for (int i = 0; i < n1; i++) {
        int digit1 = a[n1 - 1 - i] - '0';
        int digit2 = (i < n2) ? b[n2 - 1 - i] - '0' : 0;

        int diff = digit1 - digit2 - borrow;
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

    return result.empty() ? "0" : result;
}

str nhan(str s1, str s2) {
    int n = s1.size(), m = s2.size();
    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (s1[i] - '0') * (s2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    str res = "";
    bool leadingZero = true;
    for (int num : result) {
        if (num == 0 && leadingZero) continue;
        leadingZero = false;
        res += to_string(num);
    }

    return res.empty() ? "0" : res;
}

str cong(const str &a, const str &b) {
    // Simple addition for large numbers
    int carry = 0;
    str result = "";
    int n1 = a.size(), n2 = b.size();
    int i = n1 - 1, j = n2 - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? a[i] - '0' : 0;
        int digit2 = (j >= 0) ? b[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result = char(sum % 10 + '0') + result;

        i--;
        j--;
    }

    return result;
}

str sodu(const str &s1, const str &s2) {
    str temp = s1;
    while (comparee(temp, s2) >= 0) {
        temp = tru(temp, s2);
    }
    return temp;
}  
string csa_10(string x, str a) {
    string ans = "", curr;
    string to16 = "0123456789ABCDEF";

    for (int i = 0; i < x.size(); i++) {
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

str decimalToBase(int s, int base) {
    str result = "";
    
    while (s > 0) {
        int remainder = s % base;
        char digit = (remainder < 10) ? '0' + remainder : 'A' + remainder - 10;
        result = digit + result;
        s /= base;
    }

    return (result == "") ? "0" : result;
}

int main() {
    init();
    str s;
    getline(cin, s); 
    ll a, b;
    cin >> a >> b; 
    str a1 = to_string(a);
    int thapphan = stoi(csa_10(s, a1));  
    str ketqua = decimalToBase(thapphan, b);
    cout << ketqua << endl;
    return 0;
}
