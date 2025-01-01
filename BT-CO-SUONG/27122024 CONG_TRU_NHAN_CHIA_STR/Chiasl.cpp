#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
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
string tru(string a, string b){
    ll len = max(a.size(), b.size());
     vector<int> res(len, 0);
    ll carry = 0;
    
    while (a.size() < len) a = "0" + a;
    while (b.size() < len) b = "0" + b;
    for(int i = len - 1; i >= 0; i--){
        int sub_a = a[i] - '0';
        int sub_b = b[i] - '0';
        ll kq = sub_a - sub_b - carry;
        if(kq<0){
            kq += 10;
            carry = 1;
        }
        else carry = 0;
        res[i] = kq;
    }
    bool lead = true;
    string result ="";
    for(int i = 0; i <= len-1; i++){
        if(res[i] == 0 && lead == true)continue;
        lead = false;
        result = to_string(res[i]) + result;
    }
    reverse(result.begin(), result.end());
    return result;
}
int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);

}