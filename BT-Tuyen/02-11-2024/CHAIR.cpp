#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

bool able(int x, string s){
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ') cnt++;
    }
    return x == cnt;
}

int main(){
    ll n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);

    int minn = INT_MAX;
    for(int i = 0; i < s.size(); i++){
        if('0' <= s[i] && s[i] <= '9'){
            minn = min(s[i], minn);
        }
    }

    int cnt = minn;
    while(!able(cnt, s)){
        cnt++;
    }

    cout << cnt << endl; 
}
