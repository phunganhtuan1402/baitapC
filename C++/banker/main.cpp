/*
* File: main.cpp
* Author: PHUNG ANH TUAN
* Date: 11/04/2023
* Description: This is file for bank
*/
#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<stdarg.h>
#include<string.h>
#include<vector>
 using namespace std;
/*------------class Bank-----------*/
class Bank{
    private:
      uint64_t accountNumberID;
      char accountName[50];
      uint64_t surplus;
    public:
      Bank(){};
      Bank(const uint64_t accountNumberID, const char* accountName,const uint64_t surplus);
      uint64_t getAccountNumberID();
      char*  getAccountName();
      uint64_t getSurplus();
      void withdrawMoney();
      void depositMoney();
      void checkSurplus();
};
Bank::Bank(const uint64_t accountNumberID, const  char* accountName,const uint64_t surplus){
    Bank::accountNumberID = accountNumberID;
    Bank::surplus = surplus;
    strcpy(Bank::accountName, accountName);
}
/*1
* Class: Bank
* Function: getAccountNumber
* Description: This function use for get account number of bank
* Input:
*   Dont have input parameters
* Output:
*   return: accuontNumberID of bank
*/
uint64_t Bank:: getAccountNumberID(){
  return accountNumberID;
}
/*1
* Class: Bank
* Function: getAccountName
* Description: This function use for get account name of bank
* Input:
*   Dont have input parameters
* Output:
*   return: accountName of bank
*/
char* Bank:: getAccountName(){
  return accountName;
}
/*1
* Class: Bank
* Function: withdrawMoney
* Description: This function to withdraw money from the bank account
* Input:
*   money - an integer value
* Output:
*   return:money
*/
void Bank::withdrawMoney(){
  uint64_t money;
    printf("Nhap so tien can rut: ");
    scanf("%d", &money);
    if(surplus ==0 )
    {
        printf("So du khong du de rut.\n");
    }
    else
    {
        Bank::surplus = surplus - money;
        printf(" Ban da rut thanh cong %d$ ra khoi tai khoan.\n", money);
        
    }
}
/*1
* Class: Bank
* Function: depositMoney
* Description: This function to withdraw money from the bank account
* Input:
*   money - an integer value
* Output:
*   return:money
*/
void Bank::depositMoney(){
  uint64_t money;
    printf("Nhap so tien can nap: ");
    scanf("%d", &money);
    Bank::surplus = surplus + money;
    printf(" Ban da nap thanh cong %d$ vao tai khoan.\n", money);
}
/*1
* Class: Bank
* Function: checkSurplus
* Description: This function to check surplus from the bank account
* Input:
*   none
* Output:
*   none
*/
void Bank:: checkSurplus(){
     printf("So du hien tai la: %d\n", surplus);
}

int main(int argc, char const *argv[])
{
    Bank bnk_ac( 9999,"Agrri bank", 1000);
    int i=0;
    do
    {
        
        printf("----Welcome to your bank account----: \n");
        printf("1, Rut tien.\n");
        printf("2, Nap tien.\n");
        printf("3, Kiem tra so du.\n");
        printf("4, Thoat.\n");
        printf("=>Chon giao dich ban muon thuc hien: ");
        scanf("%d",&i);
        switch (i)
        {
        case 1:
            bnk_ac.withdrawMoney();
            break;
        case 2:
            bnk_ac.depositMoney();
             break;
        case 3:
            bnk_ac.checkSurplus();
            break;
        case 4:
            printf("Ket thuc giao dich.\n");
            return 0;
        default:
            printf("Hay lua chon dung yeu cau.\n");
            break;
        }

        
    } while (1);
    

    return 0;
}
