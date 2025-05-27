// Problem: 03B. An Giang - Bài 2 - Tổng các số lẻ (2 điểm)
// Contest: Codeforces - Đề tuyển sinh toàn quốc năm học 2024-2025 phần 1
// URL: https://codeforces.com/gym/604749/problem/03B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define int long long

signed main()
{
	int n; cin>>n;
	
	int limit = 2*n - 1;
	if(limit % 2 == 0)limit--;
	
	int am = (limit - 1)/2 + 1;
	int sum = (limit + 1)*am/2;
	cout<<sum;
}