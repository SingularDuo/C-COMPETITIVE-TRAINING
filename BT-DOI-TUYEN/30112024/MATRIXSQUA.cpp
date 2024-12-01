#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 1e5;
int a[1005][1005];

int main(){
    int n;
    cin>>n;
    ll tong = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
            if(i == 0) tong += a[i][j];
        }
    }
    //cout<<tong<<endl;
    for(int i = 0; i < n; i++){
        int currsum = 0;
        for(int j = 0; j < n; j++){
            currsum += a[i][j];
        }
        //cout<<"ngang"<<i<<" "<<currsum<<endl;
        if(currsum != tong){
            cout<<"NO";
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        int currsum = 0;
        for(int j = 0; j < n; j++){
            currsum += a[j][i];
        }
        //cout<<"doc"<<i<<" "<<currsum<<endl;
        if(currsum != tong){
            cout<<"NO";
            return 0;
        }
    }
    int currsum_cheochinh = 0;
    for(int i = 0; i < n; i++){
        currsum_cheochinh += a[i][i];
    }
    int currsum_cheophu = 0;
    for(int i = 0; i < n; i++){
        currsum_cheophu += a[i][n - i - 1];
    }

    //cout<<"cheochinh"<<" "<<currsum_cheochinh<<endl;
    //cout<<"cheophu"<<" "<<currsum_cheophu<<endl;
    if(currsum_cheochinh != tong || currsum_cheophu != tong){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
}
/*
5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
*/
/*
5
3 16 9 22 15
20 8 21 14 2
7 25 13 1 19
24 12 5 18 6
11 4 17 10 23
*/
