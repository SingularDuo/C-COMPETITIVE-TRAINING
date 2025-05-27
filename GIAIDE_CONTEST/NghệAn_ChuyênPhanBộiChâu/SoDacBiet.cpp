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


const int maxn = 1e6;
int uoc[maxn + 5];
void Sang_so_luong_uoc() {
    for(int i = 1; i <= maxn; ++i) {
        for (int j = i; j <= maxn; j += i) {
            uoc[j]++;  
        }
    }
}

vector<ll> preprocessed(maxn+5, 0);
void precompute()
{
    for(int i = 0; i <=  maxn; i++)
    {
        if(uoc[i] == 4)preprocessed[i] = preprocessed[i-1] + 1;
        else preprocessed[i] = preprocessed[i-1];
    }
}
void sol()
{
    int l, r; cin>>l>>r;
    cout<<preprocessed[r] - preprocessed[l-1]<<endl;
}
TOISETHIVOI
{
    Sang_so_luong_uoc();
    precompute();
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}