/**
 * Project Mars Rover
 */


#ifndef _HEADING_H
#define _HEADING_H

#include <iostream>
#include <string>
class heading {
public: 
heading(){}
/**
 * @param x
 * @param y
 */
heading(double x, double y);
bool operator == (heading);
friend std::ostream& operator<<(std::ostream& os, heading h) {
    os << "(" << h.getazimuth() << ", " << h.getzenith() << ")";
    os.flush();
    return os;
}
/**
 * @param x
 */
void setazimuth(double x);
    
/**
 * @param x
 */
void setzenith(double x);
    
double getazimuth();
    
double getzenith();
private: 
    double azimuth;
    double zenith;
};

#endif //_HEADING_H
