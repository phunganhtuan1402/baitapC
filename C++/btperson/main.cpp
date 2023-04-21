/*
* File: main.cpp
* Author: PHUNG ANH TUAN
* Date: 11/04/2023
* Description: This is file for person
*/
#include<stdio.h>
#include<stdint.h> // sử dụng uint
#include<math.h>
#include<string.h>
#include <stdarg.h> // nhiều inputparameter

using namespace std;
/*------------------class person----------------*/
class person{
    private:
      char name[50];
      uint8_t age;
      char adress[50];
    public:
      person(const char *name,uint8_t age,const char* adress);
      char *getName();
      char *getAdress();
      uint8_t  getAge();
      void information();
      uint8_t calculateAge();
};
person::person(const char *name,const uint8_t age,const char *adress){ //khai báo tường minh
    strcpy(this->adress ,adress);
    person::age = age;
    strcpy(this->name, name);
}
/*
* Class: person
* Function: getName
* Description: This function use for get name of person
* Input:
*   Dont have input parameters
* Output:
*   return: name of person
*/
char* person:: getName(){
    return name;
}
/*
* Class: person
* Function: getAge
* Description: This function use for get age of person
* Input:
*   Dont have input parameters
* Output:
*   return: age of person
*/
uint8_t person:: getAge(){
    return age;
}
/*
* Class: person
* Function: getAdress
* Description: This function use for get adress of person
* Input:
*   Dont have input parameters
* Output:
*   return: adress of person
*/
char* person::getAdress(){
    return adress;
}
/*
* Class: person
* Function: information
* Description: This function use for void information of person
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void person:: information(){
    printf("Name is: %s\n", name);
    printf("Age is: %d\n", age);
    printf("Adress is: %s\n", adress);
}
int main(int argc, char const *argv[])
{
    person ps("Viet", 23, "Hung Yen");
    ps.information();
    //ps.calculateAge();
    return 0;
}