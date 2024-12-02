//BÀI 1
/*
Yêu cầu bài toán: Nhập vào n đối tượng có màu đỏ (red), trắng (white) và xanh (blue). 
                  Sắp xếp theo trật tự như sau: các đối tượng cùng màu nằm kế tiếp nhau và theo thứ tự đỏ, trắng, xanh.
Input: {xanh, đỏ, xanh, đỏ, đỏ, trắng, đỏ, xanh, trắng}
Output: {đỏ, đỏ, đỏ, đỏ, trắng, xanh, xanh, xanh}
Gợi ý: Có thể mã hóa các màu bằng các số nguyên 0,1,2 để biểu diễn lần lượt màu đỏ, trắng và xanh tương ứng.
Chú ý: Không sử dụng các thư viện hàm sắp xếp có sẵn để giải quyết bài toán trên khi cài đặt chương trình. 
*/

#include <stdio.h> 
int main()
{
    //n đối tượng có màu đỏ, trắng, xanh tạo thành một mảng 1 chiều có n phần tử nguyên. 
    //Trong đó các đối tượng màu đỏ, trắng và xanh được mã hóa tương ứng với các số nguyên 0,1,2.
    int n;
    int min_idx; 

    //Nhập vào số phần tử của mảng (n>0).
    printf("So phan tu cua mang: n = "); 
    do scanf("%d", &n);
    while(n <= 0);

    int arr[n];
    //Nhập vào các phần tử của mảng. 
    for(int i = 0; i < n; i++) 
    {
        do scanf("%d", &arr[i]); 
        while((arr[i] != 0) || (arr[i] != 1) || (arr[i] != 2));
    }

    //In ra các phần tử của mảng
    printf("Mang da tao: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    //Sử dụng thuật toán Selection Sort để sắp xếp mảng theo thứ tự tăng dần {0,1,2}
    for(int i = 0; i < n-1; i++)
    {
        //Tìm ra phần tử nhỏ nhất trong mảng chưa được sắp xếp 
        min_idx = i; 
        for (int j = i+1; j < n; j++)
            if(arr[j] < arr[min_idx])
                min_idx = j; 
        
        //Hoán đổi vị trí của phần tử nhỏ nhất với phần tử đầu tiên của mảng
        int temp = arr[min_idx]; 
        arr[min_idx] = arr[i];
        arr[i] = temp;  
    }

    //In ra mảng sau khi đã sắp xếp 
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]); 

    return 0;
    
    
}
