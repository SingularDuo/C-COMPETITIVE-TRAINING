#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
vector<pair<int, int>> pieces;
vector<vector<bool>> board(N, vector<bool>(N, false));
char pieceTypes[4] = {'Q', 'N', 'R', 'B'}; // Hậu, Mã, Xe, Tượng

void backtrack(int placed) {
    if (placed == 4) {
        for (int i = 0; i < 4; i++) {
            cout << pieceTypes[i] << "(" << pieces[i].first << ", " << pieces[i].second << ") ";
        }
        cout << "\n";
        return;
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (!board[row][col]) { // Ô chưa có quân nào
                board[row][col] = true;
                pieces.push_back({row, col});
                backtrack(placed + 1);
                pieces.pop_back();
                board[row][col] = false;
            }
        }
    }
}

int main() {
    backtrack(0);
    return 0;
}
