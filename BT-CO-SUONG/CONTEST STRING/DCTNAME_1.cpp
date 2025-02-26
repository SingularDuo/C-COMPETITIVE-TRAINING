#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX_CHAR = 26;

string s, t;
vvi pos_s(MAX_CHAR), pos_t(MAX_CHAR);

string find_max_substring(int from_s, int from_t, vvi &pos_s, vvi &pos_t) {
    for(int i = MAX_CHAR - 1; i >= 0; i--) {

        while(!pos_s[i].empty() && pos_s[i].back() < from_s)
            pos_s[i].pop_back();
        while(!pos_t[i].empty() && pos_t[i].back() < from_t)
            pos_t[i].pop_back();


        if(!pos_s[i].empty() && !pos_t[i].empty()) {
            int from_s = pos_s[i].back();
            int from_t = pos_t[i].back();

            string answer = find_max_substring(from_s + 1, from_t + 1, pos_s, pos_t);
            return (char)(i + 'a') + answer;
        }
    }

    return "";
}

void find_vector_position(string &s, vvi &pos) {
    for(int i = 0; i < MAX_CHAR; i++)  pos[i].clear();
    for (int i = 0; i < s.size(); i++) {
        pos[s[i] - 'a'].push_back(i);
    }


    for(int i = 0; i < MAX_CHAR; i++) {
        reverse(pos[i].begin(), pos[i].end());
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> s >> t;
    find_vector_position(s, pos_s);
    find_vector_position(t, pos_t);

    cout << find_max_substring(-1, -1, pos_s, pos_t) << endl;
}
