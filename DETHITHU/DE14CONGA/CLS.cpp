#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void sol_brute(string s){ // sub1
	ll cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'C') {
			ll cntL = 0, cntS = 0;
			for (int j = i + 1; j < s.size(); j++) {
				if (s[j] == 'L')cntL++;
				if (s[j] == 'S')cntS++;
				if (cntL > 0 && cntS > 0) {
					cnt++;
					break;
				}
			}
		}
	}
	cout << cnt;
}
int main(){
	string s;
	getline(cin, s);
	sol_brute(s);
}