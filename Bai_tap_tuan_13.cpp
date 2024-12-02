/*
Trong siêu thị người ta xếp hàng để thực hiện thanh toán. 
Mỗi giỏ hàng với các hàng hoá được coi như một node trong một cấu trúc hàng đợi.  
Yêu cầu: 
1. Khai báo cấu trúc hàng đợi. 
   Các thông tin chứa ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung sau được thực hiện 
2. Loại bỏ từng người ra khỏi hàng đợi sau khi người đó đã thực hiện thanh toán xong 
3. Tính tổng số tiền mà thu ngân thu được tại quầy trong một phiên làm việc  
4. Xác định số lượng một sản phẩm A đã được bán tại quầy thu ngân  
*/

#include <iostream>
#include <string> 
using namespace std;

//Khai báo cấu trúc lưu thông tin của một loại sản phẩm
struct Item
{
   string iName; //Tên sản phẩm 
   int iQuantity; //Số lượng mua một loại sản phẩm 
   double price; //Giá/1 sản phẩm 
};

//Khai báo cấu trúc hàng đợi 
//Cấu trúc của một Node trong cấu trúc queue (lưu thông tin của một khách hàng)
struct Customer
{
   string cName; //Tên khách hàng
   Item* itemList; //Danh sách các sản phẩm khách hàng đã mua
   int countList; //Số lượng sản phẩm trong danh sách
   Customer* next; 
};

struct Queue
{
   Customer* front; //Con trỏ trỏ tới khách hàng đầu tiên trong queue
   Customer* rear; //Con trỏ trỏ tới khách hàng cuối cùng trong queue
};

//Khởi tạo Queue
void Init(Queue* Q)
{
   Q->front = Q->rear = NULL;
}

//Kiểm tra Queue rỗng 
Customer isEmpty(Queue Q)
{
   return Q.front == NULL && Q.rear == NULL ? 1 : 0; 
}


