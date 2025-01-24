#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int maxn = 1e5;
const int MOD = 1e9 + 7;
bool isprime[maxn + 1];
void init(){
    freopen("TONGUOC.INP","r", stdin);
    freopen("TONGUOC.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void sieve() {
    for (int i = 0; i <= maxn; i++) isprime[i] = true;
    isprime[1] = isprime[0] = false;
    for (int i = 2; i * i <= maxn; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
}

ll legendre(ll n, ll p) {
    ll cnt = 0;
    if (!isprime[p]) return cnt;
    while (n > 0) {
        cnt += n / p;
        n /= p;
    }
    return cnt;
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
    if (res.empty()) return "0";
    else return res;
}

int main() {
    //init();
    sieve();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> souoc;
    for (ll i = 2; i <= 100; i++) {
        ll so_mu = legendre(n, i);
        if (so_mu > 0) souoc.push_back({i, so_mu});
    }
    string uoc = "1";
    // so uoc
    for(int i = 0; i < souoc.size();i++){
        uoc = nhan(to_string(souoc[i].second +1), uoc);
    }
    string tonguoc = "1";
    // Tính tổng ước đúng với công thức
    for (int i = 0; i < souoc.size(); i++) {
        string currentval = "1";
        string power = "1"; // p^0 = 1
        for (int j = 1; j <= souoc[i].second; j++) {
            power = nhan(power, to_string(souoc[i].first));
            currentval = cong(currentval, power);
        }
        tonguoc = nhan(tonguoc, currentval);
    }
    cout<<uoc<<endl;
    cout << tonguoc;
    return 0;
}
