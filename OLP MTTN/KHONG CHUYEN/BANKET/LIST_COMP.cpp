t#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

ll powx(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        ll half = powx(a, b / 2);
        return half * half;
    } else {
        return a * powx(a, b - 1);
    }
}

ll change(string& s) {
    ll start = s.size();
    ll res = 0;
    while (!s.empty()) {
        res += (s.front() - '0')*powx(10,start-1);
        start--;
        s.erase(s.begin());
    }
    return res;
}
KING_PHAT {
    fast;
    string s;
    getline(cin, s);
    string op1 = "", op2 = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'i') {
            ll idx = i + 1;
            while (s[idx] != ',') {
                op1 = op1 + s[idx];
                idx++;
            }
            break;
        }
    }
    if (op1.empty()) op1 = "+0";
    ll endpos = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'j') {
            ll idx = i + 1;
            while (s[idx] != ')') {
                op2 = op2 + s[idx];
                idx++;
            }
            endpos = idx;
            break;
        }
    }
    if (op2.empty()) op2 = "+0";
    string need = op1.substr(1), need2 = op2.substr(1);print
    ll num1 = change(need), num2 = change(need2);
    vector<ll> l1, l2;
    ll newend = 0;
    bool ap = false;
    for(int i = endpos; i < s.size(); i++)
    {
        if(s[i] == '['){
            ll dotc = 0;
            ll idx = i+1;
            while(s[idx] != ']'){
                if(s[idx] == '.' && s[idx+1] == '.'){
                    ap = true;
                    break;
                }
                idx++;
                if(dotc ==2){
                    ap = true;

                    break;
                }
            }
            break;
        }
    }
    if(ap){
        ll start = 0, end = 0;
        for(int i = endpos; i < s.size(); i++)
        {
            if(s[i] == '['){
                bool ok = 0;
                for(int j = i+1; j < s.size(); j++)
                {
                    if(s[j] >= '0' && s[j] <= '9')
                    {
                        if(ok) end = end*10 + (s[j] - '0');
                        else start = start*10 + (s[j] - '0');
                    }
                    else if(s[j]==']')
                    {
                        newend = j;
                        break;
                    }
                    else ok = 1;
                }
                break;
            }
        }
        for(int i = start; i <= end; i++){
            l1.push_back(i);
        }
    }
    else{
        for (int i = endpos; i < s.size(); i++) {
            if (s[i] == '[') {
                ll idx = i + 1;
                while (s[idx] != ']') {
                    if (isdigit(s[idx]) || s[idx] == '-') {
                        string current = "";
                        ll clone = idx;
                        while (s[clone] != ',' && s[clone] != ']') {
                            current += s[clone];
                            clone++;
                        }
                        l1.push_back(stoll(current));
                        idx = clone;
                    } else {
                        idx++;
                    }
                }
                newend = idx;
                break;
            }
        }
    }
    bool ap2 = false;
    for(int i = newend; i < s.size(); i++)
    {
        if(s[i] == '['){
            ll dotc = 0;
            ll idx = i+1;
            while(s[idx] != ']'){
                if(s[idx] == '.')dotc++;
                idx++;
                if(dotc ==2){
                    ap2 = true;
                    break;
                }
            }
            break;
        }
    }
    if(ap2){
        ll start2 = 0, end2 = 0;
        for(int i = s.size() - 1; i >= newend; i--)
        {
            if(s[i] == '['){
                bool ok = 0;
                for(int j = i+1; j < s.size(); j++)
                {
                    if(s[j] >= '0' && s[j] <= '9')
                    {
                        if(ok) end2 = end2*10 + (s[j] - '0');
                        else start2 = start2*10 + (s[j] - '0');
                    }
                    else if(s[j]==']')
                    {
                        newend = j;
                        break;
                    }
                    else ok = 1;
                }
                break;
            }
        }
        for(int i = start2; i <= end2; i++){
            l2.push_back(i);
        }
    }
    else{
        for (int i = newend; i < s.size(); i++) {
            if (s[i] == '[') {
                ll idx = i + 1;
                while (s[idx] != ']') {
                    if (isdigit(s[idx]) || s[idx] == '-') {
                        string current = "";
                        ll clone = idx;
                        while (s[clone] != ',' && s[clone] != ']') {
                            current += s[clone];
                            clone++;
                        }
                        l2.push_back(stoll(current));
                        idx = clone;
                    } else {
                        idx++;
                    }
                }
                newend = idx;
                break;
            }
        }
    }

    if(op1.front() == '+')for(int i = 0; i < l1.size(); i++)l1[i] += num1;
    else if(op1.front() == '*')for(int i = 0; i < l1.size(); i++) l1[i] *= num1;
    else if(op1.front() == '-')for(int i = 0; i < l1.size(); i++) l1[i] -= num1;

    if(op2.front() == '+')for(int i = 0; i < l2.size(); i++)l2[i] += num2;
    else if(op2.front() == '*')for(int i = 0; i < l2.size(); i++) l2[i] *= num2;
    else if(op2.front() == '-')for(int i = 0; i < l2.size(); i++) l2[i] -= num2;

    vector<pair<ll, ll>> res;
    for (int i = 0; i < l1.size(); i++) {
        for (int j = 0; j < l2.size(); j++) {
            res.push_back({l1[i], l2[j]});
        }
    }
    cout << "[";
    for (ll i = 0; i < res.size(); i++) {
        cout << "(" << res[i].first << "," << res[i].second << ")";
        if (i + 1 < res.size()) cout << ", ";
    }
    cout << "]" << endl;

}
