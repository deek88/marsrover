/**
 * Project Mars Rover
 */


#include "point.h"

/**
 * point implementation
 */


/**
 * @param x
 * @param y
 * @param z
 */
point::point(double x, double y, double z) {
	this->x=x;
	this->y=y;
	this->z=z;
}

bool point::operator== (point p)  {
    if (this->getX() == p.getX() &&
        this->getY() == p.getY() &&
        this->getZ() == p.getZ()) {
        return true;
    } else {
        return false;
    }
}
/**
 * @return double
 */
double point::getX() {
    return x;
}

/**
 * @param X
 */
void point::setX(double X) {
	x=X;
}

/**
 * @return double
 */
double point::getY() {
    return y;
}

/**
 * @param Y
 */
void point::setY(double Y) {
	y=Y;
}

/**
 * @return double
 */
double point::getZ() {
    return z;
}

/**
 * @param Z
 */
void point::setZ(double Z) {
	z=Z;
}
