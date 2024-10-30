/*
YÊU CẦU:
Cài đặt danh sách móc nối để nhập và in một đa thức với phương thức cấp phát động tối ưu 
- Có kiểm tra điều kiện nhập hệ số bằng 0 thì sẽ giải phóng cấp phát phần tử và không liên kết vào hàm tạo đa thức 
- Submit lên git và chụp ảnh kết quả chạy trên màn hình 
*/

/*
Cài đặt một danh sách móc nối để lưu trữ đa thức.
- Mỗi phần tử (node) của danh sách - đại diện cho một đơn thức trong đa thức, gồm: 
    + Hệ số của một đơn thức thuộc đa thức. 
    + Số mũ của một đơn thức thuộc đa thức. 
    + Một con trỏ liên kết tới node tiếp theo. 
- Khi nhập hệ số, nếu hệ số bằng 0 thì node sẽ không được tạo. 
- Nếu hệ số khác 0, chương trình sẽ cấp phát bộ nhớ động cho node và thêm vào danh sách.
- Duyệt qua từng node trong danh sách và in ra thành một đa thức. 

f(x) = x^10+1;
g(x) = x^15+ x^10+ x^7+x^5+x^2+1

*/

#include <stdio.h>
#include <stdlib.h>

//Định nghĩa cấu trúc của một node thuộc danh sách
struct NodeDT
{
    float heso; //Hệ số 
    int somu;   //Số mũ
    struct NodeDT* next; //Con trỏ trỏ tới node kế tiếp
};
typedef struct NodeDT NodeDT; 

struct ListDT 
{
    NodeDT* first; //Con trỏ trỏ đến phần tử đầu tiên của list
    NodeDT* last;  //Con trỏ trỏ tới phần tử cuối cùng của list
};
typedef struct ListDT ListDT; 

//Khởi tạo danh sách đa thức
void initDT(ListDT* dsDT) 
{
    dsDT->first = dsDT->last = NULL; //Danh sách ban đầu là rỗng 
}

//Tạo một node mới nếu hệ số khác 0 
NodeDT* callNode(float hs, int sm) 
{
    if (hs == 0) return NULL; // Hệ số bằng 0 thì không tạo node mới 
    NodeDT* p = (NodeDT*)malloc(sizeof(NodeDT)); //Con trỏ trỏ tới node mới 
    if (p == NULL) return NULL;
    p->heso = hs;
    p->somu = sm;
    p->next = NULL;
    return p;
}

//Thêm node p vào cuối danh sách
void addNode(ListDT* dsDT, NodeDT* p) 
{
    if (dsDT->first == NULL) //Phần tử đầu tiên của danh sách = NULL => Danh sách rỗng 
        dsDT->first = dsDT->last = p; 
    else 
    {
        dsDT->last->next = p; //Thành phần con trỏ của node cuối trỏ tới node tiếp theo là p (Gán địa chỉ của p cho con trỏ của node cuối)
        dsDT->last = p; //Cập nhật node cuối là p
    }
}

//Thêm node với hệ số và số mũ cho trước
void attachNode(ListDT* dsDT, float hs, int sm) 
{
    NodeDT* pDT = callNode(hs, sm);
    if (pDT != NULL) // Chỉ thêm node nếu node hợp lệ
        addNode(dsDT, pDT);
}

//Tạo đa thức
void taoDT(ListDT* lDT) 
{
    float hs;
    int sm;
    int i = 0;
    printf("Bat dau nhap da thuc (nhap he so 0 de ket thuc): \n");
    do 
    {
        i++;
        printf("Nhap phan tu thu %d\n", i);
        printf("Nhap he so: ");
        scanf("%f", &hs);
        if (hs == 0) break;
        printf("Nhap so mu: ");
        scanf("%d", &sm);
        attachNode(lDT, hs, sm);
    } while (hs != 0);
    printf("Ket thuc nhap\n");
}

//In đa thức
void inDT(ListDT dsDT) 
{
    NodeDT* p = dsDT.first;
    printf("\nf(x) = ");
    int first = 1; // Đánh dấu hạng tử đầu để tránh in dấu "+"
    while (p != NULL) 
    {
        if (p->heso != 0) 
        {
            if (!first) printf(" + ");
            printf("%.0f*x^%d", p->heso, p->somu);
            first = 0;
        }
        p = p->next;
    }
    printf("\n");
}

//Giải phóng bộ nhớ của danh sách
void freeDT(ListDT* dsDT) 
{
    NodeDT* p;
    while (dsDT->first != NULL) {
        p = dsDT->first;
        dsDT->first = dsDT->first->next;
        free(p);
    }
    dsDT->last = NULL; // Đảm bảo last trỏ NULL sau khi giải phóng
}

int main() {
    ListDT DT1;
    initDT(&DT1);
    taoDT(&DT1);
    inDT(DT1);
    freeDT(&DT1);
    return 0;
}