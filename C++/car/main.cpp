/*
* File: main.cpp
* Author: PHUNG ANH TUAN
* Date: 11/04/2023
* Description: This is file for car
*/
#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<stdarg.h>
#include<string.h>
#include<vector>
 using namespace std;
/*------------class Car-----------*/
class Car{
    private:
      char engine_Type[20];
      char color[20];
      uint64_t kilometer;
    public:
      Car(){};
      Car(const char* color, const char* engine_Type,const uint64_t kilometer);
      char* get_Engine_Type();
      char* get_Color();
      uint64_t get_Kilometer();
      float maintenance_Costs();
      void check_Kilometer();
      void show_Information();
};
Car::Car(const char* color, const char* engine_Type,const uint64_t kilometer){
    strcpy(Car::color , color);
    strcpy(Car::engine_Type, engine_Type);
    Car::kilometer = kilometer;
}
/*1
* Class: Car
* Function: get engine type
* Description: This function use for get engine type of car
* Input:
*   Dont have input parameters
* Output:
*   return: engine type
*/
char* Car:: get_Engine_Type(){
    return engine_Type;
}
/*1
* Class: Car
* Function: get color
* Description: This function use for get color of car
* Input:
*   Dont have input parameters
* Output:
*   return: color
*/
char* Car:: get_Color(){
    return color;
}
/*1
* Class: Car
* Function: get kilometer
* Description: This function use for get kilometer of car
* Input:
*   Dont have input parameters
* Output:
*   return: kilometer
*/
uint64_t Car:: get_Kilometer(){
    return kilometer;
}
/*1
* Class: Car
* Function: maintenance cost
* Description: This function use for maintenance cost of car
* Input:
*   Dont have input parameters
* Output:
*   return: maintenance cost of car
*/
float Car:: maintenance_Costs(){
    if(kilometer <= 5000)
    {
        return (uint64_t) 420000;
    }
    else if(kilometer < 10000){
        return (uint64_t)650000;
    }
    else if(kilometer < 20000){
        return (uint64_t)850000;
    }
    else if(kilometer >= 40000){
        return (uint64_t)2750000;
    }
    else{
        return (uint64_t)3000000;
    }
}
/*1
* Class: Car
* Function: check_kilometer
* Description: This function use for check kilmeter of car
* Input:
*   Dont have input parameters
* Output:
*   return: kilometer
*/
void Car:: check_Kilometer(){
    printf("So km da di la: %d km\n", kilometer);
}
/*
*Class: Car
*Function: check_Km 
*Describe: This is the function used to show information of car
*Input: Don't have input parameters
*Output: Don't have output
*/
void Car::show_Information()
{
    printf("Thong tin xe: \n");
    printf("Color: %s \n", color);
    printf("Type of Engine: %s \n", engine_Type);
    printf(" Km: %d \n", kilometer);
}

int main(int argc, char const *argv[])
{
    Car car("Red", "Camry", 11200);

    car.show_Information();
    car.check_Kilometer();
    printf("Chi phi bao duong xe la %.2lf$\n", car.maintenance_Costs());

    return 0;
}