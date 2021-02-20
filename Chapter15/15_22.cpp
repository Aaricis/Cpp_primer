#include<iostream>
#include<math.h>
using namespace std;

class Figure{
public:
    Figure()=default;
    Figure(double x, double y):xSize(x), ySize(y){}
    virtual ~Figure()=default;
protected:
    double xSize, ySize;
};

class Figure2D : public Figure{
public:
    Figure2D(double x, double y):Figure(x, y){}
    virtual double area() = 0;
    virtual double perimeter() = 0;
};


class Ranctangular: public Figure2D{
public:
    Ranctangular(double x, double y):Figure2D(x, y){}
    ~Ranctangular()=default;
    double area() override{
        return xSize*ySize;
    }

    double perimeter() override{
        return 2*(xSize+ySize);
    }
};

