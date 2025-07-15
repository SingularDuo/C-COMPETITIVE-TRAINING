// Problem: Tower of Hanoi
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2165
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define endl "\n"

void Tower_of_HN(int disk, int start, int mid, int endd) {
    if (disk == 1) {
        cout<<start<<" "<<endd<<endl;
        return;
    }

    Tower_of_HN(disk - 1, start, endd, mid);
    cout << start << " " << endd << endl;
    Tower_of_HN(disk - 1, mid, start, endd);
}



int binpow(int a, int b)
{
	int res = 1;
	while(b > 0)
	{
		if(b%2==1)res *= a;
		a*=a;
		b /=2;
	}
	return res;
}
signed main()
{
	int n; cin>>n;
	int res1 = binpow(2, n)-1;
	cout<<res1<<endl;
	Tower_of_HN(n, 1, 2, 3);
	
	
	
}