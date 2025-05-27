# Solution B4 Phan Bội Châu - Nghệ An

## Cách 1 - Duyệt trâu bò - $O(n^2)$

Với mỗi phần tử a[i], ta sẽ duyệt tất cả index $j$ bé hơn a[i], nếu có phần tử bé hơn a[i] thì gán giá trị vô vector res và in vector res ra

``` cpp
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> res(n);
    res[0] = 0; 
       
    for (int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i])
            {
                ll v = abs(j - i);
                res[i] = v;
                break;
            }
        }
    }
    for(auto& i : res)cout<<i<<" ";
}

int main() {
    sol();
    return 0;
}

```

## Cách 2 - Tối ưu 

### Nhận xét:
-   Với mỗi giá trị a[i], thì:
    
    1. Tìm $j$ nhỏ nhất và &j < i$
    2. Mà $a[j] < a[i]$
-   Như vậy, $j$ phụ thuộc vào 2 yếu tố là vị trí và giá trị nên chúng ta cần thực hiện 2 vòng lặp để tìm cặp $i,j$ thỏa mãn

**=> Cần xử lí trước để loại bỏ 1 trong 2 điều kiện**

Có thể cài để với mỗi số $a[i]$, biết được **những** số có giá trị < $a[i]$ và tìm ra $index$ bé nhất giữa những số đó

Cach 1:
```cpp
// code dung vector ($a[i] <= 1e5$)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int long long
#define TOISETHIVOI signed main()

const int mx = 1e5+5;
TOISETHIVOI
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    vector<ll> a(n);
    vector<vector<ll>> b(mx);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        b[a[i]].push_back(i);
    }

    vector<ll> res(n);
    ll cmp = LLONG_MAX;

    for(int i = 0; i < mx; i++)
    {
        for(int j : b[i])
        {
            if(cmp >= j)res[j] = 0;
            else res[j] = j - cmp;
        }
        for(int j : b[i])
        {
            if(j < cmp)cmp = j;
        }
    }
    for(int i = 0; i < n; i++)cout<<res[i]<<" ";


}
```
Cach 2:
```cpp
// code dung map de xu li nhung bai co gioi han a[i] cao hon nhung se tang luon do phuc tap thoi gian logN
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int long long
#define TOISETHIVOI signed main()

const int mx = 1e5+5;
TOISETHIVOI
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    vector<ll> a(n);
    map<int, vector<ll>> b;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        b[a[i]].push_back(i);
    }
    vector<ll> res(n);
    ll cmp = LLONG_MAX;
    for(int i = 0; i < b.size(); i++)
    {
        for(int j : b[i])
        { 
            // may cai dau tien ma k co thi nhot
            // cai phan tu nho nhat thi = 0 
            if(cmp >= j)res[j] = 0;
            else res[j] = j - cmp;
        }
        for(int j : b[i])
        {
            // doi me index len :
            if(j < cmp)cmp = j;
        }
    }
    for(int i = 0; i < n; i++)cout<<res[i]<<" ";


}
```