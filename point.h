//Myesha Mahazabeen

#include<iostream>

#ifndef POINT_H
#define POINT_H

using namespace std;

class Point
{
    private:
        double x;
        double y;

    public:
        void setX(double X);
        void setY(double Y);
        double  getX();
        double getY();
        Point(double X=0, double Y=0);
        void print() const;
};

#endif
