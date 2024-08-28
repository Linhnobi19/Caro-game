Đầu tiên là về giao diện game Caro thì ở đây sẽ dùng các state để điều hướng sang các màn hình thông qua thuộc tính visible, và để tạo  thêm hiệu ứng chuyển cảnh thì dùng thêm opacity
Và mỗi khi chuyển sang các màn hình khác thì thay đổi state và sử dụng SequentialAnimation để tạo hiệu ứng điều hướng
![image](https://github.com/user-attachments/assets/23006ce4-e465-45a7-9ba8-3a3e7d463113)
Với màn hình đăng nhập thì có 2 lựa chọn là chơi giữa 2 người với nhau hoặc đấu với BOT. Khi click vào chơi với BOT thì không thể nhập tên Player2 nữa 
![image](https://github.com/user-attachments/assets/1f53e1e9-9b07-4f84-8a84-c27ad0855a2b)
Và khi muốn chọn chế độ chơi thì trỏ đến trên thanh menuBar chọn GameMode và lựa chọn các chế độ đấu với BOT
![image](https://github.com/user-attachments/assets/85d257e3-b72a-48de-a78b-770359c051b7)
Sau khi enter tên người chơi ấn submit thì dữ liệu được xử lý dưới C++ và check xem tên người chơi có phù hợp hay không thì gửi lại biến bool. Nếu tên không hợp lệ thì sẽ có dòng chữ cảnh báo nhấp nháy với các kiểu dữ liệu không thỏa mãn như: Nickname không được có dấu cách, maximum 32 ký tự, 2 tên người chơi không được trùng nhau
![image](https://github.com/user-attachments/assets/14bd146c-4d21-4e4c-83c6-a41ee076232b)
Nếu thỏa mãn thì sẽ tiến hành kiểm tra xem người chơi đó đã tồn tại hay chưa, nếu chưa thì sẽ tiến hành khởi tạo

Tiếp đến là phần chơi game
2 bên màn hình là thông tin người chơi với Player1 luôn là người đi trước và đánh O, màu xanh và thời gian suy nghĩ của player1 cũng được đếm
![image](https://github.com/user-attachments/assets/986ad13f-2959-4b8e-a1ae-55eac384c2fe)
Ở dưới bàn cờ có 3 nút là Concede, Undo, Quit match
Khi chọn concede thì sẽ hiện thị lên 1 message box để xác nhận lựa chọn
![image](https://github.com/user-attachments/assets/b62ca142-2c75-4d90-8076-7d5006520027)
Nếu chọn yes thì lúc này đang ở lượt người chơi nào thì người đó sẽ thua và người còn lại sẽ chiến thắng
Hoặc là nếu như muốn Undo thì sẽ remove nước trước đó và trở lại phần di chuyển của player vừa ấn undo
Còn nút cuối là Quit match thì sẽ hiển thị 1 message box để xác nhận người chơi không còn tiếp tục và out game --> kết thúc chương trình --> không ảnh hưởng đến kết quả trận đấu

Tiếp đến là khi đấu BOT
Với Bot mode hard thì sử dụng thuật toán minimax để tìm ra nước đi tiếp theo. Khi Bot đang suy nghĩ thì ta sẽ không thể tương tác với các nút phía dưới bàn cờ cũng những là click trên bàn cờ được nữa 
Và khi đã vào trận đấu thì không thể chọn lựa mức độ khó cho game được nữa.
![image](https://github.com/user-attachments/assets/4a02809d-ef90-465c-b121-f5fc45743df1)


Tiếp đến là khi có người chiến thắng thì sẽ hiển thị màn hình thông báo kết quả trận đấu
![image](https://github.com/user-attachments/assets/3c35ed56-c3dd-45f0-8c74-427e3de8b61a)
Và nếu Quitmatch thì sẽ quay về màn hình đăng nhập
Nếu lựa chọn replay thì quay trở lại ván chơi để xem lại trận đấu
![image](https://github.com/user-attachments/assets/e3ca564e-801f-4db0-86b6-64d6049bafe5)
Lúc này thì lựa chọn nextmove, prevmove để hiện thị các nước tiếp  theo, nước phía trước. Và để thoát ra khỏi màn hình replay thì sẽ ấn quitmatch trở lại màn hình thông báo

Tiếp đến là màn hình search thông tin người chơi bằng cách di chuyển lên menubar và lựa chọn GameHistory
![image](https://github.com/user-attachments/assets/52a8e696-adea-4eec-bd80-1a6500288c83)
Ở đây sẽ có 2 phần là tìm kiếm thông tin người chơi và những người cùng 1 rank. Khi mà không có input thì những người cùng 1 rank sẽ được hiển thị tất và để lựa chọn các cấp độ khác thì sẽ chọn vào combo box.
Phần tìm kiếm này thì mỗi lần nhập thông tin thì sẽ hiển thị ra những player có ký tự đó trong nickname. Đến lúc này thì phần hiển thị sameRank sẽ hiển thị nhưng người mà được tìm kiếm ở trên phân theo từng rank tương ứng

Cuối cùng là màn hình hướng dẫn bằng cách di chuyển lên Guide document
![image](https://github.com/user-attachments/assets/d81b71d6-7cf5-4cef-9f56-6ec55146c568)
