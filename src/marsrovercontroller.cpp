/**
 * Project Mars Rover
 */


#include "marsrovercontroller.h"
#include <cmath>
/**
 * marsrovercontroller implementation
 */


double round(double r)
{
	return (r>0.0)?floor(r+0.5):ceil(r-0.5);
}
/**
 * @param id
 * @param distance
 */
void marsrovercontroller::move(std::string id, int distance) {
    if (distance > 0) {
        double x, y, z;
        rover r = this->getrover(id);
        x = r.getPosition().getX();
        y = r.getPosition().getY();
        z = r.getPosition().getZ();
        x += sin(r.getHeading().getzenith())*cos(r.getHeading().getazimuth());
        y += sin(r.getHeading().getzenith())*sin(r.getHeading().getazimuth());
        z += cos(r.getHeading().getzenith());
        point position(round(x), round(y), round(z));
        this->checkposition(position);
        r.setPosition(position);
        rovers[id] = r;
        move(id, distance - 1);
	} else if (distance < 0) {
        throw "Rover can only move in the forward direction";
}
}

/**
 * @param id
 * @param head
 */
void marsrovercontroller::turn(std::string id, heading head) {
    if (fmod(head.getazimuth(), M_PI/2) == 0.0 && fmod(head.getzenith(), M_PI/2) == 0.0) {
        double az, z;
        rover r = this->getrover(id);
        az = r.getHeading().getazimuth();
        z = r.getHeading().getzenith();
        az += head.getazimuth();
        z += head.getzenith();
        r.setHeading(heading(az, z));
        this->rovers[id] = r;
    } else {
        throw "Rover can only turn orthognally";
}
}
