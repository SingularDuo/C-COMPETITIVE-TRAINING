#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

int dr[8] = {0, -1, 0, 1, -1, 1, -1, 1}; 
int dc[8] = {-1, 0, 1, 0, 1, 1, -1, -1};

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<vector<int>> updated(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'O')
            {
                updated[i][j] = -1;
                continue;
            }
            
            int count = 0;
            for (int x = 0; x < 8; x++) {
                int nx = i + dr[x];
                int ny = j + dc[x];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == 'O')
                    count++;
            }
            updated[i][j] = count;
        }
    }
    int res = 0;
    for(int i = 1; i < n-1; i++)
    {
        for(int j = 1; j  < n-1; j++)
        {
            if(updated[i][j]  == -1) continue;
            int count_bomb = 0;
            int count_chan = 0;
            int count_le = 0;
            bool isdb = true;
            for (int x = 0; x < 4; x++) {
                int nx = i + dx[x]; 
                int ny = j + dy[x];
            
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) { 
                    if (updated[nx][ny] == -1) count_bomb++;
                    if (count_bomb > 2) {
                        isdb = false;
                        break;
                    }
                    if (updated[nx][ny] != -1 && updated[nx][ny] % 2 == 0) count_chan++;
                    else if (updated[nx][ny] != -1 && updated[nx][ny] % 2 != 0) count_le++;
                }
            }            
            if(count_chan!=1||count_le!=1)
            {
                isdb = false;
            }
            if(isdb)res++;
        }
    }
    cout<<res;

}

int main() {
    FAST_IO;
    bool multitest = false;

    if (multitest) {
        int t;
        cin >> t;
        while (t--) {
            solve();
        }
    } else {
        solve();
    }
    
    return 0;
}
