/**
 * Project Mars Rover
 */


#ifndef _POINT_H
#define _POINT_H
#include <iostream>
#include <string>
class point {
public: 
	point() {};
/**
 * @param x
 * @param y
 * @param z
 */
point(double x, double y, double z);
bool operator == (point);
friend std::ostream& operator<<(std::ostream& os, point p) {
    os << "(" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")";
    os.flush();
    return os;
}
double getX();
    
/**
 * @param X
 */
void setX(double X);
    
double getY();
    
/**
 * @param Y
 */
void setY(double Y);
    
double getZ();
    
/**
 * @param Z
 */
void setZ(double Z);
private: 
    double x;
    double y;
    double z;
};

#endif //_POINT_H
