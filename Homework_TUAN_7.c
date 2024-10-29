//Cài đặt danh sách quản lý dân số, để tìm số năm có cùng số lượng người sinh ra, in ra các năm có số lượng người sinh ra là lớn nhất và bé nhất. 
#include <stdio.h>

//Tạo struct lưu trữ danh sách quản lý thông tin về năm và số lượng người sinh ra trong năm. 
struct Danso
{
    int nam; 
    int so_nguoi_sinh_ra; 
};
typedef struct Danso Danso; 

//Hàm tìm số năm có cùng số lượng người sinh ra 
void Same(Danso DS[], int n)
{
    printf("\nCac nam co cung so nguoi sinh ra:\n");
    int kt = 0; 
    for (int i = 0; i < n; i++)
    {
        int count = 0; 
        for(int j = i + 1; j < n; j++)
        {
            if (DS[i].so_nguoi_sinh_ra == DS[j].so_nguoi_sinh_ra)
            {
                if (count == 0) 
                {
                    printf("Cac nam cung co %d nguoi sinh ra la: ", DS[i].so_nguoi_sinh_ra);
                    printf("%d ", DS[i].nam);
                }
                printf("%d ", DS[j].nam);
                count++;
                kt = 1;
            }
        }
        if (count > 0) printf("\n");
    }
    if (kt == 0) printf("Khong co nam nao co cung so nguoi sinh ra\n");
}

//Hàm tìm ra số lượng người sinh ra là lớn nhất
void Max(Danso DS[], int n)
{
    int max = DS[0].so_nguoi_sinh_ra;
    int nam_lon_nhat = DS[0].nam;
    for(int i = 1; i < n; i++)
    {
        if (DS[i].so_nguoi_sinh_ra > max) 
        {
            max = DS[i].so_nguoi_sinh_ra;
            nam_lon_nhat = DS[i].nam;
        }
    }
    printf("Nam %d co so luong nguoi sinh ra la lon nhat voi %d nguoi", nam_lon_nhat, max);
}

//Hàm tìm ra số lượng người sinh ra là nhỏ nhất
void Min(Danso DS[], int n)
{
    int min = DS[0].so_nguoi_sinh_ra;
    int nam_nho_nhat = DS[0].nam; 
    for (int i = 1; i < n; i++)
    {
        if (DS[i].so_nguoi_sinh_ra < min)
        {
            min = DS[i].so_nguoi_sinh_ra; 
            nam_nho_nhat = DS[i].nam;
        }
    }
    printf("Nam %d co so luong nguoi sinh la nho nhat voi %d nguoi", nam_nho_nhat, min); 
    
}

int main()
{
    int n; //n là số lượng năm cần quản lý 
    printf("Nhap so luong nam: "); scanf("%d", &n);

    //Khởi tạo một mảng có kiểu cấu trúc Danso, mỗi phần tử của mảng sẽ lưu trữ dữ liệu của một năm và số lượng người sinh ra trong năm đó. 
    Danso DS[n];
    
    //Nhập dữ liệu danh sách cần quản lý
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &DS[i].nam);
        scanf("%d", &DS[i].so_nguoi_sinh_ra); 
    }

    //In ra danh sách cần quản lý 
    printf("\n%-10d %-20d\n", "Nam","So nguoi sinh ra");
    for (int i = 0; i < n; i++)
    {
       printf("\n%-10s %-20s\n", DS[i].nam, DS[i].so_nguoi_sinh_ra); 
    }

    //In ra các năm có cùng số lượng sinh ra 
    printf("\n"); 
    Same(DS, n); 
    //In ra các năm có số lượng người sinh ra là lớn nhất và nhỏ nhất
    printf("\n");
    Max(DS, n); 
    Min(DS, n);
    return 0; 
    

}