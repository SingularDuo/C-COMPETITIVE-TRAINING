#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

bool checkYear(ll year) 
{
    if (year % 400 == 0) 
        return true;
    if (year % 4 == 0 && year % 100 != 0) 
        return true;
    return false; 
}
ll leapcnt(ll y, ll skipped){
    ll leapskip = (skipped/4) - (skipped/100) + (skipped/400);
    ll leapy = (y/4) - (y/100) + (y/400);
    return leapskip - leapy;
}
void solmain(){
    ll x, d, m ,y ;
    cin>>x>>d>>m>>y;
    ll year_skip = x / 365, canthem = 0;
    ll leap = leapcnt(y-1, y+year_skip);
    if( (x-canthem)/365 == year_skip){
        y += year_skip;
        x -= year_skip*365;
    }
    vector<ll> thuong = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<ll> nhuan = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    vector<ll> namdau;
    if (checkYear(y)) {
        namdau = nhuan;
    } else {
        namdau = thuong;
    }
     while (x--) {
        d++;
        if (d > namdau[m - 1]) {
            m++;
            d = 1;
        }
    }
    cout<<d<<" "<<m<<" "<<y;
    return;
}
signed main() {
    solmain();

    return 0;
}