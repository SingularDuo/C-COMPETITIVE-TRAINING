#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"

void init(){
    freopen("COLORS.INP", "r",stdin);
    freopen("COLORS.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string color(ll x, ll y, vector<vector<int>> &a ){
    if(a[x][y] == 1){
        return "RED"; 
    }
    if(a[x][y] == 2){
        return "BLUE"; 
    }
    if(a[x][y] == 3){
        return "YELLOW"; 
    }
}

int main(){
    //init();
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> f(k);
    vector<vector<int>> a(n, vector<int>(n, 0)); 

    for(int i = 0; i < k; i++) {
        cin >> f[i].first >> f[i].second;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int curr_i1 = i, curr_j1 = j;
            while(curr_i1 >= 4 && curr_j1 >= 4){
                curr_i1 -= 3;
                curr_j1 -= 3;
            }
            if(i == 0 || j == 0 || i == n-1 || j == n-1 || curr_i1 == 0 || curr_j1 == 0){ 
                a[i][j] = 1; // 1 = red;
                continue;
            } 
            if(i == 1 || j == 1 || i == n - 2 || j == n - 2 || curr_i1 == 1 || curr_j1 == 1){ 
                a[i][j] = 2; // 2 = blue
                continue;
            }
            if(i == 2 || j == 2 || i == n - 3 || j == n - 3 || curr_i1 == 2 || curr_j1 == 2){ 
                a[i][j] = 3; // 3 = yellow
                continue;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j]; 
        }
        cout << endl;
    }

    for(int i = 0; i < k; i++){
        int first = f[i].first - 1, s = f[i].second - 1;
        cout << color(first, s, a) << endl;
    }
}
