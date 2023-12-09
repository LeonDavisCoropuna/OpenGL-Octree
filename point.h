#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point() {
        x=0.0;
        y=0.0;
        z=0.0;
    }

    Point(double a,double b, double c){
        x=a;
        y=b;
        z=c;
    }

    Point(double a,double b){
        x=a;
        y=b;
        z=0.0;
    }

    double x,y,z;

};

#endif // POINT_H
