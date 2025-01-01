#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("GTSL.INP", "r", stdin);
    freopen("GTSL.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
string congsl(string a, string b){
    ll len = max(a.size(), b.size());
    while(a.size()<len) a = "0"+a;
    while(b.size() < len) b = "0" + b;
    ll carry = 0;
    vector<int> res(len+1,0);
    for(ll i = len -1; i >= 0; i--){
        int sum = (a[i] - '0') + (b[i]- '0')+carry;
        res[i+1] =  sum % 10;
        carry = sum / 10;
    }
    res[0] = carry;
    string result = "";
    bool lead = true;
    for(int i = 0; i <= len; i++){
        if(res[i] == 0 && lead == true)continue;
        lead = false;
        result = result + to_string(res[i]);
    }
    if(lead == true)result = "0";
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
    if(res.empty())return 0;
    else return res;
}
string giaithua(ll a){
    string res = "1"; 
    for(int i = 1; i <= a; i++){
        res = nhan(res, to_string(i));
    }
    return res;
}
int main(){
    init();
    ll n;
    cin >> n;
    //auto start = chrono::high_resolution_clock::now();
    string res = giaithua(n);
    cout << res << endl;
    //auto end = chrono::high_resolution_clock::now();
    //chrono::duration<double> duration = end - start;
    //cout << "Runtime: " << duration.count() << " seconds" << endl;

    return 0;
}