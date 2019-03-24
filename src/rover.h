/**
 * Project Mars Rover
 */


#ifndef _ROVER_H
#define _ROVER_H
#include "point.h"
#include "heading.h"
class rover {
public: 
	rover(){}
/**
 * @param p
 * @param h
 */
rover(point &p, heading &h);
    
/**
 * @param h
 */
void setHeading(heading h);
    
/**
 * @param p
 */
void setPosition(point p);
    
point getPosition();
    
heading getHeading();
private: 
    point _position;
    heading _heading;
};

#endif //_ROVER_H
