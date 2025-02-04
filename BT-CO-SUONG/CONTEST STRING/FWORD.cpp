#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void sol() {
    ll n, m, k, x;
    cin >> n >> m >> k >> x;
    string s;
    cin >> s;
    string res ="";
    ll cnt = 0;
    vector<string> a(m);
    vector<char> inside;
    for (int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < m; i++){
        string s1 = a[i];
        string s2 = "";
        for(int j = i+1; j < m ; j++)s2 = s2+ a[j];
        for(int j = 0; j < s1.size(); j++){
            if(s2.size() < x){
                x -= s2.size();
                continue;
            }
            else{
                for(int ik = 0; ik < s.size(); ik++){
                    if(s[ik] == '#'){
                        s[ik] = s1[j];
                        break;
                        cout<<"sik"<<" "<<s[ik]<<endl;
                    }
                }
                ll idx = 0;
                while(cnt < x){
                    idx++;
                    cnt++;
                }
                for(int ik = 0; ik < s.size(); ik++){
                    if(s[ik] == '#'){
                        s[ik] = s2[idx-1];
                    }
                }
            }
        }
    }
    cout<<s;

    return;
}

signed main() {
    sol();
    return 0;
}