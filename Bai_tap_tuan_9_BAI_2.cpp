/*
Một câu tiếng việt cấu thành từ nhiều từ khác nhau. Mỗi từ được lưu thành một node trong một danh sách liên kết đơn 
1. Khai báo cấu trúc danh sách liên kết. Các thông tin chứa ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung sau được thực hiện 
2. Xác định từ xuất hiện nhiều nhất trong câu  
3. Nếu xuất hiện từ láy (cấu thành từ hai từ giống nhau ví dụ: xanh xanh), thực hiện loại bỏ một từ 
4. Thực hiện đếm số từ vựng xuất hiện trong câu. 
*/
#include <iostream>
using namespace std; 

//1. Khai báo cấu trúc danh sách liên kết
struct Word
{
    char word[50];
    Word* next; 
};

struct Sentence
{
    Word* firstNode, *lastNode;
};

void init_Sentence(Sentence* sentence)
{
    sentence->firstNode = sentence->lastNode = NULL; 
}

//Thêm một từ vào danh sách

