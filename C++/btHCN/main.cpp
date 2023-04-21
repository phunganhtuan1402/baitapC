/*
* File: main.cpp
* Author: PHUNG ANH TUAN
* Date: 11/04/2023
* Description: This is file for rectangle
*/
#include<stdio.h>
#include<stdint.h>
#include<math.h>
/*---------------class Rectangle-------------*/
class Rectangle{
    private:
      float lenght;
      float width;
    public:
      Rectangle(float lenght = 0, float width = 0); // khi contructor mk k truyền vào thì nó hiểu là bằng 0
      float getLenght(){return Rectangle::lenght;};
      float getWidth(){return Rectangle::width;};
      float calulatePerimeter();
      float calulateArea();
      float calulateDiagonalLine();
      void checkSquare();

};
Rectangle::Rectangle(float lenght, float width){ //khai báo tường minh
    Rectangle::lenght = lenght;
    Rectangle::width = width;
}
/*
* Class: Rectangle
* Function: calulatePerimeter
* Description: This function use for float calulatePerimeter
* Input:
*   Dont have input parameters
* Output:
*   return: (float)(lenght+with)*2
*/
float Rectangle:: calulatePerimeter(){
  return (float)((lenght+width)*2);
}
/*
* Class: Rectangle
* Function: calulateArea
* Description: This function use for float calulate area
* Input:
*   Dont have input parameters
* Output:
*   return: (float)(lenght+with)
*/
float Rectangle:: calulateArea(){
  return (float)(lenght*width);
}
/*
* Class: Rectangle
* Function: calulateDiagonalLine
* Description: This function use for float calulate diagonal line
* Input:
*   Dont have input parameters
* Output:
*   return: (float)(sqrt(pow(lenght,2)+pow(width,2)))
*/
float Rectangle:: calulateDiagonalLine(){
  return (float)(sqrt(pow(lenght,2)+pow(width,2)));
}
/*
* Class: Rectangle
* Function: calulateDiagonalLine
* Description: This function use for float calulate diagonal line
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Rectangle::checkSquare(){
  if(lenght = width){
    printf("DAY LA HINH VUONG\n");
  }else{
    printf("DAY KHONG PHAI LA HINH VUON\n");
  }
}
int main(int argc, char const *argv[])
{
  Rectangle rec(3,3);
  printf("CHU VI HCN: %f\n", rec.calulatePerimeter());
  printf("DIEN TICH HCN: %f\n", rec.calulateArea());
  printf("DUONG CHEO HCN: %f\n", rec.calulateDiagonalLine());
  rec.checkSquare();
  return 0;
}
