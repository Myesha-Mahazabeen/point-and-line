//Myesha Mahazabeen, EMPLID: 24005884

#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
#include<assert.h>

#include "line.h"

using namespace std;

int main()
{
    // GETTER-SETTER TESTING
    cout<< "Testing all get/set functions:\n\n";
    Line tmp;
    tmp.setP1(1, 1);
    tmp.setP2(2, 2);
    if(tmp.getP1()->getX()!=1 && tmp.getP1()->getY()!=1)
        cout<< "FAILED get/setP1: p1(1,1)\n";
    else 
        cout<< "get/setP1 passed: p1(1,1)\n";
    if(tmp.getP2()->getX()!=2 && tmp.getP2()->getY()!=1)
        cout<< "FAILED get/setP2: p2(2,2)\n";
    else
        cout<< "get/setP2 passed: p2(2,2)\n";
    tmp.setLength();
    if(tmp.getLength()!=sqrt(2))
        cout<< "FAILED get/setLength: p1(1,1), p2(2,2)\n";
    else
        cout<< "get/setLength passed: p1(1,1), p2(2,2), Length: "<< tmp.getLength()<< endl;
    tmp.setSlope();
    if(tmp.getSlope()!=1)
        cout<< "FAILED get/setSlope: p1(1,1), p2(2,2)\n";
    else
        cout<< "get/setSlope passed: p1(1,1), p2(2,2), Slope: "<< tmp.getSlope()<< endl;
    cout<< endl;

    tmp.setP1(-1, 0);
    tmp.setP2(1, -1);
    if(tmp.getP1()->getX()!=-1 && tmp.getP1()->getY()!=0)
        cout<< "FAILED get/setP1: p1(-1,0)\n";
    else
        cout<< "get/setP1 passed: p1(-1,0)\n";
    if(tmp.getP2()->getX()!=1 && tmp.getP2()->getY()!=-1)
        cout<< "FAILED get/setP2: p2(1,-1)\n";
    else
        cout<< "get/setP2 passed: p2(1,-1)\n";
    tmp.setLength();
    if(tmp.getLength()!=sqrt(5))
        cout<< "FAILED get/setLength: p1(-1,0), p2(1,-1)\n";
    else
        cout<< "get/setLength passed: p1(-1,0), p2(1,-1), Length: "<< tmp.getLength()<< endl;
    tmp.setSlope();
    if(tmp.getSlope()!=-0.5)
        cout<< "FAILED get/setSlope: p1(-1,0), p2(1,-1)\n";
    else
        cout<< "get/setSlope passed: p1(-1,0), p2(1,-1), Slope: "<< tmp.getSlope()<< endl;
    cout<< endl;

    tmp.setP1(-1, 0);
    tmp.setP2(-1, 1);
    if(tmp.getP1()->getX()!=-1 && tmp.getP1()->getY()!=0)
        cout<< "FAILED get/setP1: p1(-1,0)\n";
    else
        cout<< "get/setP1 passed: p1(-1,0)\n";
    if(tmp.getP2()->getX()!=-1 && tmp.getP2()->getY()!=1)
        cout<< "FAILED get/setP2: p2(-1,1)\n";
    else
        cout<< "get/setP2 passed: p2(-1,1)\n";
    tmp.setLength();
    if(tmp.getLength()!=1)
        cout<< "FAILED get/setLength: p1(-1,0), p2(-1,1)\n";
    else
        cout<< "get/setLength passed: p1(-1,0), p2(-1,1), Length: "<< tmp.getLength()<< endl;
    tmp.setSlope();
    if(tmp.getSlope()!=INF)
        cout<< "FAILED get/setSlope: p1(-1,0), p2(-1,1)\n";
    else
        cout<< "get/setSlope passed: p1(-1,0), p2(1,-1), Slope: "<< "INF"<< endl;
    cout<< endl;
    cout<< endl;



    // NULL CONSTRUCTOR TESTING
    
    Line tmpn;
    cout<< "Null Construtor Testing:\n";
    if(tmpn.getP1()->getX()!=0 || tmpn.getP1()->getY()!=0 || tmpn.getP2()->getX()!=0 || tmpn.getP2()->getY()!=0 ||tmpn.getLength()!=0 || tmpn.getSlope()!=0)
        cout<< "FAILED Null Constructor\n";
    else
        cout<< "Null Constructur passed, created object: tmpn(0, 0, 0, 0)\n";
    cout<< endl;
    // OVERLOADED CONSTRUCTOR TESTING
    Line tmp0= Line(1, 1.2, 3.1, 7);
    cout<< "Overloaded Constructor Testing:\n";
    if(tmp0.getP1()->getX()!=1 || tmp0.getP1()->getY()!=1.2 || tmp0.getP2()->getX()!=3.1 || tmp0.getP2()->getY()!=7 )
        cout<< "FAILED overloaded Constructor\n";
    else
        cout<< "Overloaded Constructur passed, created object: tmp0(1, 1.2, 3.1, 7)\n";
    cout<< endl;



    // COPY CONSTRUCTOR TESTING
    Line tmp1= Line(1, 1.2, 3.1, 7);
    Line tmp2= tmp1;
    cout<< "Copy Constructor Testing:\n";
    if(tmp2.getP1()->getX()!=1 || tmp2.getP1()->getY()!=1.2 || tmp2.getP2()->getX()!=3.1 || tmp2.getP2()->getY()!=7)
        cout<< "FAILED Copy Constructor\n";
    else
        cout<< "Copy Constructur passed, created object: tmp2(1, 1.2, 3.1, 7)\n";
    cout<< endl;



    // COPY ASSIGNMENT OPERATOR TESTING
    Line tmp3= Line(1, 1.2, 3.1, 7);
    Line tmp4;
    tmp4= tmp3;
    cout<< "Copy assignment operator Testing:\n";
    if(tmp4.getP1()->getX()!=1 || tmp4.getP1()->getY()!=1.2 || tmp4.getP2()->getX()!=3.1 || tmp4.getP2()->getY()!=7)
        cout<< "FAILED Copy assignment\n";
    else
        cout<< "Copy assignment passed ,object: tmp4(1, 1.2, 3.1, 7)\n";
    cout<< endl;



    // PARALLEL FUNCTION TESTING
    cout<< "Testing parallel function:\n\n";
    Line l1= Line(1, 1, 5, 6);
    Line l2= Line(3, 3, 15, 18);
    if(Line::parallel(l1, l2)==0)
        cout<< "FAILED parallel function: l1((1,1),(5,6)) and l2((3,3),(15,18))\n";
    else
        cout<< "Passed parallel function: l1((1,1),(5,6)) and l2((3,3),(15,18)) are parallel\n";


    l1= Line(3, 1, 5, 6);
    l2= Line(1, 3, 2, 4);
    if(Line::parallel(l1, l2)==1)
        cout<< "FAILED parallel function: l1((3,1),(5,6)) and l2((1,3),(2,4))\n";
    else
        cout<< "Passed parallel function: l1((3,1),(5,6)) and l2((1,3),(2,4)) are not parallel\n";

    l1= Line(2, 3, 2, 7);
    l2= Line(9, 3, 9, 1);
    if(Line::parallel(l1, l2)==0)
        cout<< "FAILED parallel function: l1((2,3),(2,7)) and l2((9,3),(9,1))\n";
    else
        cout<< "Passed parallel function: l1((2,3),(2,7)) and l2((9,3),(9,1)) are parallel\n";




    // OVERLOADED OPERATOR TESTING
    cout<< "Testing overloaded == < > operators:\n\n";
    l1= Line(3, 1, 3, 6);
    l2= Line(-1, 5, 2, 1);
    if(l1==l2 && !(l1<l2) && !(l1>l2))
        cout<<"==, <, > operator passed: l1(3,1,3,6), length=5 == l2(-1,5,2,1), length=5\n";
    else
    {
        cout<<"FAILED overloaded ";
        if(!(l1==l2)) cout<< "== ";
        if(l1<l2) cout<<"< ";
        if(l1>l2) cout<< "> ";
        cout<<"operator l1(3,1,3,6) and l2(-1,5,2,1)\n";
    }

    l1= Line(2, 1, 2, 2);
    l2= Line(2, 2, 4, 2);
    if(l1<l2 && !(l1==l2) && !(l1>l2))
        cout<<"==, <, > operator passed: l1(2,1,2,2), length=1 < l2(2,2,4,2), length=1.41\n";
    else
    {
        cout<<"FAILED overloaded ";
        if(l1==l2) cout<< "== ";
        if(!(l1<l2)) cout<<"< ";
        if(l1>l2) cout<< "> ";
        cout<<"operator l1(2,1,2,2) and l2(2,2,4,2)\n";
    }

    l1= Line(3, 1, 0, -3);
    l2= Line(0, 0, -1, 0);
    if(l1>l2 && !(l1==l2) && !(l1<l2))
        cout<<"==, <, > operator passed: l1(3,1,0,-3), length=5 > l2(0,0,-1,0), length=1\n";
    else
    {
        cout<<"FAILED overloaded ";
        if(l1==l2) cout<< "== ";
        if(l1<l2) cout<<"< ";
        if(!(l1>l2)) cout<< "> ";
        cout<<"operator l1(3,1,0,-3) and l2(0,0,-1,0)\n";
    }
    cout<< endl;


    // PROCESSLINES TESTING
    cout<< "Testing processLines, inputs taken from lines.txt:\n";
    vector<Line> lines= processLines();
    for(int i=0; i<lines.size(); i++)
    {
        cout<< "line "<<i
            << ": p1("<< lines[i].getP1()->getX()<<","<< lines[i].getP1()->getY()<<"), "
            << "p2("<< lines[i].getP2()->getX()<<","<< lines[i].getP2()->getY()<<"), "
            << "length="<< lines[i].getLength()<< ", "
            << "slope= "<< lines[i].getSlope()<< endl;
    }
    cout<< endl;

    cout<< "Sorting lines vector:\n";
    sort(lines.begin(), lines.end());
    for(int i=0; i<lines.size(); i++)
    {
        cout<< "line "<<i
            << ": p1("<< lines[i].getP1()->getX()<<","<< lines[i].getP1()->getY()<<"), "
            << "p2("<< lines[i].getP2()->getX()<<","<< lines[i].getP2()->getY()<<"), "
            << "length="<< lines[i].getLength()<< ", "
            << "slope= "<< lines[i].getSlope()<< endl;
    }
    cout<< endl;


    // CIN, COUT FOR LINES TESTING
    Line in;
    cin>> in;
    cout<< in;
}

