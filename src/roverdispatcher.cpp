/**
 * Project Mars Rover
 */


#include "roverdispatcher.h"
#include <cmath>
#include <sstream>
#include <vector>
#include <stdlib.h>
/**
 * roverdispatcher implementation
 */

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return split(s, delim, elems);
}

void roverdispatcher::dispatch() {
    std::string rover;
    std::string instruction;
    for(int j=0; j < rovers.size(); j++) {
        rover = rovers[j];
        instruction = instructions[j];
        for (int i = 0; i < instruction.size(); i++) {
            char c = instruction[i];
            if (c == 'L') {
                this->turnLeft(rover);
            } else if (c == 'R') {
                this->turnRight(rover);
            } else if (c == 'M') {
                this->move(rover);
            } else {
                throw "unknown instruction " + c;
            }
        }
    }
}
/**
 * @param head
 * @return std::string
 */
std::string roverdispatcher::mapControllerHeading(double head) {
	std::string output;
	if(fabs(head)==0.0)
		output='E';
	else if(fabs(head)==M_PI/2)
		output='N';
	else if(fabs(head)==3*M_PI/2)
		output='S';
	else if(fabs(head)==M_PI)
		output='W';
	else
		throw "Unknown Controller Handling";
    return output;
}
void roverdispatcher::parseInput(std::vector<std::string> input)
{
    parseVertex(input[0]);
    controller = marsrovercontroller(point(0, 0, 0), this->vertex);
    for (int i = 1; i < input.size(); i+=2) {
		this->parseRover(input[i]);
	}
	for (int i = 2; i < input.size(); i+=2) {
        this->parseInstruction(input[i]);
    }
}
std::string roverdispatcher::renderView(){
    std::string output;
    for(int i=0; i < rovers.size(); i++) {
        rover r = controller.getrover(rovers[i]);
        point p = r.getPosition();
        std::string h = mapControllerHeading(r.getHeading().getazimuth());
        std::ostringstream pos;
        pos << (int) p.getX() << " " << (int) p.getY() << " ";
        output += pos.str() + h + "\n";
    }
return output;
}
/**
 * @param id
 */
void roverdispatcher::turnRight(std::string id) {
	controller.turn(id, heading(-M_PI/2, 0));
}

/**
 * @param id
 */
void roverdispatcher::turnLeft(std::string id) {
	controller.turn(id, heading(M_PI/2, 0));
}

/**
 * @param id
 */
void roverdispatcher::move(std::string id) {
	controller.move(id,1);
}

/**
 * @param input
 */
void roverdispatcher::parseInstruction(std::string input) {
	instructions.push_back(input);
}

/**
 * @param input
 */
void roverdispatcher::parseRover(std::string input) {
    std::vector<std::string> rover = split(input, ' ');
    if (rover.size() == 3) {
        point position(atoi(rover[0].c_str()), atoi(rover[1].c_str()), 0);
        heading heading(mapUserHeading(rover[2]), M_PI/2);
        controller.addrover(input, position, heading);
        rovers.push_back(input);
    } else {
        throw "Incorrectly specified Rover.";
}
}

/**
 * @param input
 */
void roverdispatcher::parseVertex(std::string input) {
    std::vector<std::string> v = split(input, ' ');
    if (v.size() == 2) {
        this->vertex = point(atoi(v[0].c_str()), atoi(v[1].c_str()), 0);
    } else {
        throw "vertex must be specified int int.";
}
}

/**
 * @param head
 * @return double
 */
double roverdispatcher::mapUserHeading(std::string head) {
	double output;
	std::string c0("N");
	std::string c1("W");
	std::string c2("S");
	std::string c3("E");
	if(head.compare(c0)==0)
		output=M_PI/2;
	else if(head.compare(c3)==0)
		output=0.0;
	else if(head.compare(c1)==0)
		output=M_PI;
	else if(head.compare(c2)==0)
		output=3*M_PI/2;
	else
		throw "Unknown user heading "+head;
    return output;
}
