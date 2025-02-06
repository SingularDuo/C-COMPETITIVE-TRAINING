#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    int n;
    cin >> n;
    cin.ignore();

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        getline(cin, a[i]);
    }
    string header1 = "Lookattheanimals,dancing,dancing,";
    string header2 = "Lookattheanimals,dancingtothemusic";
    string add = ",dancing, dancing,";
    string comma = ",";
    ll cnt = 0;
    ll comma_val = 0;
    ll dancing_val = 0;
    for(char c : add) if(isalpha(c)) dancing_val++;
    ll head2_val = header2.size() - 1;
    cnt += header1.size() - 3;
    cnt += head2_val;
    vector<ll> alpha_sum(n);
    for (int i = 0; i < n; i++) {
        for (char c : a[i]) {
            if (isalpha(c)) alpha_sum[i]++;
        }
    }
    ll f = 0;
    for (int i = 0; i < n; i++) {
        f += alpha_sum[i];
        cnt += f + dancing_val + head2_val+ (i > 0 ? 3 : 0);
    }
    cout << cnt << endl;
    return 0;
}

/*
5
one fat cat
two big elephants
three small bats
four long snakes
five thin bears
*/