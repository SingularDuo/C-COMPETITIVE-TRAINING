#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
void init() {
    freopen("Chiasl.INP", "r", stdin);
    freopen("Chiasl.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int comparee(const string& a, const string& b) {
    if (a.length() > b.length()) return 1;
    if (a.length() < b.length()) return -1;
    return a.compare(b);
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
string divide(const string& s1, const string& s2) {
    string quotient = "";
    string current = "";
    for (char digit : s1) {
        current += digit;
        while (current.length() > 1 && current[0] == '0') {
            current.erase(0, 1);
        }

        int count = 0;
        while (comparee(current, s2) >= 0) {
            current = tru(current, s2);
            count++;
        }
        quotient += char(count + '0');
    }
    while (quotient.length() > 1 && quotient[0] == '0') {
        quotient.erase(0, 1);
    }

    return quotient;
}
string nhan(string s1, string s2) {
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
    string res = "";
    bool leadingZero = true;
    for (int num : result) {
        if (num == 0 && leadingZero) continue; 
        leadingZero = false;
        res += to_string(num);
    }
    if(res.empty())return 0;
    else return res;
}
int main() {
    init();
    string num1, num2;
    cin >> num1;
    cin >> num2;
    string result = divide(num1, num2);
    string multiply = nhan(num2, result);
    string du = tru(num1, multiply);
    cout<<result<<endl;
    cout<<du;

    return 0;
}
