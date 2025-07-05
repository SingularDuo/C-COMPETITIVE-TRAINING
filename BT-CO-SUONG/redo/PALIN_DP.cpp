#include<bits/stdc++.h>
using namespace std;

// Tính độ dài của xâu Palin lớn nhất trong xâu s.
// Nhận xét: aba -> palin => Mở rộng: c***c
// Xâu độ dài lớn hơn => Có thể cập nhật kết quả từ xâu độ dài nhỏ hơn.

// DP[l][r]: Độ xài xâu palin dài nhất trong đoạn từ L -> R.
//    - DP[l][r]: max(l + 1 -> r, l -> r - 1)
//    - Lấy cả l, r vô palin: s[l] == s[r] => DP[l][r] = DP[l + 1][r - 1] + 2;

// Tìm số cách tách một xâu s thành các xâu nhỏ sao cho mỗi xâu là palin.
// dp[n]: số cách chia đến vị trí n.
int dp[1005][1005];
int main() {
    // độ dài từ nhỏ -> lớn
    // k = 1 => Tự tính được.

    for(int l = 1; l <= n; l++) {
        r = l;
        dp[l][r] = 1;
    }

    for(int k = 2; k <= n; k++) {
        for(int l = 1; l <= n - k + 1; l++) {
            int r = l + k - 1;

            dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);

            if(s[l] == s[r]) {
                dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + 2);
            }
        }
    }

    cout <<  dp[1][n] << endl;
}
