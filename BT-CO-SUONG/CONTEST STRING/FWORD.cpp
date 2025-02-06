#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void sol(){
  ll n,m,k,x;
  cin>>n>>m>>k>>x;
  string s;
  cin>>s;
  cin.ignore();
  string replace;
  cin>>replace;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '#'){
      s[i] = replace[x-1];
      break;
    }
  }
  cout<<s;
  return;
}
signed main() {
  sol();
  return 0;
}