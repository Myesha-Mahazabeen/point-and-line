//Myesha Mahazabeen

#include<iostream>
#include<math.h>
#include "line.h"
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;

Line :: Line()
{
    slope= 0;
    length= 0;

    p1= new Point(0, 0);
    p2= new Point(0, 0);
}

Line :: Line(double x1, double y1, double x2, double y2)
{
    p1= new Point(x1, y1);
    p2= new Point(x2, y2);

    double x_sq= (x1-x2)*(x1-x2);
    double y_sq= (y1-y2)*(y1-y2);

    length= sqrt(x_sq + y_sq);
    slope=(x2-x1)? (y2-y1)/(x2-x1) : INF;   //checking if x2-x1==0, in that case, slope=INF
}

Line :: Line(const Line& obj)
{
    this->p1= new Point(obj.p1->getX(), obj.p1->getY());
    this->p2= new Point(obj.p2->getX(), obj.p2->getY());
    
    this->slope= obj.slope;
    this->length= obj.length;
}

Line :: ~Line()
{
    delete p1;
    delete p2;
}

Line& Line :: operator=(const Line& obj)
{
    if(this == &obj) return *this;
    
    delete this->p1;
    delete this->p2;

    this->p1= new Point(obj.p1->getX(), obj.p1->getY());
    this->p2= new Point(obj.p2->getX(), obj.p2->getY());

    this->slope= obj.slope;
    this->length= obj.length;

    return *this;
}

double Line :: getLength(){ return this->length; }

double Line :: getSlope(){ return this->slope; }

Point* Line :: getP1() { return this->p1; }

Point* Line :: getP2() { return this->p2; }

void Line :: setP1(double X, double Y)
{
    this->p1->setX(X);
    this->p1->setY(Y);
}

void Line :: setP2(double X, double Y)
{
    this->p2->setX(X);
    this->p2->setY(Y);
}

void Line :: setLength()
{
    double x_sq= (p1->getX()-p2->getX());       //x_sq= x2-x1
    x_sq*=x_sq;                                 //x_sq= (x2-x1)*(x2-x2)
    double y_sq= (p1->getY()-p2->getY());       //y_sq= y2-y1
    y_sq*=y_sq;                                 //y_sq= (y2-y1)*(y2-y1)

    this->length= sqrt(x_sq+y_sq);
}

void Line :: setSlope()
{
    double x= (p1->getX()-p2->getX());
    double y= (p1->getY()-p2->getY());

    this->slope= x? y/x : INF;
}

bool Line :: parallel(Line l1, Line l2)
{
    return l1.getSlope()==l2.getSlope();
}

bool Line :: operator<(Line& obj)
{
    return this->getLength()<obj.getLength();
}

bool Line :: operator>(Line& obj)
{
    return this->getLength()>obj.getLength();
}

bool Line :: operator==(Line& obj)
{
    return this->getLength()==obj.getLength();
}

ostream &operator<<(ostream &output, const Line &L)
{
    // cout
    output<< "Point 1: ("<< L.p1->getX()<< " , "<< L.p1->getY()<< ")\n";
    output<< "Point 2: ("<< L.p2->getX()<< " , "<< L.p2->getY()<< ")\n";
    output<< "Length: "<< L.length<< endl;
    output<< "Slope: "<< L.slope<< endl;

    return output;
}

istream &operator>>(istream &input, Line &L)
{
    string in, p1, p2;
    double x1, y1, x2, y2;
    cout<<"Enter input in given manner: [(x1,y1),(x2,y2)]\n";
    input>> in;
    
    //parsing
    x1= stod(in.substr(2, in.find(",")));                       // value of x1 starts from index 2 and finsihes before first ','
    y1= stod(in.substr(in.find(",")+1, in.find("),(")));        // value of y1 starts after first ',' and finishes before "),("
    p1= in.substr(in.find("),(")+3);                            //p1= "x2,y2)]"
    x2= stod(p1.substr(0, p1.find(",")));                       //value of x2 starts at 0th index of p1 and finishes before ','
    y2= stod(p1.substr(p1.find(",")+1, p1.find(")]")));         //value of y2 starts after ',' and finishes before ")]"
    // cout<<x1<< '\t'<< y1<< '\t'<< x2<< '\t'<< y2<< endl;
    if(input.fail()==0)
        L= Line(x1, y1, x2, y2);
        
    return input;
}

vector<Line> processLines()
{
    vector<Line> lines;
    
    ifstream f1;
    string in;


    f1.open("lines.txt");

    if(!f1.is_open())
    {
        cout<< "could not open lines.txt\n";
        return lines;
    }

    while(!f1.eof())
    {
        f1>>in;
        if(in.length()<7) continue;

        int col= in.find(":");
        string p1= in.substr(col+2);        //p1= "x1,y1],[x2,y2]],"
        int cl_br= p1.find("]");        
        string p2= p1.substr(cl_br+3);      //p2= "x2,y2]],"
        p1= p1.substr(0, cl_br);            //p1= "x1,y1"
        p2= p2.substr(0, p2.find("]"));     //p2= "x2, y2"

        double x1= stod(p1.substr(0, p1.find(",")));    //value of x1 starts from index 0, ends before ',' in string p1
        double y1= stod(p1.substr(p1.find(",")+1));     //value of y1 starts after ',' and finishes at end in string p1
        double x2= stod(p2.substr(0, p2.find(",")));    //value of x2 starts from index 0, ends before ',' in string p2
        double y2= stod(p2.substr(p2.find(",")+1));     //value of y2 starts after ',' and finishes at end in string p2

        lines.push_back(Line(x1, y1, x2, y2));
    }
    f1.close();
    return lines;
}
