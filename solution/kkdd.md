# Lời giải cho bài toán **K - Không đơn độc**

[Link đề bài gốc](https://oj.vnoi.info/problem/kkdd)

## Tóm tắt đề bài

Một dãy được gọi là **K–không đơn độc** nếu **mỗi phần tử** của dãy đều thuộc **một đoạn liên tiếp dài ≥ K** mà tất cả giá trị trong đoạn đó **bằng nhau**.

Cho dãy số nguyên (A) có (N) phần tử.

**Trong 1 thao tác**, ta có thể tăng hoặc giảm **1 phần tử** đi **1 đơn vị**.

### Yêu cầu

Tìm **số thao tác ít nhất** để biến dãy (A) thành dãy **K–không đơn độc**.

---

### **Input**

* Dòng 1: hai số nguyên (N), (K)
* Dòng 2: (N) số nguyên – dãy (A)

### **Output**

* Một số nguyên – số thao tác ít nhất

---

### **Ví dụ**

```
Input:
7 3
2 2 3 4 4 5 5

Output:
3
```

**Giải thích thao tác:**

* Giảm 3 → 2
* Tăng 4 → 5
* Tăng 4 → 5

Dãy cuối cùng:

```
2 2 2 5 5 5 5
```

---

## Nhận xét bài toán

### Bước quan trọng đầu tiên:

Giả sử có một mảng (A) cố định, ta muốn **biến tất cả phần tử thành cùng một giá trị (X)** với số thao tác ít nhất.

Hãy tưởng tượng các giá trị (a[i]) nằm trên **trục số OX**.

Khi đó bài toán trở thành:

> **Tìm số (X) sao cho tổng khoảng cách từ các điểm (a[i]) đến (X) là nhỏ nhất.**

---

##  Vì sao phải chọn *median*?

### Nếu (X) đứng **quá lệch về bên trái**:

* Rất nhiều điểm nằm ở phía phải
* Khoảng cách tới các điểm này lớn
* Nếu ta kéo (X) sang **phải 1 đơn vị**, X **gần nhiều điểm hơn**
  ==> **Tổng khoảng cách giảm**

==> Vậy **X không thể ở quá bên trái**.

---

### Nếu (X) đứng **quá lệch về bên phải**:

* Nhiều điểm nằm ở bên trái
* Kéo (X) sang **trái 1 đơn vị** giúp X gần nhiều điểm hơn
  ==> **Tổng khoảng cách giảm**

==> Vậy **X không thể ở quá bên phải**.

---

##  X kết luận phải ở đâu?

X phải nằm ở **giữa các giá trị**, sao cho:

* **nửa số phần tử nằm bên trái X**
* **nửa nằm bên phải X**

Đó chính là:

## **Median** (trung vị)

Median là giá trị ở giữa khi sắp xếp dãy tăng dần → tổng khoảng cách (\sum |a[i] - X|) là nhỏ nhất.
 **Chứng minh chi tiết có xuât hiện trong phần xác suất - thống kê trong toán lớp 10**

 Vậy bài toán ở trên có thể được giải bằng việc tìm *median* của dãy số và biến tất cả số trong dãy về *median*
 ---
##  Vậy bài toán này giải sao?
Do đề bài chỉ yêu cầu số thao tác **ít nhất**, ta xây dựng một mảng quy hoạch động:
Gọi:
> **dp[i]** = số thao tác ít nhất để **i phần tử đầu tiên** của dãy trở thành **dãy K–không đơn độc**.
---
**dp[i]** sẽ có công thức truy hồi là
$$ dp[i] = min(dp[i], dp[j-1] + cost(j,i) $$
với j là phần tử nằm trong đoạn 1 tới i và cost(j,i) là chi phí biến đoạn từ j tới i thành dãy K--không đơn độc
## Code ngây thơ 1:
```cpp=
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<ll> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i - j + 1 >= k) {
                vector<int> find_median;
                ll tot = 0;
                for (int l = j; l <= i; l++) {
                    find_median.push_back(a[l]);

                }
                sort(all(find_median));
                int mid = (int)find_median.size() / 2;
                int median = find_median[mid];
                for(int l = j; l <= i; l++) tot += abs(median - a[l]);
                if (dp[j - 1] != INF) {
                    dp[i] = min(dp[i], dp[j - 1] + tot);
                }
            }
        }
    }
    if (dp[n] == INF) {
        cout << -1 << "\n";
    } else {
        cout << dp[n] << "\n";
    }
}
```
Độ phức tạp thời gian: **O(n^3)** trong trường hợp xấu nhất

## Tối ưu 1
Ta thấy được ở phần trên, code có độ phức tạp rất lớn không thể **AC** được bài này.

Nhận thấy code ở trên bên trong hai vòng lặp tới $N$, phải tốn thêm 1 vòng nữa để tìm median, khiến độ phức tạp đi từ **O(n ^2)** lên thành **O(n ^ 3)**

Vậy làm sao để tối ưu việc tìm median trong 1 đoạn

Dễ thấy bài toán này không gồm các truy vấn yêu cầu cập nhật lại mảng, nên chúng ta có thể sử dụng thuật toán **Merge sort tree** để tìm median trong độ phức tạp thời gian **O(log(N)^2)** với mỗi lần truy vấn trên đoạn j-> i

Về mặt tư tưởng, **merge sort tree** chỉ là cây segment tree thông thường nhưng các node sẽ lưu vector và gộp 2 node lại bằng merge sort
[Đọc thêm về Merge Sort Tree - GFG](https://www.geeksforgeeks.org/dsa/merge-sort-tree-smaller-or-equal-elements-in-given-row-range/)

Code mẫu dùng Merge Sort Tree để truy vấn tìm median:
```cpp=
const int N = 10005;
vector<vector<int>> merge_tree(4 * N);
int a[N + 5],n,k;

void build(int id, int l, int r)
{
 if(l == r)
 {
  merge_tree[id].pb(a[l]);
  return;
 }
 int mid = (l + r) / 2;
 build(id * 2, l, mid);
 build(id * 2 + 1, mid + 1, r);
 merge(all(merge_tree[2 * id]), all(merge_tree[2 * id + 1]), back_inserter(merge_tree[id]));
}
int count_le(int id, int l, int r, int u, int v, int x) {
    if(r < u || l > v) return 0;
    if(u <= l && r <= v) {
        return upper_bound(all(merge_tree[id]), x) - merge_tree[id].begin();
    }
    int mid = (l + r) / 2;
    return count_le(id*2, l, mid, u, v, x) + count_le(id*2+1, mid+1, r, u, v, x);
}

int get(int id, int l, int r, int u, int v) {
    int left_val = -1e9, right_val = 1e9;
    int k = (v-u+1)/2;
    while(left_val < right_val) {
        int mid_val = left_val + (right_val - left_val)/2;
        int cnt = count_le(1, 1, n , u, v, mid_val);
        if(cnt <= k) left_val = mid_val+1;
        else right_val = mid_val;
    }
    return left_val;
}
void solve() {

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<ll> dp(n + 1, INF);
    dp[0] = 0;
    // vector<ll> pre(n + 1, 0);
    // for (int i = 1; i <= n; i++) {
    //     pre[i] = pre[i-1] + a[i];
    // }

    build(1,1,n);
    for (int i = 1; i <= n; i++) {
        int sta = max((int)1, i - 2 * k + 1);
        for (int j = sta; j <= i - k + 1; j++) {
            if (i - j + 1 >= k) {
                int median = get(1, 1, n, j, i);
                // ll tot = abs((pre[i] - pre[j-1]) - (i-j+1) * median);
                ll tot = 0;
                for(int l = j; l <= i; l++) tot += abs(a[l] - median);
                if (dp[j - 1] != INF) {
                    dp[i] = min(dp[i], dp[j - 1] + tot);
                }
            }
        }
    }

    if (dp[n] == INF) {
        cout << -1 << "\n";
    } else {
        cout << dp[n] << "\n";
    }
}
```
Trong đó hàm Count_le tốn đpt O(logN) để tìm số phần tử <= trong đoạn và sau đó sử đụng chặt nhị phân để tìm **giá trị** (không phải **index**) của giá trị median

Tuy nhiên về tổng quan, code này vẫn cỏn "dở" vì vẫn mấy một vòng for để tính tổng độ chênh lệch với median, khiến độ phức tạp vẫn xấp xỉ **O(n^3)**

## Tối ưu 2
Ở code tối ưu 1, vẫn còn vòng lặp tính tổng độ chênh lêhcj khiến độ phức tạp vẫn còn cao, từ đây, chúng ta tìm cách tối ưu phần tính toán chỗ này:

Gọi $X$ là median của đoạn hiện tại đang xét

**Với những phần tử <=** $X$, chênh lệch của mỗi số sẽ còn được tính là:
$$ X - a[i] $$
Với nhiều số ta sẽ có
$$ X - a[i] + X - a[j] + ... + X - a[k] $$
Vậy công thức tổng quan là
$$ X * cntleft - (a[i] + a[j] + ... + a[k])(SumLeft) $$

**Với những phần tử >** $X$, chênh lệch của mỗi số sẽ được tính là:
$$ a[i] - X $$
Với nhiều số ta sẽ có
$$ a[i] - X + a[j] - X + ... + a[k] - X$$
Vậy công thức tổng quan là
$$ (a[i] + a[j] + ...+ a[k])(SumRight) - X * cntright $$


Vậy công thức tổng quát là
$$ X * cntleft - SumLeft + SumRight - X * cntright $$
Có thể thấy, về mặt bản chất, chúng ta chỉ cần kiếm được cnt và tổng của một trong hai số thì có thể dễ dàng tính được nửa còn lại sử dụng **prefix sum**

Vậy làm sao để tính nhanh những tổng này thay cho độ phức tạp **O(N)**

Chúng ta có thể sử dụng thêm một cây **Merge sort tree** để giải quyết bài toán này, đưa bài toán từ độ phức tạp **O(N)** xuống độ phức tạp **O(log(N) ^ 2)**

Code triển khai:
```cpp=
const int N = 10005;

vector<vector<int>> merge_tree(4 * N);
vector<vector<ll>> merge_sum(4 * N);
int a[N + 5],n,k;

void build(int id, int l, int r)
{
    if(l == r)
    {
        merge_tree[id].pb(a[l]);
        merge_sum[id].pb(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    merge(all(merge_tree[2 * id]), all(merge_tree[2 * id + 1]), back_inserter(merge_tree[id]));

    merge_sum[id].resize(merge_tree[id].size());
    for(int i = 0; i < merge_tree[id].size(); i++){
        merge_sum[id][i] = merge_tree[id][i] + (i ? merge_sum[id][i-1] : 0);
    }
}

int count_le(int id, int l, int r, int u, int v, int x) {
    if(r < u || l > v) return 0;
    if(u <= l && r <= v) {
        return upper_bound(all(merge_tree[id]), x) - merge_tree[id].begin();
    }
    int mid = (l + r) / 2;
    return count_le(id*2, l, mid, u, v, x) + count_le(id*2+1, mid+1, r, u, v, x);
}

int get(int id, int l, int r, int u, int v) {
    int left_val = 0, right_val = 1e9;
    int k = (v-u+1)/2;
    while(left_val < right_val) {
        int mid_val = left_val + (right_val - left_val)/2;
        int cnt = count_le(1, 1, n , u, v, mid_val);
        if(cnt <= k) left_val = mid_val+1;
        else right_val = mid_val;
    }
    return left_val;
}
ll sum_le(int id, int l, int r, int u, int v, int x) {
    if (r < u || l > v) return 0;
    if (u <= l && r <= v) {
        int idx = upper_bound(all(merge_tree[id]), x) - merge_tree[id].begin() - 1;
        if(idx < 0) return 0;
        return merge_sum[id][idx];
    }
    int mid = (l + r) / 2;
    return sum_le(id*2, l, mid, u, v, x) + sum_le(id*2+1, mid+1, r, u, v, x);
}

void solve() {
    cin >> n >> k;
    vector<ll> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }

    vector<ll> dp(n + 1, INF);
    dp[0] = 0;

    build(1,1,n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - k + 1; j++) {
            if (i - j + 1 >= k) {
                int median = get(1, 1, n, j, i);
                ll tot_le = sum_le(1, 1, n, j, i, median);
                ll cnt_le = count_le(1, 1, n, j, i, median);
                ll len = i - j + 1;
                ll tot = f[i] - f[j - 1];
                ll res = (median * cnt_le - tot_le) + ((tot - tot_le) - median * (len - cnt_le));

                if (dp[j - 1] != INF) {
                    dp[i] = min(dp[i], dp[j - 1] + res);
                }
            }
        }
    }

    if (dp[n] == INF) {
        cout << -1 << "\n";
    } else {
        cout << dp[n] << "\n";
    }
}
```
Độ phức tạp lúc này là: **O(N^2 * log(N) ^ 2 * 60)**
Vẫn còn quá lớn để có thể AC bài toán này

## Tối ưu 3
Ở trên, do vòng lặp xuất hiện n^2 luôn xuất hiện, khiến độ phức tạp lúc nào cũng là 1e4 * 1e4 = 1e8 không thể cho thêm bất cứ thao tác gì ở giữa hai vòng lặp, nên chúng ta sẽ tìm cách tối ưu vòng lặp lồng n^2 này

Gọi f(l,r) là giá trị để biến đoạn l->r về cùng một giá trị

Giả sử ta có hai đoạn
- f(l, k) có median là x1
- f(k + 1, r) có median là x2

Vậy thì lúc này, muốn tìm giá trị f(l,r) thì làm như thế nào?

Có thể thấy, chúng ta muốn tính f(l,r), cũng cần phải có median của đoạn từ l tới r (dựa vào công thức trên phần tối ưu 2), vậy sẽ xảy ra 3 trường hợp:

1. x1 == x2

Nếu trường hợp này xảy ra thì chi phí tối đa để biến đoạn f(l, r) về cùng một số là
$$f(l,k) + f(k + 1,r)$$

2. x1 != x2

**Giả sử x1 < x2**

Để chứng minh f(l,k) + f(k+1,r) ≤ f(l,r), ta cần so sánh hai cách tiếp cận:

**Cách 1: Tách thành 2 đoạn riêng biệt**
- Chi phí = f(l,k) + f(k+1,r)
- Đoạn [l,k] hội tụ về x1 (median của đoạn [l,k])
- Đoạn [k+1,r] hội tụ về x2 (median của đoạn [k+1,r])

**Cách 2: Xử lý toàn bộ đoạn [l,r] cùng lúc**
- Chi phí = f(l,r)
- Toàn bộ đoạn hội tụ về một giá trị x (median của [l,r])

### Phân tích chi tiết:

Gọi:
- Đoạn [l,k] có n1 phần tử
- Đoạn [k+1,r] có n2 phần tử
- x1 < x2 (do giả thiết)
- x là median của toàn đoạn [l,r]

Do x là median của [l,r] và x1, x2 là median của 2 đoạn con, ta có: **x1 ≤ x ≤ x2**

### Chứng minh:

**Chi phí cách 1 (tách 2 đoạn):**
$$\text{Cost}_1 = f(l,k) + f(k+1,r) = \sum_{i=l}^{k} |a_i - x_1| + \sum_{i=k+1}^{r} |a_i - x_2|$$

**Chi phí cách 2 (gộp cả đoạn):**
$$\text{Cost}_2 = f(l,r) = \sum_{i=l}^{r} |a_i - x|$$

Ta có thể viết lại Cost₂:
$$\text{Cost}_2 = \sum_{i=l}^{k} |a_i - x| + \sum_{i=k+1}^{r} |a_i - x|$$

### So sánh từng phần:

**Phần 1: Đoạn [l,k]**

Do x1 là median của đoạn [l,k], theo tính chất tối ưu của median:
$$\sum_{i=l}^{k} |a_i - x_1| \leq \sum_{i=l}^{k} |a_i - x|$$

Vì x1 ≤ x, và x1 là điểm tối ưu cho đoạn [l,k], nên khi ta chọn x (lớn hơn x1) thì chi phí sẽ tăng lên hoặc bằng.

**Phần 2: Đoạn [k+1,r]**

Tương tự, do x2 là median của đoạn [k+1,r]:
$$\sum_{i=k+1}^{r} |a_i - x_2| \leq \sum_{i=k+1}^{r} |a_i - x|$$

Vì x ≤ x2, và x2 là điểm tối ưu cho đoạn [k+1,r], nên khi ta chọn x (nhỏ hơn x2) thì chi phí sẽ tăng lên hoặc bằng.

### Kết luận:

Cộng 2 bất đẳng thức:
$$\sum_{i=l}^{k} |a_i - x_1| + \sum_{i=k+1}^{r} |a_i - x_2| \leq \sum_{i=l}^{k} |a_i - x| + \sum_{i=k+1}^{r} |a_i - x|$$

$$\Rightarrow f(l,k) + f(k+1,r) \leq f(l,r)$$

**Giải thích trực quan:**
- x1 là điểm tối ưu nhất cho đoạn [l,k], nên bất kỳ điểm nào khác (như x) đều có chi phí cao hơn hoặc bằng
- x2 là điểm tối ưu nhất cho đoạn [k+1,r], nên bất kỳ điểm nào khác (như x) đều có chi phí cao hơn hoặc bằng
- Khi gộp lại và chọn một median chung x (nằm giữa x1 và x2), ta "ép buộc" cả hai đoạn phải hội tụ về một điểm không tối ưu cho từng đoạn riêng lẻ
- Do đó, chi phí tổng cộng khi xử lý toàn bộ đoạn sẽ lớn hơn hoặc bằng chi phí khi xử lý từng đoạn riêng biệt

**Ý nghĩa:**
Điều này chứng tỏ rằng việc tách mảng thành K đoạn (thay vì để nguyên 1 đoạn) có thể giảm được tổng chi phí, vì mỗi đoạn có thể tối ưu riêng theo median của chính nó.

Có thể thấy, việc duyệt >= 2 * k phần tử vô chung 1 phần sẽ không tối ưu, vì vậy vòng lặp for có thể biến thành dạng:
```cpp=
for(int i = 1; i <= n; i++)
{
    for(int j = i - k; j >= i - 2k; i--)
    {

    }
}
```
từ đó tất cả các code ở trên đều có thể thay thế độ phức tạp từ n^2 xuống còn k*n, để thấy sự khác biệt thì n * n = 1e4 * 1e4 = 1e8 và n * k = 1e4 * 1e2 = 1e6 thao tác, nhanh hơn rất nhiều !

Từ đó, code tốt nhất của chúng ta ở phần **tối ưu 2** đã từ độ phức tạp lúc là: **O(N^2 * log(N) ^ 2 * 60)** xuống **O(n * k * log(N)^2 * 60)**

Bài toán này bây giờ đã được cố định độ phức tạp thời gian ít nhất là >= n * k, vậy nên độ phức tạp tối đa có thể chọn là n * k * log(n) (vừa đủ xấp xỉ 1e8)

## Tối ưu 4
Có thể thấy độ phức tạp mà chúng ta cần tối ưu là phần tính cost(j,i), đang chiếm độ phức tạp thời gian log(N)^2 * 60, cần tối ưu xuống log(n)

[Tìm median trong đoạn không cố định - Hackerrank](https://www.hackerrank.com/challenges/ctci-find-the-running-median/problem?fbclid=IwY2xjawOPtjVleHRuA2FlbQIxMQBzcnRjBmFwcF9pZAEwAAEeJjzeo-aafZfMKihO8YO-dbaGkrK8OFiCL5MiFB3ROJ2dRB1iuUHxabat3_8_aem_RD6qFz5AhdoW6756_3lVyQ)

Chúng ta cần phải có một tư tưởng khác, không phải là cố định tìm median trên đoạn j tới i nữa, mà cần là làm sao để lợi dụng từ những kết quả đã có trước đó mà tìm được median trong đoạn tiếp theo

**Giả sử những mảng sau đây đã sort**

Ta có mảng độ dài lẻ: [1,3,5,6,7]

Median = 5

Bây giờ nếu chúng ta thêm 1 phần tử nữa vào trong mảng đó thì median dịch chuyển như thế nào

Giả sử thêm phần tử > median hiện tại, lấy tạm 6

Mảng mới: [1,3,5,6,6,7]

Median vẫn là 5

Giả sử thêm phần tử <  median hiện tại, lấy tạm 3

Mảng mới: [1,3,3,5,6,7]

Median vẫn là 5 (có thể là 3 tuỳ theo cách tính)

Vậy có thể thấy, nếu là mảng độ dài lẻ thì thêm vào phần tử gì median vẫn giữ nguyên

Ta có mảng độ dài chẵn: [1,3,4,5,6,7]

Median là 4

Giả sử thêm phần tử > median hiện tại, lấy tạm 6

Mảng mới: [1,3,4,5,6,6,7]

Median đổi thành  5

Giả sử thêm phần tử <  median hiện tại, lấy tạm 3

Mảng mới: [1,3,3,4,5,6,7]

Median đổi thành 4

Vậy mảng chẵn khi thêm vào sẽ làm thay đổi phần tử trung vị

Từ đó rút ra,**đối với mảng đã sort**, chúng ta có thể dễ dàng **duy trì một con trỏ trỏ đến vị trí median hiện tại và tuỳ vào việc thêm vào có độ dài chẵn hay lẻ mà di chuyển con trỏ một cách phù hợp.**

Vậy thì câu hỏi tiếp theo là làm sao để duy trì một mảng đã sort để dễ xử lí

Chúng ta có thể sử dụng min_heap (priority_queue) hoặc multiset để xử lí một cách dễ dàng. Đáp ứng đủ thao tác thêm vào và gọi ra đều tốn độ phức tạo **O(logN)**, đủ để AC bài này.

Tuy nhiên nếu làm thao tác trên 1 mảng, với con trỏ di chuyển liên tục thì sẽ phải mất thêm thao tác để tính lại cntleft, cntright, sumleft, sumright để tính cost cuối cùng mà chúng ta sẽ update

Từ đó, chúng ta sẽ tách ra thành 2 cái min_heap.
Lúc này sumleft và sumright sẽ là tổng của 2 min_heap, có thể dễ dàng tính được bằng việc duy trì 2 biến sum1, sun2. Còn cntleft và cntright thì chúng ta sẽ tính bằng size của 2 priority_queue, hoàn toàn có thể làm được.


### 1. Tư tưởng cốt lõi: Median = “phần tử đứng giữa”

Giả sử ta đang xét một tập hợp các số:

```
S = { x₁, x₂, ..., x_m }
```

Sau khi sắp xếp:

```
sorted(S) = { a₁ ≤ a₂ ≤ … ≤ a_m }
```

* Nếu m lẻ → median = a_{(m+1)/2}
* Nếu m chẵn → ta thường lấy median "dưới" = a_{m/2}

**Ta muốn tìm ra phần tử đứng giữa mà không phải sort cả đoạn mỗi lần.**

---

### 2. Ý tưởng 2 heap: chia dữ liệu thành hai nửa

Ta duy trì hai tập:

#### • Left side (L) – max-heap

Chứa nửa “nhỏ hơn”.
Phần tử lớn nhất trong L là **ứng cử viên median**.

#### • Right side (R) – min-heap

Chứa nửa “lớn hơn”.
Phần tử nhỏ nhất trong R là “phần tử đứng ngay sau median”.

Ta đảm bảo 2 điều:

#### (1) Mọi phần tử trong L ≤ mọi phần tử trong R

Tức là:

```
max(L) ≤ min(R)
```

→ Hai nửa được chia giới hạn rõ ràng.

#### (2) |L| = |R| hoặc |L| = |R| + 1

Tức là L chứa số phần tử **không ít hơn R**.

Khi đó:

**Median luôn nằm ở top của L.**

---

### 3. Tại sao top(L) là median?

Giả sử có m phần tử.

Nếu m = 7 (lẻ), median là phần tử thứ 4.
Nếu m = 8 (chẵn), median dưới là phần tử thứ 4.

Ta muốn:

```
Kích thước L = 4
Kích thước R = 3   (lẻ)
hoặc
Kích thước L = 4
Kích thước R = 4   (chẵn)
```

L chứa **tất cả phần tử ≤ median**,
R chứa **tất cả phần tử > median**.

Vậy phần tử lớn nhất của L (top(L)) = median.

Đó chính là tư tưởng.

---

### 4. Cách duy trì hai heap (tư tưởng)

Khi **thêm 1 số mới x**:

* Nếu x nhỏ → đưa vào L.
* Nếu x lớn → đưa vào R.

Sau đó:

* Nếu L nhiều hơn R quá 1 → chuyển top(L) sang R.
* Nếu R nhiều hơn L → chuyển top(R) sang L.

Nhờ vậy:

```
|L| ~ |R|
và
max(L) ≤ min(R)
```

→ top(L) luôn là median.

---

### 5. Ví dụ minh họa từng bước

Giả sử cửa sổ / đoạn đang có các giá trị được thêm lần lượt:

```
[5, 2, 8, 1, 7]
```

---

#### Bước 1: thêm 5

```
L = [5]
R = []
Median = 5
```

---

#### Bước 2: thêm 2

2 ≤ 5 → vào L:

```
L = [5,2] → maxheap: top = 5
R = []
```

Nhưng L nhiều hơn R quá 1 → chuyển top(L)=5 sang R:

```
L = [2]
R = [5]
Median = 2
```

---

#### Bước 3: thêm 8

8 > median → vào R:

```
L = [2]
R = [5,8]  (minheap)
```

R nhiều hơn L → chuyển top(R)=5 sang L:

```
L = [5,2]
R = [8]
Median = 5
```

---

#### Bước 4: thêm 1

1 ≤ median → vào L:

```
L = [5,2,1]
R = [8]
```

L nhiều hơn R quá 1 → chuyển 5 sang R:

```
L = [2,1]
R = [5,8]
Median = 2
```

---

#### Bước 5: thêm 7

7 > median → vào R:

```
L = [2,1]
R = [5,8,7]
```

R nhiều hơn L → chuyển 5 sang L:

```
L = [5,1,2]
R = [7,8]
Median = 5
```

---

### Nhận xét sau khi thêm toàn bộ:

Các số ban đầu:

```
[5, 2, 8, 1, 7]
Sắp xếp: [1, 2, 5, 7, 8]
Median = 5
```

Heap cho ta đúng median = 5.

---

### 6. Vì sao cách này hay?

Không cần sort lại toàn bộ.
Chỉ cần:

* Thêm: O(log n)
* Lấy median: O(1)
* Xóa (dùng lazy deletion): O(log n)

Rất mạnh cho:
✔ Sliding window
✔ Online processing (dòng dữ liệu tới dần)
✔ Những bài K-th, median động

---

### 7. Tổng kết tư tưởng

| Khái niệm    | Ý nghĩa                               |   |   |   |   |
| ------------ | ------------------------------------- | - | - | - | - |
| 2 heap       | Chia mảng thành 2 nửa: nhỏ & lớn      |   |   |   |   |
| L (max-heap) | Chứa phần tử nhỏ hơn hoặc bằng median |   |   |   |   |
| R (min-heap) | Chứa phần tử lớn hơn median           |   |   |   |   |
| Invariant    | max(L) ≤ min(R) và                    | L | ≥ | R |   |
| Median       | = top(L)                              |   |   |   |   |

**TƯ TƯỞNG TRUNG TÂM**
Median là phần tử đứng giữa.
Ta dùng 2 heap để luôn giữ được phần tử đứng giữa tại đỉnh của L.
Việc duy trì chỉ tốn O(log n) mỗi lần.

Lưu ý: Phải tìm cách "cân bằng" hai heap sao cho chênh lệch hai heap tối đa chỉ có 1, lúc đó thì việc lấy cuối heap 1 hoặc đầu heap 2 mới có thể hoạt động
Trong code mẫu dưới đây mình sẽ luôn duy trì kích thước của maxheap lớn hơn, khiến median luôn rơi vào phần tử đầu của maxheap
Dứoi đây là code mẫu AC cho bài toán
```cpp=
/**
 * Giải bài toán chia mảng thành nhiều đoạn liên tiếp,
 * mỗi đoạn có độ dài ≥ k và được biến đổi sao cho tất cả phần tử bằng median.
 * Chi phí mỗi đoạn = tổng |a[i] - median|.
 *
 * dp[i] = chi phí nhỏ nhất để xử lý đến vị trí i.
 * Duyệt j từ i về i - 2k + 1 để tạo đoạn [j..i].
 * Dùng 2 heap để tính median + cost nhanh.
 */

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXX = 1e15;
const int N = 1e4;
const int K = 1e2;

int n, k;
int a[N + 5];

/**
 * Cấu trúc MedianHeap:
 * - maxHeap chứa nửa nhỏ hơn của đoạn
 * - minHeap chứa nửa lớn hơn của đoạn
 * - median luôn là maxHeap.top()
 *
 * sumLower = tổng phần tử maxHeap
 * sumUpper = tổng phần tử minHeap
 *
 * Công thức cost:
 *     cost = median * |lower| - sumLower
 *             + sumUpper - median * |upper|
 * Tương đương tổng |x - median|
 */
struct MedianHeap {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    ll sumLower = 0;
    ll sumUpper = 0;

    // tổng số phần tử hiện tại
    int get_size() {
        return maxHeap.size() + minHeap.size();
    }

    // thêm 1 giá trị vào cấu trúc
    void add(int x) {
        if (maxHeap.empty() || x <= maxHeap.top()) {
            maxHeap.push(x);
            sumLower += x;
        } else {
            minHeap.push(x);
            sumUpper += x;
        }
        balance();
    }

    // đảm bảo maxHeap luôn có nhiều hơn hoặc bằng minHeap
    void balance() {
        if (maxHeap.size() > minHeap.size() + 1) {
            int x = maxHeap.top(); maxHeap.pop();
            sumLower -= x;
            minHeap.push(x);
            sumUpper += x;
        }
        else if (minHeap.size() > maxHeap.size()) {
            int x = minHeap.top(); minHeap.pop();
            sumUpper -= x;
            maxHeap.push(x);
            sumLower += x;
        }
    }

    // median là phần tử lớn nhất trong nửa dưới
    int getMedian() {
        return maxHeap.top();
    }

    // tính chi phí biến tất cả phần tử hiện tại về median
    long long getCost() {
        ll median = getMedian();
        return median * maxHeap.size() - sumLower +
               sumUpper - median * minHeap.size();
    }
};

void input();
void solve();

int main() {
    input();
    solve();
}

// Quy hoạch động để tìm chi phí nhỏ nhất
void solve() {
    vector<ll> dp(n + 1, MAXX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {

        MedianHeap mh;

        // xét đoạn j → i
        // chỉ cần duyệt tối đa 2k phần tử ngược lại
        for (int j = i; j >= max(1, i - 2*k + 1); j--) {
            mh.add(a[j]);

            // chỉ cập nhật dp nếu độ dài đoạn ≥ k
            if (i - j + 1 >= k) {
                dp[i] = min(dp[i], dp[j - 1] + mh.getCost());
            }
        }
    }

    cout << dp[n] << "\n";
}

// đọc input
void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}
```
---




