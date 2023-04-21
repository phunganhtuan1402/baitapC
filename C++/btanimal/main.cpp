/*
* File: main.cpp
* Author: PHUNG ANH TUAN
* Date: 11/04/2023
* Description: This is file for animal
*/
#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<stdarg.h>
#include<string.h>
#include<vector>
 using namespace std;
/*------------class Animal-----------*/
class Animal{
    private:
      char name[50];
      uint8_t age;
      uint8_t weight;
      uint8_t height;
    public:
      Animal(){}
      Animal(const char *name, const uint8_t age, const uint8_t weight, const uint8_t height );
      char* getName();
      uint8_t getAge();
      uint8_t getWeight();
      uint8_t getHeight();
      float getBMI();
      void information();
};
Animal::Animal(const char *name, const uint8_t age, const uint8_t weight, const uint8_t height){
    Animal::age = age;
    Animal::weight= weight;
    Animal::height= height;
    strcpy(this->name, name);
}

/*1
* Class: Animal
* Function: getName
* Description: This function use for get name of animal
* Input:
*   Dont have input parameters
* Output:
*   return: name of animal
*/
char* Animal:: getName(){
    return name;
}
/*
* Class: Animal
* Function: getAge
* Description: This function use for get age of animal
* Input:
*   Dont have input parameters
* Output:
*   return: age of animal
*/
uint8_t Animal:: getAge(){
    return age;
}
/*
* Class: Animal
* Function: getWeight
* Description: This function use for get weight of animal
* Input:
*   Dont have input parameters
* Output:
*   return: weight of animal
*/
uint8_t Animal:: getWeight(){
    return weight;
}
/*
* Class: Animal
* Function: getHeight
* Description: This function use for get Height of animal
* Input:
*   Dont have input parameters
* Output:
*   return: height of animal
*/
uint8_t Animal::getHeight(){
    return height;
}
/*
* Class: Animal
* Function: getBMI
* Description: This function use for get BMI of animal
* Input:
*   Dont have input parameters
* Output:
*   return: BMI of animal
*/
float Animal::getBMI(){
    return (float)((weight)/(height*height));
}
/*----------------class compare---------------*/
class compare{
    private:
    public:
      void cmpAnimalAge(int num, ...);
      void cmpAnimalWeight(int num, ...);
};
/*
* Class: Compare
* Function: cmpAnimalAge
* Description: This function use for compare age of animals
* Input:
*   num - number of animals
*   ... - Animal for compare
* Output:
*   return: None
*/
void compare::cmpAnimalAge(int num, ...){
    uint8_t max_age = 0;
    uint8_t is_have_first_animal = 0;
    Animal animal;
    va_list args;

    va_start(args, num);
    max_age = va_arg(args, Animal).getAge();
    for(int i=0; i < num - 1; i++){
        animal = va_arg(args, Animal);
        if(max_age < animal.getAge()){
            max_age = animal.getAge();
        }
    }

    va_end(args);

    va_start(args, num);
    for(int i=0; i<num; i++){
        animal = va_arg(args, Animal);
        if(max_age == animal.getAge()){
            if(is_have_first_animal == 1) printf("va ");
            printf("%s ",animal.getName());
            is_have_first_animal = 1;
        }
    }
    va_end(args);
    printf("co tuoi cao nhat\n");
}
/*
* Class: Compare
* Function: cmpAnimalWeigt
* Description: This function use for compare weight of animals
* Input:
*   num - number of animals
*   ... - Animal for compare
* Output:
*   return: None
*/
void compare::cmpAnimalWeight(int num, ...){
    uint8_t max_weight = 0;
    uint8_t is_have_first_animal = 0;
    Animal animal;
    va_list args;

    va_start(args, num);
    max_weight = va_arg(args, Animal).getWeight();
    for(int i=0; i < num - 1; i++){
        animal = va_arg(args, Animal);
        if(max_weight < animal.getWeight()){
            max_weight = animal.getWeight();
        }
    }

    va_end(args);

    va_start(args, num);
    for(int i=0; i<num; i++){
        animal = va_arg(args, Animal);
        if(max_weight == animal.getWeight()){
            if(is_have_first_animal == 1) printf("va ");
            printf("%s ",animal.getName());
            is_have_first_animal = 1;
        }
    }
    va_end(args);
    printf("co trong luong cao nhat\n");
}
int main(int argc, char const *argv[])
{
    /* code */
    Animal Meo("Meo", 2, 3, 4);
    Animal Cho("Cho", 5, 3, 4);
    Animal Voi("Voi", 5, 10, 10);
    compare cmp;
    cmp.cmpAnimalAge(3, Meo, Voi, Cho);
    cmp.cmpAnimalWeight(3, Meo, Voi, Cho);
    return 0;
}
