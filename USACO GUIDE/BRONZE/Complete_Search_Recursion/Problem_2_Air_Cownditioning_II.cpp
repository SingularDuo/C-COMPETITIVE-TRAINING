#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i <= b; i++)

struct AC {
    int start, end, temp, cost;
};

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int n, m;
    cin >> n >> m;
    vi a(101, 0); 

    FOR(i, n) {
        int s, t, c;
        cin >> s >> t >> c;
        REP(j, s, t) a[j] -= c;
    }

    vector<AC> air(m);
    FOR(i, m) {
        cin >> air[i].start >> air[i].end >> air[i].temp >> air[i].cost;
    }

    int min_cost = INT_MAX;
    

    for (int mask = 0; mask < (1 << m); mask++) {
        vi temp_a = a; 
        int cost = 0;

        FOR(i, m) {
            if (mask & (1 << i)) { 
                cost += air[i].cost;
                REP(j, air[i].start, air[i].end) {
                    temp_a[j] += air[i].temp; 
                }
            }
        }
        
    
        bool valid = true;
        for (int i = 1; i <= 100; i++) {
            if (temp_a[i] < 0) { 
                valid = false;
                break;
            }
        }
        
        if (valid) {
            min_cost = min(min_cost, cost);
        }
    }

    cout << min_cost << endl;

    return 0;
}