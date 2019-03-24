/**
 * Project Mars Rover
 */


#include "rovercontroller.h"
#include <sstream>
/**
 * rovercontroller implementation
 */



/**
 * @param id
 * @param pos
 * @param head
 */
void rovercontroller::addrover(std::string id, point &pos, heading &head) {
	checkposition(pos);
	if(rovers.find(id)==rovers.end())
	{
		rovers.insert(std::pair<std::string,rover>(id,rover(pos,head)));
	}else
	{
		throw "Rover already exits";
	}
}

/**
 * @param id
 * @return rover
 */
rover rovercontroller::getrover(std::string id) {
	std::map<std::string, rover>::iterator iter = rovers.find(id);
	if(iter == rovers.end())
		throw "Rover doesn't exist";
	return iter->second;
}

/**
 * @param pos
 */
void rovercontroller::checkposition(point pos) {
	if(!inEmpty(pos)){
		std::ostringstream p;
		p<<pos;
		throw "Rover Already occupies position" + p.str();
	}else if(!inGrid(pos))
	{
		std::ostringstream p;
		p<<pos;
		throw " position" + p.str() + "is out of grid";
	}
}

/**
 * @param pos
 * @return bool
 */
bool rovercontroller::inGrid(point pos) {
	if (((origin.getX() <= pos.getX() && pos.getX() <= vertex.getX()) ||
        (vertex.getX() <= pos.getX() && pos.getX() <= origin.getX())) &&
        ((origin.getY() <= pos.getY() && pos.getY() <= vertex.getY()) ||
        (vertex.getY() <= pos.getY() && pos.getY() <= origin.getY())) &&
        ((origin.getZ() <= pos.getZ() && pos.getZ() <= vertex.getZ()) ||
        (vertex.getZ() <= pos.getZ() && pos.getZ() <= origin.getZ()))) {
        return true;
	} else {
        return false;
}
}

/**
 * @param pos
 * @return bool
 */
bool rovercontroller::inEmpty(point &pos) {
	std::map<std::string, rover>::iterator iter;
	for(iter=rovers.begin();iter != rovers.end(); ++iter)
	{
		rover r=iter->second;
		if(r.getPosition()==pos){
			return false;
		}
	}
    return true;
}
