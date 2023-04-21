#include<stdio.h>
#include<stdint.h>
#include<math.h>

class fraction{
    private:
      int8_t numerator;
      int8_t denominator;
    public:
      fraction(int8_t numerator = 0, int8_t denominator = 0); // khi contructor mk k truyền vào thì nó hiểu là bằng 0
      int8_t getNumerator(){return fraction::numerator;};
      int8_t getDenominator(){return fraction::denominator;};
};
fraction::fraction(int8_t numerator, int8_t denominator){ //khai báo tường minh
    if(denominator == 0){
        printf("KHOI TAO SAI MAU SO\n");
        return;
    }
    fraction::numerator = numerator;
    fraction::denominator = denominator;
}
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