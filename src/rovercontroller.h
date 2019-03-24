/**
 * Project Mars Rover
 */


#ifndef _ROVERCONTROLLER_H
#define _ROVERCONTROLLER_H
#include <map>
#include "rover.h"
class rovercontroller {
public: 
	rovercontroller(){}
/**
 * @param o
 * @param v
 */
rovercontroller(point o, point v):origin(o),vertex(v){}
    
/**
 * @param id
 * @param distance
 */
virtual void move(std::string id, int distance) = 0;
    
/**
 * @param id
 * @param head
 */
virtual void turn(std::string id, heading head) = 0;
virtual ~rovercontroller(){}
    
/**
 * @param id
 * @param pos
 * @param head
 */
void addrover(std::string id, point &pos, heading &head);
    
/**
 * @param id
 */
rover getrover(std::string id);
protected: 
    std::map<std::string,rover> rovers;
    
/**
 * @param pos
 */
void checkposition(point pos);
private: 
    point origin;
    point vertex;
    
/**
 * @param pos
 */
bool inGrid(point pos);
    
/**
 * @param pos
 */
bool inEmpty(point &pos);
};

#endif //_ROVERCONTROLLER_H
