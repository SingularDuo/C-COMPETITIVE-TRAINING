#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define endl "\n"

signed main()
{
	int n,p,d; cin>>n>>p>>d;
	
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin>>a[i];
	sort(a.begin(), a.end());
	
	if(a[n-1] + p < d)
	{
		cout<<-1;
		return 0;
	}
	ll current = p;
	ll res = 0;
	while(current < d)
	{
		auto it = upper_bound(a.begin(), a.end(), current);
		it--;
		current = *it + p;
		res++;
	}
	cout<<res;
}