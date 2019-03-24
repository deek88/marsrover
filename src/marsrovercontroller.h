/**
 * Project Mars Rover
 */


#ifndef _MARSROVERCONTROLLER_H
#define _MARSROVERCONTROLLER_H

#include "rovercontroller.h"


class marsrovercontroller: public rovercontroller {
public:
	marsrovercontroller() {}
	marsrovercontroller(const point &origin, const point &vertex)
: rovercontroller(origin, vertex) {}
    
/**
 * @param id
 * @param distance
 */
void move(std::string id, int distance);
    
/**
 * @param id
 * @param head
 */
void turn(std::string id, heading head);
};

#endif //_MARSROVERCONTROLLER_H
