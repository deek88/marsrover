/**
 * Project Mars Rover
 */


#include "rover.h"

/**
 * rover implementation
 */


/**
 * @param p
 * @param h
 */
rover::rover(point &p, heading &h) {
	this->setHeading(h);
	this->setPosition(p);
}

/**
 * @param h
 */
void rover::setHeading(heading h) {
	_heading=h;
}

/**
 * @param p
 */
void rover::setPosition(point p) {
	_position=p;
}

/**
 * @return point
 */
point rover::getPosition() {
    return _position;
}

/**
 * @return heading
 */
heading rover::getHeading() {
    return _heading;
}
