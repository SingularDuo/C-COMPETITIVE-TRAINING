#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int comparee(const string& a, const string& b) {
    if (a.length() > b.length()) return 1;
    if (a.length() < b.length()) return -1;
    return a.compare(b);
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
    if(res.empty())return "0"   ;
    else return res;
}
string chia(const string& s1, const string& s2) {
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
string mod(const string& s1, const string& s2){
    string result = chia(s1, s2);
    string multiply = nhan(s2,result);
    string du = tru(s1, multiply);
    return du;
}
string pew(string s1,long long y)
{
    string ans="1";
    for(long long i=1;i<=y;i++){
        ans=nhan(ans,s1);
    }
    return ans;
}
const long long maxn=1e6+5;
long long x[maxn];
string asang10(string s11, long long a) {
    string n = "0";
    for(long long i = 0; i < s11.size(); i++) {
        if(isalpha(s11[i])) {
            n = cong(n, nhan(pew(to_string(a), s11.size() - i - 1), to_string(s11[i] - 'A' + 10)));
        } else {
            n = cong(n, nhan(pew(to_string(a), s11.size() - i - 1), to_string(s11[i] - '0')));
        }
    }
    return n;
}

int main()
{
    //freopen("2_8.inp","r",stdin);
    //freopen("2_8.out","w",stdout);
    long long cnt=0,m;
    string s,mb;
    getline(cin,s);
    cin>>m;
    /*while(comparee(n,"0")>0){
        x[cnt]=stoi(mod(n,b));
        n=chia(n,b);
        cnt++;
    }
    for(long long i=cnt-1;i>=0;i--) cout<<x[i];*/
    cout<<asang10(s,m);
    return 0;
}