/*
BÀI 2: Thiết kế giải thuật và cài đặt để tạo ra một mảng số nửa nguyên tố (Blum) nhỏ hơn một số N cho trước và thực hiện hai yêu cầu sau
- Tìm ra tất cả các cặp số Blum có tổng cũng là một số Blum nhỏ hơn N
- Kiểm tra xem một số Blum M có tồn tại trong dãy số Blum được tạo ra hay không.
*/

/*
SỐ NỬA NGUYÊN TỐ (số Blum) 
là một số nguyên dương có dạng tích của hai số nguyên tố khác nhau, và cả hai số nguyên tố đó đều chia 4 dư 3.
*/


#include <stdio.h> 
#include <math.h> 

//Hàm kiểm tra một số có phải là số nguyên tố hay không. 
int isPrime(int n)
{
    int count = 0;    
    if (n <= 1) return 0; //n không là số nguyên tố 
    else 
        {
            for (int i = 2; i <= sqrt(n); i++)
            {
                if(n % i == 0) count += 1; 
            }
            if(count != 0) return 0; // n không là số nguyên tố 
        }
    return 1; 
}

//Hàm kiểm tra một số có chia 4 dư 3 không. 
int mod4is3(int n)
{
    return (n%4 == 3);
}

//Hàm kiểm tra xem một số có phải là số blum không. 
int isBlum(int n)
{
    //Duyệt qua các số nguyên tố nhỏ hơn căn bậc hai của n. 
    for(int i = 2; i <= sqrt(i); i++)
    {
        //Kiểm tra xem i số nguyên tố chia 4 dư 3 không. 
        if(isPrime(i) && mod4is3(i))
        {
            //Kiểm tra xem i có là ước của n không. 
            if (n % i == 0) 
            {
                //Tìm ước còn lại.
                int j = n/i; 
                //Kiểm tra j có là số nguyên tố chia 4 dư 3 và khác i không.
                if(isPrime(j) && mod4is3(j) && (j != i))
                return 1; //n là số blum. 
            }
        }
    }
    return 0; //Không là số blum.

}

int main()
{
    int N; //Số N cho trước
    printf("Nhap N = "); 
    do scanf("%d", &N);
    while(N <= 0); 

    int n;
    printf("Nhap n = "); //Số phần tử của mảng
    do scanf("%d", &n); 
    while( n <= 0); 

    //Khởi tạo mảng 
    int B[n]; 
    //Nhập các phần tử của mảng thỏa mãn là các số blum và nhỏ hơn N cho trước 
    for(int i = 0; i < n; i++)
    {
        do scanf("%d", &B[i]); 
        while (isBlum(B[i]) == 0 || B[i] >= N); 
    }

    //Tìm ra tất cả các cặp số Blum có tổng cũng là một số Blum nhỏ hơn N
    printf("Cac cap so blum thoa man yeu cau la:  "); 
    for(int i = 0; i < n; i++)
    {
        //Duyet qua lan luot cac phan tu con lai trong mang.
        for(int j = i + 1; j < n; j++)
        {
            //Tính tổng của phần tử thứ i với từng phần tử còn lại trong mảng.
            int sum = B[i] + B[j]; 
            //Kiểm tra điều kiện tổng có phải là số blum nhỏ hơn N cho trước không. 
            if(isBlum(sum) && sum < N) 
                printf("(%d, %d); ", B[i], B[j]); 
        }
    }

    //Kiểm tra xem một số Blum M có tồn tại trong dãy số Blum được tạo ra hay không.
    int M; 
    do scanf("%d", &M);
    while (isBlum == 0); 
    if(M >= N) printf("M khong ton tai trong mang B"); 
    else
    {
        for(int i = 0; i < n; i++)
            if (M == B[i]) break;
        printf("M co ton tai trong mang B");
    }
    printf("M khong ton tai trong mang B"); 
    return 0; 
}

    
    

