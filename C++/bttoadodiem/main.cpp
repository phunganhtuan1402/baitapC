/*
* File: main.cpp
* Author: PHUNG ANH TUAN
* Date: 11/04/2023
* Description: This is file for point coordinates
*/
#include<stdio.h>
#include<stdint.h>
#include<math.h>
/*---------------class point-----------------*/
class Point{
    private:
      int8_t ordinate;
      int8_t abscissa;
    public:
      Point(int8_t ordinate = 0, int8_t abscissa = 0); // khi contructor mk k truyền vào thì nó hiểu là bằng 0
      int8_t getOrdinate(){return Point::ordinate;};
      int8_t getAbscissa(){return Point::abscissa;};
};
Point::Point(int8_t ordinate, int8_t abscissa){ //khai báo tường minh
    Point::ordinate = ordinate;
    Point::abscissa = abscissa;
}
/*-----------------class spaceMath------------*/
class SpaceMath{
    private:
      Point firstCoordinate; //tọa độ
      Point secondCoordinate;
      Point thirdCoordinate;
      enum{
        DISTANCE,
        AREA_OF_TRIANGLE
      }Math;
    public:
      SpaceMath(Point firstCoordinate,Point secondCoordinate);
      SpaceMath(Point firstCoordinate,Point secondCoordinate,Point thirdCoordinate);
      Point getFirstPoint();
      Point getSecondPoint();
      Point getThirdPoint();
      double calculateDistance(); //tính khoảng cách
      double calculateAreaOfTriangle(); //tính diện tích
};
SpaceMath::SpaceMath(Point firstCoordinate,Point secondCoordinate){
    Math = DISTANCE;
    SpaceMath::firstCoordinate = firstCoordinate;
    SpaceMath::secondCoordinate = secondCoordinate;
}
SpaceMath::SpaceMath(Point firstCoordinate,Point secondCoordinate,Point thirdCoordinate){
  Math = AREA_OF_TRIANGLE;
  SpaceMath::firstCoordinate = firstCoordinate;
  SpaceMath::secondCoordinate = secondCoordinate;
  SpaceMath::thirdCoordinate = thirdCoordinate;
}
double SpaceMath::calculateAreaOfTriangle(){
  if(Math != AREA_OF_TRIANGLE){
       printf("KHONG PHAI LA TAM GIAC\n");
        return -1;
    }else{
    double distance_a = sqrt(pow(firstCoordinate.getOrdinate() - secondCoordinate.getOrdinate(),2) + pow(firstCoordinate.getAbscissa() - secondCoordinate.getAbscissa(),2));
    double distance_b = sqrt(pow(firstCoordinate.getOrdinate() - thirdCoordinate.getOrdinate(),2) + pow(firstCoordinate.getAbscissa() - thirdCoordinate.getAbscissa(),2));
    double distance_c = sqrt(pow(thirdCoordinate.getOrdinate() - secondCoordinate.getOrdinate(),2) + pow(thirdCoordinate.getAbscissa() - secondCoordinate.getAbscissa(),2));
    double p = (distance_a + distance_b + distance_c) / 2;
    return (double)(sqrt(p*(p - distance_a)*(p - distance_b)*(p - distance_c)));
    }
}
double SpaceMath::calculateDistance(){
    if(Math != DISTANCE){
        printf("DU LIEU NHAP VAO KHONG PHU HOP\n");
        return -1;
    }else{
      return  (double)(sqrt(pow(firstCoordinate.getOrdinate() - secondCoordinate.getOrdinate(),2) \
    + pow(firstCoordinate.getAbscissa() - secondCoordinate.getAbscissa(),2)));
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    Point point1(2, 4);
    Point point2(2, 3);
    Point point3(5, 6);

    SpaceMath space1(point1 , point2);
    SpaceMath space2(point1, point2, point3);

    //-------------Space 1--------------//
    //printf("POINT 1(%d,%d)\n", space1.getFirstPoint().getOrdinate(), space1.getFirstPoint().getAbscissa());
    //printf("POINT 2(%d,%d)\n", space1.getSecondPoint().getOrdinate(), space1.getSecondPoint().getAbscissa());
    printf("DISTANCE: %.2lf\n\n", space1.calculateDistance());

    //-------------Space 2--------------//
    //printf("POINT 1(%d,%d)\n", space2.getFirstPoint().getOrdinate(), space2.getFirstPoint().getAbscissa());
    //printf("POINT 2(%d,%d)\n", space2.getSecondPoint().getOrdinate(), space2.getSecondPoint().getAbscissa());
    printf("AREA OF TRIANGLE: %d\n\n", space2.calculateAreaOfTriangle());

    return 0;
}
