#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define endl "\n"
const int MAX_RANGE1 = 1e6;
void init(){
    freopen("CDIGIT.INP", "r",stdin);
    freopen("CDIGIT.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void so_nho(int n)
{
    ll res = 0;
    for(ll i = 1;i<=n;i++){
           string s = to_string(i);
            int a = (ll)s.size();
            res+=a; 
        }
    cout<<res;
    return;
}
int main(){
    init();
    ll n;
    cin>>n;
    if(n == 0){
        cout<<"1";
        return 0;
    }
    if(n <= MAX_RANGE1){
        so_nho(n);
        return 0;
    }
    /*
    9 so 1 chu so
    90 so 2 chu so
    900 so 3 chu so
    */
    string s = to_string(n);
    ll sochuso = (ll)s.size();
    ll res = 0;
    ll first = pow(10,sochuso - 1);
    ll socuoi = n;
    ll sodau = first;
    while(socuoi > 0){
        res += sochuso*(socuoi - sodau + 1);
        ll currtong = sodau- 1;
        // dang dem so luong tu 1000 den 1340
        // socuoi - so dau = 340
        // 1340 - 340 = 1000
        //1000 - 1 = 999
        socuoi = currtong;
        sodau /= 10;
        sochuso --;
    }
    cout<<res;
}