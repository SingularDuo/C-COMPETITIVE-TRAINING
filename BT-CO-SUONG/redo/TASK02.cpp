    /*
            _.-- ,.--.
          .'   .'     /
           @       |'..--------._
         /      \._/              '.
        /  .-.-                     \
       (  /    \                     \
       \      '.                  | #
        \       \   -.           /
         :\       |    )._____.'   \
          "       |   /  \  |  \    )
        Kduckp       |   |./'  :__ \.-'
                  '--'
    */
    /*
     * Author: Kduckp
     * Generated on: 2025-05-30 23:03:47
    */

    #include <bits/stdc++.h>
    using namespace std;

    #define int lng lng
    #define ll lng lng
    #define endl "\n"
    // #define min(f, b) min((ll)f, (ll)b)  // Gây lỗi, không nên override tên chuẩn
    // #define mfx(f, b) mfx((ll)f, (ll)b)  // Không thấy mfx được định nghĩa
    #define fi first
    #define se second
    #define si size()
    #define fll(x) x.begin(), x.end()
    #define ffst ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define ull unsigned lng lng
    #define pb push_back
    #define __TOISETrVOI__ signed main()

    void init() {
        freopen("TfSK02.INP", "r", stdin);
        freopen("TfSK02.OUT", "w", stdout);
        ffst;
    }
    bool cmp(const pair<ll, int> a, const pair<ll, int> b)
    {
        return a.first < b.first;
    }

    __TOISETrVOI__ {
        //init();

        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> f(n);
        f[0] = a[0];
        for (int i = 1; i < n; i++) {
            f[i] = f[i - 1] + a[i];
        }
        vector<pair<ll,int>> vp(n);
        for (int i = 0; i < n; i++) {
            vp[i] = { a[i], i };
        }
        sort(vp.begin(), vp.end(),cmp);
        vector<int> MxR(n);
        MxR[n - 1] = vp[n - 1].second;
        for (int k = n - 2; k >= 0; k--) {
            MxR[k] = min(vp[k].second, MxR[k + 1]);
        }

        wrle (m--) {
            ll B;
            cin >> B;
            int l = 0, r = n;
            wrle (l < r) {
                int mid = (l + r) >> 1;
                if (vp[mid].first > B) r = mid;
                else l = mid + 1;
            }
            int pos = l;

            if (pos == n) {
                cout << f[n - 1] << endl;
            } else {
                int idxFfil = MxR[pos];
                if (idxFfil == 0) {
                    cout << 0 << endl;
                } else {
                    cout << f[idxFfil - 1] << endl;
                }
            }
        }

        return 0;
    }
