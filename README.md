# Game

*	Tên trò chơi: 2048. 
*	Tên tác giả: Chu Minh Cương.
*	Thời gian hoàn thành: 18 ngày.
*	Luật chơi:
    +	2048 chơi trên một lưới vuông 4×4.Mỗi lần di chuyển là một lượt, người chơi sử dụng các phím mũi tên và các khối vuông sẽ trượt theo một trong bốn hướng tương ứng (lên, xuống, trái, phải)
    +	Mỗi lượt có một khối có giá trị 2 hoặc 4 sẽ xuất hiện ngẫu nhiên ở một ô trống trên lưới.
    +	Các khối vuông trượt theo hướng chỉ định cho đến khi chạm đến biên của lưới hoặc chạm vào khối vuông khác. Nếu hai khối vuông có cùng  giá trị chạm vào nhau, chúng sẽ kết hợp lại thành một khối vuông có giá trị bằng tổng giá trị hai khối vuông đó.
    +	Khối vuông kết quả không thể kết hợp với khối vuông khác một lần nữa trong một lượt di chuyển.
    +	Ban đầu điểm bằng 0.Khi hai khối vuông kết hợp thì người chơi sẽ tăng điểm là giá trị khối vuông mới. Bên cạnh điểm hiện tại là kỉ lục điểm cao nhất người chơi từng đạt được.
    +	Khi người chơi tạo được ô vuông có giá trị 2048 thì thắng cuộc. Khi không còn nước đi hợp lệ (không còn ô trống và các ô kề nhau đều khác giá trị) thì trò chơi kết thúc.
*	Hướng phát triển trò chơi trong tương lai:
    +   Tạo menu cho trò chơi: có thể chơi 1 người, 2 người hoặc đấu với máy.
    +	Tính thời gian chơi.
    +	Lưu lại 5 điểm cao nhất.
    +	Phát triển chơi 2 người: tạo 2 lưới ô vuông. Người chơi 1 sử dụng các phím W,A,S,D còn người chơi 2 sử dụng các phím mũi tên để di chuyển. 2 người chơi có thể chơi lần lươt hoặc cùng một lúc. Người giành chiến thắng là người sau khi kết thúc trò chơi có số điểm cao hơn.
    +	Phát triển chơi với máy: tạo 2 lưới ô vuông. Người chơi 1 sử dụng các phím W,A,S,D để di chuyển còn máy di chuyển ngẫu nhiên. Bên nào có điểm cao hơn thì bên đấy chiến thắng
