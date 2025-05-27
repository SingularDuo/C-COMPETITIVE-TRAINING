#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
#define fi first 
#define se second 
#define TOISETHIVOI signed main()

int last = -1;

void last_point_set(const string &s, char k) {
    for(int i = 0; i < (ll)s.size(); i++) {
        if(s[i] == k) {
            last = i;
        }
    }
}

string delete_char(string s, char k) {
    s.erase(remove(s.begin(), s.end(), k), s.end());
    return s;
}

void sol() {
    string s;
    char k;
    cin >> s >> k;  

    last_point_set(s, k);

    if (last == -1) {
        cout << "-1"; 
        return;
    }
    //cout<<last<<endl;
    for(int i = last; i < (ll)s.size(); i++) {
        string sub = s.substr(0, i);
        //cout<<sub<<endl;
        string sub2 = delete_char(sub, k);
        if (sub + sub2 == s) {
            cout << sub;
            return;
        }
    }
    cout << "-1";
}

TOISETHIVOI {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    sol();
    return 0;
}
