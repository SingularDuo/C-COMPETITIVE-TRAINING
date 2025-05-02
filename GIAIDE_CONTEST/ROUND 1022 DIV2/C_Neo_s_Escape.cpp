#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

void sol() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> lleft(n);
    lleft[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1]) lleft[i] = lleft[i - 1];
        else lleft[i] = i;
    }
    vector<int> rright(n);
    rright[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] >= a[i + 1]) rright[i] = rright[i + 1];
        else rright[i] = i;
    }
    struct Interval {
        int l, r;
    };
    vector<Interval> peaks;
    for (int i = 0; i < n; ++i) {
        peaks.push_back({lleft[i], rright[i]});
    }
    sort(peaks.begin(), peaks.end(), [](const Interval &a, const Interval &b) {
        if (a.l != b.l) return a.l < b.l;
        return a.r < b.r;
    });
    int covered = -1;
    int ans = 0;
    int idx = 0;

    while (covered < n - 1) {
        int maxx = covered;
        while (idx < (int)peaks.size() && peaks[idx].l <= covered + 1) {
            if (peaks[idx].r > maxx) maxx = peaks[idx].r;
            idx++;
        }

        if (maxx == covered) {
            break;
        }

        covered = maxx;
        ans++;
    }

    cout << ans << endl;
}

signed main() {
    fast;
    int t;
    cin >> t;
    while (t--) sol();
    
    return 0;
}