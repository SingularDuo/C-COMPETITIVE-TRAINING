#include <bits/stdc++.h>
using namespace std;

#define affirmative cout<<"Yes"<<'\n'
#define negative cout<<"No"<<'\n'
#define length size()
#define start begin()
#define finish end()
#define primary first
#define secondary second
#define bigint long long
#define arrange sort
#define append push_back
const int LIMIT=2005, LARGE=1000000, MID=50005, MODULO=1000000007;
bigint countTests, numElements, idx, step, factor, iter, tracker, tally, minValue=1e9, cases, arrayA[LARGE+5], arrayB[LARGE+5], arrayC[LARGE+5], primeArray[MID+5], depth, flag, highestValue, lowestValue=1e10;
string strMain, strAux1, strAux2, strStatic="01032025";

struct Data {
    bigint varA, varB, identity, expense, state, alternate;
    string identifier;
    vector<bigint> collection;
    map<bigint,bigint> mapping;
};

signed main() {
    ios_base::sync_with_stdio(false);   
    cin.tie(0); cout.tie(0);
    
    cin >> cases;
    while (cases--) {
        cin >> numElements;
        flag = -1;
        step = 0;
        for (iter = 1; iter <= numElements; iter++) {
            cin >> arrayA[iter];
            step = max(step, arrayA[iter]);
        }
        tally = 0;
        for (iter = 1; iter <= numElements; iter++) {
            if (arrayA[iter] == arrayA[1])
                tally++;
        }
        if (tally == numElements)
            negative;
        else {
            affirmative;
            for (iter = 1; iter <= numElements; iter++) {
                if (arrayA[iter] == step) {
                    cout << 2 << " ";
                    for (idx = iter + 1; idx <= numElements; idx++)
                        cout << 1 << " ";
                    cout << '\n';
                    break;
                } else cout << 1 << " ";
            }
        }
    }
}
