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

// Hàm nhập thông tin sản phẩm
void inforItem(Item item)
{
   cout << "  Nhap ten san pham: "; cin >> item.iName;
   cout << "  Nhap so luong san pham: "; cin >> item.iQuantity;
   cout << "  Nhap gia san pham: "; cin >> item.price;
}

//Khai báo cấu trúc hàng đợi 
//Cấu trúc của một Node trong cấu trúc queue (lưu thông tin của một khách hàng)
struct Customer
{
   string cName; //Tên khách hàng
   Item* itemList; //Danh sách các sản phẩm khách hàng đã mua
   int countList; //Số lượng các loại sản phẩm trong danh sách
   Customer* next; 
};

//Hàm nhập thông tin khách hàng 
void inforCustomer(Customer customer)
{
   cout << "Vui long nhap ten khach hang: "; cin >> customer.cName;
   cout << "  Nhap so luong san pham khach hang da mua: "; cin >> customer.countList;
   customer.itemList = new Item[customer.countList];
   //Nhập thông tin của từng loại sản phẩm 
   for (int i = 0; i < customer.countList; i++)
      inforItem(customer.itemList[i]);
}

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
int isEmpty(Queue Q)
{
   return Q.front == NULL? 1 : 0; 
}

//Thêm một khách hàng vào hàng đợi 
void push(Queue* Q, Customer customer )
{
   Customer* newCustomer = new Customer; //Khách hàng mới
   *newCustomer = customer; 
   newCustomer->next = NULL;

   //Nếu hàng đợi rỗng, front vs rear đều trỏ tới newCustomer
   if (isEmpty(*Q)) Q->front = Q->rear = newCustomer;
   else
   {
      Q->rear->next = newCustomer; 
      Q->rear = newCustomer; 
   }
}

//Loại bỏ khách hàng đã thanh toán khỏi hàng đợi 
void checkout(Queue* Q)
{
   if (isEmpty(*Q))
   {
      cout << "Khong co khach hang nao!" << endl;
      return;
   }

   Customer* temp = Q->front; 
   double totalPrice = 0; //Tổng tiền cần thanh toán 
   //Tính tổng số tiền cần thanh toán 
   for (int i = 0; i < temp->countList; i++)
      totalPrice += temp->itemList[i].iQuantity * temp->itemList[i].price; 
   
   cout << "Khach hang " << temp->cName << " checkout thanh cong!" << endl;

   //Cập nhật front trỏ tới khách hàng sau 
   Q->front = Q->front->next;

   //Nếu không còn khách hàng phía sau thì hàng đợi rỗng, cập nhật rear = NULL. 
   if (Q->front == NULL) Q->rear = NULL;

   //Giải phóng bộ nhớ 
   delete[] temp->itemList; 
   delete temp; 
}

//Tính tổng số tiền mà thu ngân thu được tại quầy trong một phiên làm việc
double totalRevenue(Queue* Q)
{
   double totalRevenue = 0; 
   Customer* p = Q->front; 
   while(p != NULL)
   {
      for (int i = 0; i < p->countList; i++)
         totalRevenue += p->itemList[i].iQuantity * p->itemList[i].price;
      p = p->next; 
   }

   return totalRevenue; 
}

//Xác định số lượng một sản phẩm A đã được bán tại quầy thu ngân  
int countA(Queue* Q, string A_Name)
{
   int countA = 0;
   Customer* p = Q->front;

   while (p != NULL) {
      for (int i = 0; i < p->countList; i++) 
      {
         if (p->itemList[i].iName == A_Name)
            countA += p->itemList[i].iQuantity;
      }
      p = p->next; 
   }

   return countA;
}

int main()
{
   Queue Q; 
   Init(&Q);

   int N;
   cout << "So luong khach hang la: "; cin >> N; 

   //Nhập thông tin khách hàng và cho hàng đợi 
   for (int i = 0; i < N; i++)
   {
      Customer customer; 
      inforCustomer(customer);
      push(&Q, customer); 
   }

   int choice; 
   do 
   {
      cout << "\n1. Thanh toan cho khach hang dau tien\n"
           << "2. Xem tong doanh thu\n"
           << "3. Xem so luong san pham A da ban\n"
           << "4. Thoat\n"
           << "Chon: ";
      cin >> choice; 

   switch(choice)
   {
      case 1: 
      {
         checkout(&Q); 
         break;
      }
      case  2:
      {
         double totalrevenue = totalRevenue(&Q); 
         cout << "Tong doanh thu = " << totalrevenue << " VND" << endl; 
         break;
      }
      case 3:
      {
         string A_Name;
         cout << "San pham can kiem tra so luong da ban: "; cin >> A_Name; 
         int count = countA(&Q, A_Name);
         cout << "So luong san pham " << A_Name << " da ban la: " << countA << endl; 
         break; 
      }
      case 4: 
         cout << "Thoat" << endl; 
         break; 
      default:
         cout << "Lua chon khong hop le! Vui long chon lai." << endl;
   }
   } while (choice != '4');
   return 0;

}






