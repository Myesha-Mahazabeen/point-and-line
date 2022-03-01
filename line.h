//Myesha Mahazabeen, EMPLID:24005884

#include<iostream>
#include<vector>
#include "point.h"

#define INF 99999
#ifndef LINE_H
#define LINE_H

using namespace std;

class Line
{
    private:
        Point* p1;
        Point* p2;
        double slope, length;
    
    public:
        void setP1(double x, double y);
        void setP2(double x, double y);
        Point* getP1();
        Point* getP2();
        void setLength();
        void setSlope();
        double getSlope();
        double getLength();

        Line& operator=(const Line& obj);

        Line();
        Line(double x1, double y1, double x2, double y2);
        
    // Line(Point P1, Point P2);
        
        Line(const Line& obj);
        ~Line();
        static bool parallel(Line l1, Line l2);
        bool operator<(Line& obj);
        bool operator>(Line& obj);
        bool operator==(Line& obj);
        friend ostream &operator<<(ostream &output, const Line &L);
        friend istream &operator>>(istream &input, Line &L);
        
};

//function that reads lines from the file lines.txt and stores the values.

vector<Line> processLines();

#endif
