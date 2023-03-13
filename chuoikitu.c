#include <stdio.h>

char arr[] = "The Grammy award-winning singer. who has been less active on digital platforms in recent weeks. Explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";

//Cau 1: Viet mot chuyen dao nguoc VD: "Finneas brother her alongside .... Grammy The"
//cau 2: In Hoa chu cai dau tien sau dau cham
//Cau 3: Chuyen doi tat ca doan van thanh chu thuong
//Cau 4: Chuyen doi tat ca doan van thanh chu hoa

void Inversion() // khai báo hàm đảo ngược
{
    int length = sizeof(arr); //kích thước của mảng
    int dem=0;  // khai báo biến đếm để đếm số lượng chữ cái trong một từ
    for(int i =length; i>=0; i--) // duyệt các phần tử trong mảng bắt đầu từ phần tử cuối
    {
        dem++; // biến đếm để đếm số lượng chữ cái trong 1 từ
        if(*(arr + i) == ' ') // xét đến lúc nào gặp dấu cách
        {
            for(int j = i+1; j < i + dem ; j++)
            {
                printf("%c", *(arr + j)); // in ra từ đấy
            }
            printf("%c", ' '); // in ra dấu cách
            dem=0;
        }
        if (i == 0) // in ra chữ đầu tiên vì trước từ đầu tiên không có dấu cách
        {
            for (int j = 0; j < length; j++)
            {
                if (*(arr + j) == ' ')
                {
                    for (int k = 0; k < j; k++)
                    {
                        printf("%c", *(arr + k));
                    }
                    break;  // in ra chữ đầu tiên xong break vòng for
                }
            }
        } 
    }
    
}
void capital_letter_after_the_dot() // khai báo hàm in hoa chữ cái đầu tiên sau dấu chấm
{
    for(int i=0; i<sizeof(arr); i++)
    {
          
        if(*(arr+i) =='.' && 97<=*(arr+i+2) && *(arr+i+2)<= 122) // a = 97, z = 122
        {
            *(arr+i+2) = *(arr+i+2)-32; // chũ thường - 32 = chữ hoa
        }
        printf("%c", *(arr+i)); 
    }
}
void plain_Print() // hàm khai báo chuyển đổi tất cả thành chữ thường
{
    for(int i=0; i<sizeof(arr); i++)
    {
          
        if( 65<=*(arr+i) && *(arr+i)<= 90) // A=65 , Z = 90
        {
            *(arr+i) = *(arr+i)+32; // chữ thường + 32 = chữ hoa
        }
        printf("%c", *(arr+i));
    }
}
void floral_Print() // khai báo hàm chuyển đổi tất cả thành chữ hoa
{
    for(int i=0; i<sizeof(arr); i++)
    {
          
        if(97<=*(arr+i) && *(arr+i)<= 122)  // a = 97, z = 122;
        {
            *(arr+i) = *(arr+i)-32; // chữ thường - 32 = chữ hoa
        }
        printf("%c", *(arr+i));
    }
}


int main(int argc, char const *argv[])
{
    printf("1,Reverse string: \n");
    Inversion();
    printf("\n----------------------\n");
    printf("2,Capitalize first letter after dot: \n");
    capital_letter_after_the_dot();
    printf("\n----------------------\n");
    printf("3,Covert text to lowercase: \n");
    plain_Print();
    printf("\n-----------------------\n");
    printf("4,Covert text to uppercase: \n");
    floral_Print();
    return 0;
}
