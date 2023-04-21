/*
* File: main.cpp
* Author: PHUNG ANH TUAN
* Date: 11/04/2023
* Description: This is file for Daymonthyear
*/
#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<stdarg.h>
#include<string.h>
#include<vector>
 using namespace std;
/*------------class Daymonthyear-----------*/
class Daymonthyear{
    private:
      uint8_t day;
      uint8_t month;
      uint16_t year;
    public:
      Daymonthyear(){};
      Daymonthyear(uint8_t day, uint8_t month, uint16_t year);
      uint8_t getDay();
      uint8_t getMonth();
      uint16_t getYear();
      void checkHoliday();
      void calculateAge(Daymonthyear today, Daymonthyear birthday);
};
Daymonthyear::Daymonthyear(uint8_t day, uint8_t month, uint16_t year){
// day
    if(day > 31 && day < 0){
        printf("Ngay khong hop le!!\n");
    }else{
         Daymonthyear::day = day;
    }
//month
    if(month > 12 && month < 0){
        printf("Thang khong hop le!!\n");
    }else{
         Daymonthyear::month = month;
    }
//year 
    if(year <= 0){
        printf("Nam khong hop le!!\n");
    }else{
         Daymonthyear::year = year;
    }
}
/*
* Class: Daymonthyear
* Function: getDay
* Description: This function use for get day of daymonthyear
* Input:
*   Dont have input parameters
* Output:
*   return: day
*/
uint8_t Daymonthyear:: getDay(){
    return day;
}
/*
* Class: Daymonthyear
* Function: getMonth
* Description: This function use for get month of daymonthyear
* Input:
*   Dont have input parameters
* Output:
*   return: month
*/
uint8_t Daymonthyear:: getMonth(){
        return month;
}
/*
* Class: Daymonthyear
* Function: getYear
* Description: This function use for get year of daymonthyear
* Input:
*   Dont have input parameters
* Output:
*   return: year
*/
uint16_t Daymonthyear:: getYear(){
    return year;
}
/*
* Class: Daymonthyear
* Function: checkHoliday
* Description: This function use for get today is holiday or not
* Input:
*   Dont have input parameters
* Output:
*   return: today is holiday or not
*/
void Daymonthyear:: checkHoliday(){
    if(day == 1 && month == 1){
        printf("Hom nay la ngay TET DUONG LICH\n");
    }
    else if(day == 14 && month == 2){
        printf("Hom nay la ngay LE TINH YEU\n");
    }
    else if(day == 8 && month == 3){
        printf("Hom nay la ngay QUOC TE PHU NU\n");
    }
    else if(day == 30 && month == 4){
        printf("Hom nay la ngay GIAI PHONG MIEN NAM, THONG NHAT DAT NUOC\n");
    }
    else if(day == 1 && month == 5){
        printf("Hom nay la ngay QUOC TE LAO DONG\n");
    }
    else if(day == 1 && month == 6){
        printf("Hom nay la ngay QUOC TE THIEU NHI\n");
    }
    else if(day == 2 && month == 9){
        printf("Hom nay la ngay LE QUOC KHANH\n");
    }
    else{
        printf("Hom nay la ngay LE TINH YEU\n");
    }
}
/*
* Class: Daymonthyear
* Function: calculage
* Description: This function use for calculate age
* Input: today, birthday
* Output:
*   return: age
*/
void Daymonthyear:: calculateAge(Daymonthyear today, Daymonthyear birthday){
    Daymonthyear age;
    if(today.year < birthday.year){
        printf("Error. Today phai lon hon birthday\n");
    }
       if(today.month <= birthday.month  && today.day < birthday.day)
    {
        age.year = today.year - birthday.year - 1;  // nếu chưa tới sinh nhật thì năm -1 
    }
    else age.year = today.year - birthday.year;     


    printf("Tuoi hien tai la: %d tuoi.\n", age.year);
}
int main(int argc, char const *argv[])
{
    Daymonthyear date;
    Daymonthyear birthday(21, 3, 2000);
    Daymonthyear today(8, 3, 2023);

    printf("--------------------\n");
    date.calculateAge(today, birthday);
    today.checkHoliday();
    return 0;
}