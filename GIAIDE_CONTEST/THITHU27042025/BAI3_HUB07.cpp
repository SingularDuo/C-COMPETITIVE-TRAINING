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
void sol() {
    string s;
    int k;
    cin >> s >> k;
    string sub = s;

    string result = "";
    int keep = s.size() - k;
    
    for (char c : s) {
        while (!result.empty() && result.back() < c && k > 0) {
            result.pop_back();
            k--;
        }
        result.push_back(c);
    }
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