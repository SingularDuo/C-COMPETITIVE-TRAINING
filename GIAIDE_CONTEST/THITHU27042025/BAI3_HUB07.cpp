#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;

bool multitest = false;

string tru(const string& a, const string& b) {
    string result = ""; // o(1)
    int borrow = 0, diff = 0; // o(1)
    int n1 = a.size(), n2 = b.size(); //o(1)

    for (int i = 0; i < n1; i++) { // o(n)
        int digit1 = a[n1 - 1 - i] - '0'; // o(1)
        int digit2;
        if(i < n2)
        {
            digit2 = b[n2 - 1 - i] - '0'; // o(1)
        }
        else digit2 = 0;
        diff = digit1 - digit2 - borrow; // o(1)
        if (diff < 0) { 
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0; 
        }
        result += char(diff + '0');
// 20 + 5 ==> 20 + 5 = 205
// result = char(diff + '0) + result; --
//                                 |-> thực hiện *phép nối string* => tốc độ thực thi là result.size() => **TLE**
// result = result + char(diff + '0');--
//20 + 5 => 20 + 5 => 205
    }
    ll idx = 0;
    reverse(result.begin(), result.end());
    while (result.length() > 1 && result[idx] == '0') {
        idx++;
    } /** */
    result.erase(0, idx);
    
    return result;
}
void sol() {
    string s;
    int k;
    cin >> s >> k;
    // n = s.size()
    string sub = s;

    string result = "";
    int keep = s.size() - k;

    for (char c : s) {
        while (!result.empty() && result.back() < c && k > 0) {
            result. pop_back();
            k--;
        }
        // 38492498293487987234
        // 39492498293487987234
        result.push_back(c);
    }
    // luu string co gia tri lon nhat sau khi xoa k chu so
    result.resize(keep);
    cout<<tru(sub, result);
}

KING_PHAT {
    fast;
    if (multitest) {
        int t;
        cin >> t;
        while (t--) {
            sol();
        }
    } else {
        sol();
    }
    return 0;
}

// 8380248390522737902399703986576270399917236558147138480460326941378838153543659549175541883522667841718787744915558298207485830622522715211018760095628594390563630840464643840093757297565304855542192458625139737502187155856794161204459753905563268914887193114959093407575064784006247418589993377325634060405685376867184973102371893748040570056780657343048759532739779533385896042337001030038360409249291093003019869016448614081031150849305238780457106033502327100971745178254530194593966408206072981161181150083