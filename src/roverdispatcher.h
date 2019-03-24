/**
 * Project Mars Rover
 */


#ifndef _ROVERDISPATCHER_H
#define _ROVERDISPATCHER_H

#include "marsrovercontroller.h"
#include <vector>
class roverdispatcher {
public:
	roverdispatcher(){}
	void dispatch();
	void parseInput(std::vector<std::string> input);
	std::string renderView();
/**
 * @param head
 */
std::string mapControllerHeading(double head);
    
/**
 * @param id
 */
void turnRight(std::string id);
    
/**
 * @param id
 */
void turnLeft(std::string id);
    
/**
 * @param id
 */
void move(std::string id);
    
/**
 * @param input
 */
void parseInstruction(std::string input);
    
/**
 * @param input
 */
void parseRover(std::string input);
    
/**
 * @param input
 */
void parseVertex(std::string input);
    
/**
 * @param head
 */
double mapUserHeading(std::string head);

private: 
    marsrovercontroller controller;
    std::vector<std::string> rovers;
    std::vector<std::string> instructions;
    point vertex;
};

#endif //_ROVERDISPATCHER_H
