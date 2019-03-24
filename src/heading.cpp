/**
 * Project Mars Rover
 */


#include "heading.h"
#include <cmath>

/**
 * heading implementation
 */


/**
 * @param x
 * @param y
 */
heading::heading(double x, double y) {
	this->setazimuth(x);
	this->setzenith(y);

}
bool heading::operator== (heading h)  {
    if (this->getazimuth() == h.getazimuth() &&
        this->getzenith() == h.getzenith()) {
        return true;
    } else {
        return false;
    }
}
/**
 * @param x
 */
void heading::setazimuth(double x) {
	azimuth=fmod(x,(2*M_PI));
}

/**
 * @param x
 */
void heading::setzenith(double x) {
	zenith=fmod(x,(2*M_PI));

}

/**
 * @return double
 */
double heading::getazimuth() {

    return azimuth;
}

/**
 * @return double
 */
double heading::getzenith() {
    return zenith;
}
