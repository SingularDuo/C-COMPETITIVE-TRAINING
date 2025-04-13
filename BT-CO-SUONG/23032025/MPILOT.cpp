// khong sort duoc vi lien quan den thu tu do tuoi
// neu chay trau thi phai for de tim nhieu ==> n^n hoac n (n/2)\
// dp hai chieu - truy hoi de tim cach chon toi uu
// f[i][j] la so tien toi uu khi cho i phi cong ma trong đo con j tro li chx co lai chinh
/*
thang dau tien luon luon la tro li vi no nho tuoi nhat, khong the thanh lai chinh
=> f[1][1] luon luon = gia tro li 1
*/
// 1. Neu thang thu i dc chon lam lai chinh thi f[i][j] = f[i-1][j+1] + lai_chinh[i]
// hay con goi l so tien toi uu khi cho i -1 phi cong va j + 1 tro li chua co lai chinh ( vi ms them 1 thg lam lai chinh)
// 2. Neu thang thu i dc chon lam tro li thi f[i][j] = f[i-1][j-1] + tro_li[i];
// Nhan xet: bai keu tim min ==> cong thuc truy hoi tong quat: f[i][j] = min(f[i-1][j+1] + lai_chinh[i], f[i-1][j-1] + tro_li[i]);
/*
4
5000 3000
6000 2000
8000 1000
9000 6000
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
void init(){
    freopen("MPILOT.INP", "r", stdin);
    freopen("MPILOT.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int n;
const int N = 10001;
int luong_lai[N], luong_tro_li[N], dp[2][N];
signed main()
{
    init();

    cin>>n;
    for(int i = 1; i <= n; i++)cin>>luong_lai[i]>>luong_tro_li[i];
    dp[1][1] = luong_tro_li[1];
    for (int i = 2; i <= n; i++) {
        int M = min(i, n / 2);
        int di = i%2;
        dp[di][0] = dp[1- di][1] + luong_lai[i];

        dp[di][M] = dp[1-di][M - 1] + luong_tro_li[i];

        for (int j = 1; j <= M-1; j++) {
            dp[di][j] = min(dp[1-di][j-1] + luong_tro_li[i], dp[1-di][j+1] + luong_lai[i]);
        }
    }
    cout << dp[0][0] << "\n";

}
