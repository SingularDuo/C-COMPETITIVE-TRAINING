# Quy hoạch động - Dynamic Programming - Cách giải quyết & những vấn đề xoay quanh nó

## Quy hoạch động là gì ?
- Thông thường, trong lập trình thi đấu, quy hoạch động thường là một bài toán được xử lí bằng các bài toán nhỏ trước đó, có thể là quy hoạch động trên mảng 1 chiều,  2 chiều, có thể là duyệt tuyến tính thông thường, 2 vòng lặp,...
- Để ví dụ cho dễ hình dung, ta có một bài toán cơ bản:
> Cho một con ếch, với mỗi bước nhảy chúng có thể nhảy qua $K[i]$ (gọi $N$ là số lượng bậc thang) bậc thang. Ban đầu nó bắt đầu tại 0, và cần nhảy đến điểm $target$ cho trước, hỏi có bao nhiêu cách nhảy từ ô 0 đến ô $target$?

- Nhìn vào bài toán này, nếu chưa biết gì về quy hoạch động, có thể chúng ta sẽ chỉ biết được việc dùng quay lui để sinh ra tất cả trường hợp, vậy nếu giới hạn của bài này quá lớn ($N, target$ lên đến 1e7) thì liệu việc quay lui có thật sự hiệu quả?

### Nhận xét bài toán
- Chúng ta có thể dễ dàng nhận ra trong bài toán trên, một con ếch muốn nhảy đến vị trí $target$, thì nó bắt buộc phải nhảy từ vị trí $target - K[0]$ -> $target - K[n-1]$.
- Từ đây chúng ta nhận ra được một bài toán nhỏ hơn là:
> Với mỗi ô từ $target - K[0]$ -> $target - K[n-1]$, liệu mỗi ô này có thể đến được từ những ô nào, và với bao nhiêu bước, bao nhiêu cách?
- Đến đây chắc hẳn bạn đọc đã nhận ra việc bài toán lớn đến từ bài toán nhỏ hơn rồi
    - Bài toán lớn là số cách đến ô $I$
    - Bài toán nhỏ là số cách đến ô $I - K[0 - > n-1]$

### Thực hiện bài toán quy hoạch động
- Trong quy hoạch động, khi thực hiện một bài toán, ta cần xác định 