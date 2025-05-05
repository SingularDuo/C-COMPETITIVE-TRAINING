# Giai thich
###### unikey bi loi nen e chiu kho doc khong dau nhe =))

##
**Buoc 1:** Input string
- O day a se lay vi du de bai la $A79C3e8$ va $k = 2$

### Xoa het chu cai
Duyet qua het string va thay cai nao thi la chu cai thi e dung erase() de xoa chu cai do ra khoi string => Sau qua trinh nay thi string con lai toan so
*No la vong for va cai bien to_delete cua anh dang lam*

### Vay gio xau con lai toan so roi, lam sao de lay duoc so lon nhat co $k$ chu so?*

- Trong bai nay a e su dung tham lam de kiem so lon nhat co the 
###### Cai bang AI tao dung hoi a 

| Character | Result Before | Action | Result After | to_delete |
|-----------|---------------|--------|--------------|-----------|
| '7'       | ""            | Add    | "7"          | 2         |
| '9'       | "7"           | 9>7, remove 7 | "9"   | 1         |
| '3'       | "9"           | 3<9, add | "93"       | 1         |
| '8'       | "93"          | 8>3, remove 3 | "98"  | 0         |

==> ket qua cuoi cung la: $98$

### TONG KET:
**BUOC 1:** Xoa het chu cai trong string
**BUOC 2:** Tao ra so lon nhat bang tham lam(*greedy*)
    - Voi moi chu so, neu nhu no lon hon chu so truoc do va *to_delete > 0* tuc la van con co the thay doi thi minh bo so cuoi (pop_back()) va bo chu so moi vo, dong thoi *to_delete--*
**That ra con 1 buoc nx nhx ma a xoa me r, chac ko can toi dau, neu WA do dap an ngu thi e tu suy nghi thu=))**

**Mot so kien thuc:** de mot so la toi uu thi chung ta mong muon so dung can ve ben trai thi gia tri cang lon, khi gap mot so nho hon thi chung ta co the loai bo so truoc do de thay the bang 1 so ngon hon