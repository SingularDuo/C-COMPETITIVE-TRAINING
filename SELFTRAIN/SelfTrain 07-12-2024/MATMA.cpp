#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    cin.ignore();
    string s;
    getline(cin, s);
    cout << "s:" << s << endl;
    vector<int> pos;
    vector<vector<char>> luu(m + 1, vector<char>(k + 1));
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= k; j++) {
            cin >> luu[i][j];
        }
    }
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '#') pos.push_back(i);
    }
    int i = 1;
    int xuathien = pow(k, m);
    while(m > 0) {
        cout<<"xuathien="<<xuathien<<endl;
        cout<<"x"<<x<<endl;
        if(xuathien / k < x) {
            x -= xuathien - xuathien /k;
            xuathien /= k;
            char maxx = luu[i][1];
            for(int j = 1; j <= k; j++) {
                maxx = max(luu[i][j], maxx); 
            }
            cout << "maxx=" << maxx << endl;
            s[pos[i-1]] = maxx; 
            i++; 
            m--;
            continue;
        }
        if(xuathien / k >= x) {
            x -= xuathien- xuathien /k;
            xuathien /= k;
            char minn = luu[i][1];
            for(int j = 1; j <= k; j++) {
                minn = min(luu[i][j], minn); 
            }
            cout << "minn=" << minn << endl;
            s[pos[i-1]] = minn;
            i++;
            m--;
            continue;
        }
    }
    cout << s;
    return 0;
}
