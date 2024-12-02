/*
BÀI 1: Định nghĩa một cấu trúc danh sách liên kết đơn để lưu trữ các file trong một thư mục D>Document trên máy tính. 
Các file được sắp xếp theo trật tự thời gian. Sau đó thực hiện tao tác:  

1. Khai báo cấu trúc của danh sách liên kết. Các thông tin chứa ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung sau được thực hiện 
2. Copy paste một file từ thư mục khác sang thư mục trên sao do file luôn được chèn vào theo trật tự thời gian  
3. Thực hiện tính toán tổng kích thước các file trong thư mục 
4. Người ta muốn sao lưu các file trong thư mục trên vào một ổ USB có kích thước 32G. Hãy thực hiện loại bỏ dần nếu cần một số file có kích thước nhỏ nhất để có thể thực hiện được thao tác trên.  

*/


#include <iostream>
#include <string> 
using namespace std; 

//1. Khai báo cấu trúc của danh sách liên kết đơn. Mỗi phần tử của danh sách lưu trữ 1 file của thư mục. 

//Khai báo cấu trúc của một node 
struct File
{
    string name; //Tên file 
    string addr; //Địa chỉ file 
    int time;    //Thời gian 
    double size; //Kích thước file (GB)
    File* link; //con trỏ trỏ tới node tiếp theo 
}; 

struct Folder
{
    File* firstNode, *lastNode; 
};

void init_Folder(Folder* folderD)
{
    folderD->firstNode = folderD->lastNode = NULL;
}


//Hàm tạo node mới 
File* newFile(string name, string addr, int time, double size)
{
    File* newNode = new File; 
    newNode->name = name; 
    newNode->addr = addr;
    newNode->time = time;
    newNode->size = size;
    newNode->link = NULL;
    return newNode; 
} 

//Hàm hiển thị các file trong thư mục 
void printFiles(Folder* folderD)
{
    File* p = folderD->firstNode; 
    cout << "Danh sach cac file co trong thu muc D>Document:\n";
    while(p)
    {
        cout << "Name: " << p->name
             << "\n     Addr: " << p->addr
             << "\n     Size: " << p->size << " GB"
             << "\n     Time: " << p->time << "\n";
        p = p->link;
    }
}


//2. Copy paste một file từ thư mục khác sang thư mục trên sao do file luôn được chèn vào theo trật tự thời gian  

//Hàm chèn file vào thư mục theo trình tự thời gian 
void addFile(Folder* folderD, File* newNode)
{
    //TH1: Nếu danh sách đang rỗng hoặc thời gian của file mới được copy sang lớn hơn thời gian của file đầu tiên trong danh sách thì chèn file mới vào đầu danh sách
   if ((folderD->firstNode == NULL) || (newNode->time < folderD->firstNode->time))
   {
        newNode->link = folderD->firstNode; 
        folderD->firstNode = newNode; 
        return; 
   }
    else
    {
   //TH2: Chèn vào sau 1 node nào đó trong danh sách 
   File* p = folderD->firstNode; 
   while ((p->link) && (p->link->time <= newNode->time))
        p = p->link;
    newNode->link = p->link; //Nối node mới vào sau node hiện tại 
    p->link = newNode; 
    }
}


//3. Thực hiện tính toán tổng kích thước các file trong thư mục 
double totalSize(Folder* folderD)
{
    double totalSize = 0; 
    File* p = folderD->firstNode; 
    while (p)
    {
        totalSize += p->size; 
        p = p->link; 
    }
    return totalSize; 
}

//4. Người ta muốn sao lưu các file trong thư mục trên vào một ổ USB có kích thước 32G. Hãy thực hiện loại bỏ dần nếu cần một số file có kích thước nhỏ nhất để có thể thực hiện được thao tác trên.  
//Hàm xóa file có kích thước nhỏ nhất trong thư mục 
 
int main()
{
    Folder folderD;
    init_Folder(&folderD);
    //Tạo danh sách các file trong thư mục
    addFile(&folderD, newFile("CTDLGT", "D:/Document/CTDLGT", 90924, 1.2));
    addFile(&folderD, newFile("XSTK", "D:/Document/XSTK", 80924, 1.2));
    addFile(&folderD, newFile("VLDCII", "D:/Document/VLDCII", 100924, 1.2));
    addFile(&folderD, newFile("TDTK", "D:/Document/TDTK", 120924, 1.2));
    addFile(&folderD, newFile("VLDT", "D:/Document/VLDT", 200924, 1.2));
    printFiles(&folderD);

    //Copy một file từ thư mục khác sang
    addFile(&folderD, newFile("TTCB", "C:/Document/TTCB", 281024, 1.2));
    printFiles(&folderD);

    //Tính tổng kích thước
    cout << "Tong kich thuoc cac file: " << totalSize(&folderD) << " GB" << endl;


    return 0;
}