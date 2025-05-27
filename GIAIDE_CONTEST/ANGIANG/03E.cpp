// Problem: 03E. An Giang - Bài 5 - Nén dãy (2 điểm)
// Contest: Codeforces - Đề tuyển sinh toàn quốc năm học 2024-2025 phần 1
// URL: https://codeforces.com/gym/604749/problem/03E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define endl "\n"

const int MOD = 1e9;

signed main() {
    int n; cin >> n;
    vector<int> upd;
    

    for (int i = 1; i < n; i++) {
        int v;
        if(i < n)v = i + i + 1;
        else v = i;
        upd.push_back(v);
    }
    
    while (upd.size() > 1) {
    	vector<ll> sub;
    	for(int i = 0; i < upd.size()-1; i++)
    	{
    		int v;
    		if(i + 1 < upd.size())v = (upd[i]%MOD + upd[i + 1]%MOD)%MOD;
    		else v = upd[i];
    		sub.push_back(v);
    	} 
    	upd = sub;
    }

    cout << upd[0] % MOD;
}
