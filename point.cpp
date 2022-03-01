//Myesha Mahazabeen, EMPLID:24005884

#include<iostream>
#include "HM4_P1_Mahazabeen_24005884_point.h"
using namespace std;


Point :: Point(double X, double Y)
{
    this->x= X;
    this->y= Y;
}

void Point :: setX(double X)
{
    this->x= X;
}

void Point :: setY(double Y)
{
    this->y= Y;
}

double Point :: getX(){ return x; }

double Point :: getY(){ return y; }

void Point :: print() const
{
    cout<< "x,y : (" << this->x<< ","<< this->y<< ")\n";
}


