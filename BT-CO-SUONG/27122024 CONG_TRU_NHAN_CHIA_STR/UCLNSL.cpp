#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string

void init() {
    freopen("UCLNSL.inp", "r", stdin);
    freopen("UCLNSL.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
} 

vector<int> tru(const string& a, const string& b, ll len) {
    vector<int> res(len, 0);
    ll carry = 0;

    string sub_a = a;
    string sub_b = b;
    while (sub_a.size() < len) sub_a = "0" + sub_a;
    while (sub_b.size() < len) sub_b = "0" + sub_b;

    for (ll i = len - 1; i >= 0; i--) {
        int new_a = sub_a[i] - '0';
        int new_b = sub_b[i] - '0';
        int sub = new_a - new_b - carry;
        if (sub < 0) {
            sub += 10; 
            carry = 1;
        } else {
            carry = 0;
        }
        res[i] = sub; 
    }

    return res;
}

int main() {
    init(); 
    str a, b;
    getline(cin, a);
    getline(cin, b);
    ll len_a = a.size();
    ll len_b = b.size();
    ll len = max(len_a, len_b);
    vector<int> result;
    while (a != b) {
        if (a > b) {
            result = tru(a, b, len);
            a = ""; 
            for (auto digit : result) {
                a += to_string(digit);
            }
        } else {
            result = tru(b, a, len);
            b = ""; 
            for (auto digit : result) {
                b += to_string(digit);
            }
        }
        len = max(a.size(), b.size());
    }
    bool lead = true;
    for(int i = 0; i <= a.size()-1; i++){
        if(lead == true && a[i] == '0')continue;
        lead = false;
        cout<<a[i];
    }
    
    cout << endl;

    return 0;
}
