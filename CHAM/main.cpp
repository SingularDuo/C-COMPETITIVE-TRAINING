#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int MAX = 1005;
int a[MAX][MAX];
const int MAX_RANGE1 = 1e6;
//
//void trau() {
//
//}
//
//void full() {
//
//}
//
//void solve() {
//    if(n <= 100) {
//        trau();
//    } else{
//        full();
//    }
//}
void so_nho(int n)
{
    ll res = 0;
    for(ll i = 1;i<=n;i++){
           string s = to_string(i);
            int a = (int)s.size();
            res+=a;
        }
    cout<<res;
    return;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
/*
5 6
3 5 6 8 19 7
1 3 4 6 7 12
13 15 17 50 5 7
25 3 2 6 8 9
5 8 5 8 6 9
*/
/*
5 5
2 3 14 5 1
3 2 1 4 5
2 9 3 6 7
4 2 7 9 2
4 6 4 6 8
*/
