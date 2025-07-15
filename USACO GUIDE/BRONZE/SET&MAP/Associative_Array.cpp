/*
        _.-- ,.--.
      .'   .'     /
       @       |'..--------._
     /      \._/              '.
    /  .-.-                     \
   (  /    \                     \
   \      '.                  | #
    \       \   -.           /
     :\       |    )._____.'   \
      "       |   /  \  |  \    )
    Kduckp       |   |./'
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int32_t main(){
	fast;

	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	map<int,int> cnt;
	int res=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		res+=cnt[k-a[i]];
		cnt[a[i]]++;
	}
	cout<<res;
}