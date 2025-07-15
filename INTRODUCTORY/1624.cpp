#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define int long long

const int MAX_LIMIT_1 = 3*1e7;
bool isprime[MAX_LIMIT_1 + 5];
vector<int> prime;

void sieve() {
    memset(isprime, true, sizeof(isprime));  
    isprime[0] = isprime[1] = false;
    
    for (int i = 2; i * i <= MAX_LIMIT_1; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= MAX_LIMIT_1; j += i) 
                isprime[j] = false;
        }
    }
    
    for (int i = 2; i <= MAX_LIMIT_1; i++) {
        if (isprime[i]) prime.push_back(i);
    }
}

pair<int, int> res(int x) {
    for (int i = 0; prime[i] <= x / 2; i++) {
        if (isprime[x - prime[i]]) {
            return {prime[i], x - prime[i]};
        }
    }
    return {0, 0};
}

signed main() {
    sieve();
    
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
 
            pair<int, int> ans = res(a);
            if (ans.first == 0 || ans.second == 0) {
                cout << "NO" << endl;
                continue;
            }
            
            cout << ans.first << " " << ans.second << endl;

        
    }
}
