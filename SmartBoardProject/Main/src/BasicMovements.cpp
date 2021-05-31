#include "../include/BasicMovements.hpp"
#include "../include/AccelStepper.h"
#include "../include/Coordinate.hpp"

namespace drawing{
	
	BasicMovements::BasicMovements(AccelStepper xAxis, AccelStepper yAxis){
		this -> xAxis = xAxis;
		this -> yAxis = yAxis;
	}
	
	Coordinate BasicMovements::circle(Coordinate start, Coordinate startDirection, float rotationPercent, int size){
		
	}
	
	Coordinate BasicMovements::line(Coordinate start, Coordinate end){
		
		int xDistance = abs(end.x - start.x);
		int xDirection = (0 < end.x - start.x) - (end.x - start.x < 0);
		int yDistance = abs(end.y - start.y);
		int yDirection = (0 < end.y - start.y) - (end.y - start.y < 0);
		
		xAxis.setSpeed(xAxis.maxSpeed() * xDirection);
		yAxis.setSpeed(yAxis.maxSpeed() * yDirection);
		
		//Because nothing moves with 0 as one axis
		int xTraveled = 1;
		int yTraveled = 1;
		
		float relation = (float)yDistance / (float)xDistance;
		
		while(xTraveled < xDistance || yTraveled < yDistance){
			
			if(yTraveled <= xTraveled * relation){
				
				yTraveled += yAxis.runSpeed();
				
			}
			
			if(xTraveled * relation <= yTraveled){
				
				xTraveled += xAxis.runSpeed();
				
			}
			
		}
		
		return Coordinate(start.x + (xTraveled * xDirection), start.y + (yTraveled * yDirection));
		
	}
	
}
