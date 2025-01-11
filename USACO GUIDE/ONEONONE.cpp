#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main(){
    string s;
    getline(cin ,s);
    ll apoint = 0, bpoint = 0;
    for(int i = 0; i <= s.size()-1;i++){
        if(s[i] == 'A')apoint += s[i+1] - '0';
        else if(s[i] == 'B') bpoint += s[i+1]-'0';
    }
    if(apoint>bpoint)cout<<"A";
    else cout<<"B";
}