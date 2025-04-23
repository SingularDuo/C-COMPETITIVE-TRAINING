#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define len(x) x.size()
#define str string
#define ma2c vector<vector<int>>
#define MOD 1000000007
#define el '\n'
using namespace std;
//hahahaha
void Init(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
}
void Sol(){
    int t;cin>>t;
    cin.ignore();
    while(t--){
        str n;getline(cin,n);
        int d = 0, as = 1;
        for(int i = 0; i < n.size(); i++){
            if(n[i]=='0'){
                d++;
            }else{
                as=d;
            }
        }
        cout<<n.size()-as-1<<el;
    }
}
int32_t main(){
    Init();
	Sol();
	return 0;
}