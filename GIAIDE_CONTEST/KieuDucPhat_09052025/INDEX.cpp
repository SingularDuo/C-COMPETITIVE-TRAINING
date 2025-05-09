#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    freopen("INDEX.inp", "r", stdin);
    freopen("INDEX.out", "w", stdout);
    
    int n;
    cin >> n;
    
    map<int, vector<int>> huyen;
    for(int i = 0; i < n; i++) {
        int district, sbd;
        cin >> district >> sbd;
        huyen[district].push_back(sbd);
    }
    
    for(auto& pair : huyen) {
        sort(pair.second.begin(), pair.second.end());
    }
    
    vector<pair<int, int>> res;
    
    while(!huyen.empty()) {

        int last = res.empty() ? -1 : res.back().first;
        bool found = false;

        for(auto it = huyen.begin(); it != huyen.end();) {
            if((*it).first != last) {
                res.push_back({(*it).first, (*it).second[0]});
                (*it).second.erase((*it).second.begin());
                
                if((*it).second.empty()) {
                    auto temp = it;
                    it++;
                    huyen.erase(temp);
                } else {
                    it++;
                }
                
                found = true;
                break;
            } else {
                it++;
            }
        }

        if(!found && !huyen.empty()) {
            auto maxx = huyen.begin();
            for(auto it = huyen.begin(); it != huyen.end(); ++it) {
                if((*it).second.size() > (*maxx).second.size()) {
                    maxx = it;
                }
            }
            
            res.push_back({(*maxx).first, (*maxx).second[0]});
            (*maxx).second.erase((*maxx).second.begin());
            
            if((*maxx).second.empty()) {
                huyen.erase(maxx);
            }
        }
    }
    
    for(const auto& student : res) {
        cout << student.first << " " << student.second << endl;
    }
    
    return 0;
}