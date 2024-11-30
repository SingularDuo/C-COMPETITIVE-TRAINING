#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> total_point(n, 0), win(n, 0), draw(n, 0), lose(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (a[i][j] == 3) {
                    total_point[i] += 3;
                    win[i]++;
                } else if (a[i][j] == 1) {
                    total_point[i] += 1;
                    draw[i]++;
                } else if (a[i][j] == 0) {
                    lose[i]++;
                }
            }
        }
    }

    // a. Tìm đội có tổng điểm cao nhất
    int max_point = *max_element(total_point.begin(), total_point.end());
    vector<int> max_point_teams;
    for (int i = 0; i < n; i++) {
        if (total_point[i] == max_point) {
            max_point_teams.push_back(i + 1); 
        }
    }

    // b. Tìm đội có số trận thắng > số trận thua
    vector<int> thang_hon_thua;
    for (int i = 0; i < n; i++) {
        if (win[i] > lose[i]) {
            thang_hon_thua.push_back(i + 1);
        }
    }

    // c. Tìm đội không thua trận nào
    vector<int> khongthua;
    for (int i = 0; i < n; i++) {
        if (lose[i] == 0) {
            khongthua.push_back(i + 1);
        }
    }
    for (int team : max_point_teams) {
        int maxwin = 0, maxdraw = 0, maxlose = 0, maxpoint = 0;
        for(int j = 0; j < n; j++){
            if(a[team-1][j] == 3){
                maxwin++;
                maxpoint += 3;
            }
            if(a[team-1][j] == 1){
                maxdraw++;
                maxpoint += 1;
            }
            if(a[team-1][j] == 0 && j != team-1){
                maxlose++;
                maxpoint += 0;
            }
        }
        cout<<team<<" "<<maxpoint<<" "<<maxwin<<" "<<maxdraw<<" "<<maxlose<<endl;
    }
    // b. In các đội có số trận thắng > số trận thua, nếu không có in ra 0
    if (thang_hon_thua.empty()) {
        cout << 0 << endl;
    } else {
        for (int team : thang_hon_thua) {
            cout << team << " ";
        }
        cout << endl;
    }

    // c. In các đội không thua trận nào, nếu không có in ra 0
    if (khongthua.empty()) {
        cout << 0 << endl;
    } else {
        for (int team : khongthua) {
            cout << team << " ";
        }
        cout << endl;
    }
    return 0;
}
