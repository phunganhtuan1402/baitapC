/*
* File: main.cpp
* Author: PHUNG ANH TUAN
* Date: 11/04/2023
* Description: This is file for circle
*/
#include<stdio.h>
#include<stdint.h>
#include<math.h>

/*---------------class circle----------------*/
class circle{
    private:
      float radius;
      public:
      circle (float radius = 0);
      float getRadius(){return circle::radius;};
      float calulatePerimeter();
      float calulateArea();
};
circle::circle(float radius){ //khai báo tường minh
    circle::radius = radius;
}
/*
* Class: circle
* Function: calulatePerimeter
* Description: This function use for calulate perimeter
* Input:
*   Dont have input parameters
* Output:
*   return: float (2*3.14*radius)
*/
float circle:: calulatePerimeter(){
    return (float)(2*3.14*radius) ;
}
/*
* Class: circle
* Function: calulateArea
* Description: This function use for calulate area
* Input:
*   Dont have input parameters
* Output:
*   return: float (3.14*radius*radius)
*/
 float circle:: calulateArea(){
    return (float)(3.14*radius*radius);
 }
 int main(int argc, char const *argv[])
 {
    circle cir(3);
    printf("CHU VI HCN: %f\n", cir.calulatePerimeter());
    printf("DIEN TICH HCN: %f\n", cir.calulateArea());
    return 0;
 }
 