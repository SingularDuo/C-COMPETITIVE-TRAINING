# 📘 Bài toán: Tìm nghiệm của phương trình đồng dư $ax \equiv b \pmod{m}$

---

## 🧩 Tổng quan

Xét phương trình đồng dư tuyến tính một ẩn:

$$
ax \equiv b \pmod{m}
$$

Với:

* $a, b, m \in \mathbb{Z}$
* $m > 0$
* $x \in \mathbb{Z}$ là ẩn số cần tìm.

**Yêu cầu:**
Tìm tất cả giá trị nguyên **không âm, không đồng dư với nhau theo modulo $m$** thỏa mãn phương trình.

---

## 📥 Input

Một dòng gồm 3 số nguyên:

$$
a\ b\ m
$$

**Ràng buộc:**

* $-10^9 \leq a, b \leq 10^9$
* $0 < m \leq 10^9$

---

## 📤 Output

* Dòng đầu tiên: Số lượng nghiệm nguyên không âm, khác nhau theo modulo $m$
* Các dòng sau: Liệt kê nghiệm theo thứ tự tăng dần.

⚠️ **Đảm bảo**: Số nghiệm không vượt quá $10^5$

---

## 🔍 Phân tích

Ta có:

$$
ax \equiv b \pmod{m} \Rightarrow m \mid (ax - b)
\Rightarrow ax - b = mk \quad (k \in \mathbb{Z})
\Rightarrow ax + m(-k) = b \tag{1}
$$

Phương trình (1) là một **phương trình Diophantine**. Để giải, ta dùng **thuật toán Euclid mở rộng**.

---

### 🎯 Điều kiện có nghiệm:

* Gọi $d = \gcd(a, m)$
* Phương trình có nghiệm **khi và chỉ khi** $d \mid b$

---

### 🔄 Thuật toán Euclid mở rộng

Tìm $s, t \in \mathbb{Z}$ sao cho:

$$
a \cdot s + m \cdot t = d
$$

\=> Nhân cả hai vế với $\frac{b}{d}$, ta được:

$$
a \cdot \left( s \cdot \frac{b}{d} \right) + m \cdot \left( t \cdot \frac{b}{d} \right) = b
$$

Từ đó, nghiệm tổng quát của phương trình ban đầu là:

$$
x = s \cdot \frac{b}{d} + \frac{m}{d} \cdot k \tag{2}
$$

với $k \in \mathbb{Z}$

---

## 📚 Tìm tất cả nghiệm phân biệt theo modulo $m$

* Bước nhảy giữa các nghiệm: $\frac{m}{d}$
* Có $d$ nghiệm phân biệt theo modulo $m$, tương ứng với $k = 0, 1, \dots, d - 1$

Công thức tổng quát:

$$
x_k = \left( s \cdot \frac{b}{d} + \frac{m}{d} \cdot k \right) \bmod m
\quad \text{với } k = 0 \rightarrow d - 1
$$

---

## ✅ Kết luận

* Phương trình có nghiệm ⟺ $\gcd(a, m) \mid b$
* Số nghiệm: $d = \gcd(a, m)$
* Các nghiệm được tính theo công thức:

$$
x_k = \left( s \cdot \frac{b}{d} + \frac{m}{d} \cdot k \right) \bmod m
$$

với $k = 0, 1, \dots, d - 1$

---

## 🛠️ Cài đặt Euclid mở rộng (C++)

```cpp
// Trả về gcd và gán s, t sao cho: a*s + b*t = gcd(a, b)
int extended_gcd(int a, int b, int &s, int &t) {
    if (b == 0) {
        s = 1;
        t = 0;
        return a;
    }
    int s1, t1;
    int d = extended_gcd(b, a % b, s1, t1);
    s = t1;
    t = s1 - (a / b) * t1;
    return d;
}
```

---

## 🔍 Tối ưu hóa – Tránh TLE

Nếu bạn cố duyệt nghiệm bằng brute-force theo công thức:

$$
a \cdot x + m \cdot y = b
$$

và thử mọi giá trị của $x$ hoặc $y$, chắc chắn sẽ bị **TLE** với $m \leq 10^9$.

Do đó cần dùng **thuật toán Euclid mở rộng** để:

* Tìm nghiệm cơ sở $(s, t)$
* Suy ra nghiệm tổng quát nhanh chóng
* Tránh lặp vô ích

---

## 🔄 Tái diễn nghiệm trong Euclid mở rộng

Giả sử ở bước đệ quy:

$$
\text{gọi } d = \gcd(a, b) = \gcd(b, a \bmod b)
$$

Sau mỗi bước, phương trình được rút thành:

$$
b \cdot x' + r \cdot y' = d \quad \text{(với } r = a \bmod b \text{)}
$$

Suy ra:

$$
a = q \cdot b + r \Rightarrow r = a - q \cdot b
$$

Thế vào:

$$
d = b \cdot x' + (a - q \cdot b) \cdot y'
= a \cdot y' + b \cdot (x' - q \cdot y')
$$

Do đó:

$$
x = y', \quad y = x' - q \cdot y'
$$

\=> **Cập nhật nghiệm $(x, y)$ theo nghiệm ở bước sau**

---

Rất tốt! Dưới đây là **ví dụ minh họa cụ thể** về việc **dùng thuật toán Euclid mở rộng để tìm các số nguyên $x, y$** sao cho:

$$
a \cdot x + b \cdot y = \gcd(a, b)
$$

---

## ✨ Ví dụ: Tìm $x, y$ sao cho $101 \cdot x + 23 \cdot y = \gcd(101, 23)$

### 🔹 Bước 1: Tính $\gcd(101, 23)$

Áp dụng Euclid thường:

```
101 = 4 × 23 + 9
 23 = 2 × 9 + 5
  9 = 1 × 5 + 4
  5 = 1 × 4 + 1
  4 = 4 × 1 + 0
⇒ gcd = 1
```

---

### 🔹 Bước 2: Dùng Euclid mở rộng để truy vết $x, y$

Ta đi ngược lại từ:

```
1 = 5 - 1 × 4
  = 5 - 1 × (9 - 1 × 5)
  = 2 × 5 - 1 × 9
  = 2 × (23 - 2 × 9) - 1 × 9
  = 2 × 23 - 5 × 9
  = 2 × 23 - 5 × (101 - 4 × 23)
  = 2 × 23 - 5 × 101 + 20 × 23
  = (2 + 20) × 23 - 5 × 101
⇒ 1 = 22 × 23 - 5 × 101
```

---

### ✅ Kết quả:

$$
\boxed{101 \cdot (-5) + 23 \cdot 22 = 1}
\Rightarrow x = -5,\ y = 22
$$

---

## 📌 Tổng quát:

Từ $a = 101,\ b = 23$, ta có:

$$
\gcd(101, 23) = 1
\Rightarrow \exists\ x = -5,\ y = 22\ \text{thoả mãn: } 101x + 23y = 1
$$

---

## 🛠️ Cài đặt tương ứng trong C++

```cpp
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}
```

Ví dụ sử dụng:

```cpp
int main() {
    int a = 101, b = 23, x, y;
    int d = extended_gcd(a, b, x, y);
    cout << "gcd(" << a << ", " << b << ") = " << d << '\n';
    cout << "x = " << x << ", y = " << y << '\n';
    // Kiểm tra: a*x + b*y == d
    cout << "Check: " << a << "*" << x << " + " << b << "*" << y << " = " << (a*x + b*y) << '\n';
}
```


