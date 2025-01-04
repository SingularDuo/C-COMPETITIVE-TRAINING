#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 1e4;

bool scp(ll n){
    if(n==0)return false;
    ll a = sqrt(n);
    return a*a == n;
}
vector<vector<ll>> rotatee(vector<vector<ll>> &a, ll size){
    vector<vector<ll>> rotated(size+1, vector<ll>(size+1));
    for(int i = 0; i < size; i++){
        for(int j =0; j < size; j++){
            rotated[i][j] = a[size - i - 1][size - j - 1];
        }
    }
    return rotated;
}
ll biendoi(ll n){
    return (n-1) *(n-1);
}
bool able(vector<vector<ll>> &a, ll diff, ll n){
    bool able = true;
    for(ll i = 0; i < n;i++){
        for(ll j = 0; j < n; j++){
            if(a[i][j] = 0){
                
            }
        }
    }
    for(ll i = 0; i < n;i++){
        for(ll j = 0; j < n; j++){
            if(j + 1 < n){
                if(a[i][j] + diff == a[i][j+1] || a[i][j] + diff == biendoi(a[i][j+1]))continue;
                else{
                    able = false;
                    continue;
                } 
            }
            else if(j + 1 >= n){
                if(a[i][j] + diff == a[i+1][0] || a[i][j] + diff == biendoi(a[i+1][0]))continue;
                else{
                    able = false;
                    continue;
                }
            }
        }
    }
    return able;
}
int main(){
    ll n; 
    cin>>n;
    vector<vector<ll>> a(n+1, vector<ll>(n+1));
    for(long long i = 0; i <n;i++){
        for(long long j = 0; j < n; j++){
            ll b;
            cin>>b;
            if(scp(b)) a[i][j] = sqrt(b) + 1;
            else if(b == 0){
                a[i][j] = 0;
                continue;
            }
            else a[i][j] = b;
        }
    }
    cout<<endl;
    vector<vector<ll>> b = rotatee(a, n);
    vector<vector<ll>> res (n+1, vector<ll>(n+1));
    ll result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j + 1 < n){
                ll maxx = max(a[i][j], a[i][j+1]);
                ll minn = min(a[i][j], a[i][j+1]);
                if(able(b, (maxx-minn), n) == true){
                    result ++;
                    continue;
                }
                else continue;   
            }
            else if(j + 1 >= n){
                ll maxx = max(a[i][j], a[i+1][0]);
                ll minn = min(a[i][j], a[i+1][0]);
                if(able(b, (maxx-minn), n) == true){
                    result++;
                    continue;
                    
                }
                else continue;

            }
        }
    }
    cout<<result;
}
/*
b1 tim buoc nhay co the
3
0 10 5
11 0 20
15 10 5
*/