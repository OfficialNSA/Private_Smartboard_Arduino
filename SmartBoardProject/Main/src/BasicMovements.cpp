#include "../include/BasicMovements.hpp"
#include "../include/AccelStepper.h"
#include "../include/MultiStepper.h"
#include "../include/Coordinate.hpp"

namespace drawing{
	
	BasicMovements::BasicMovements(AccelStepper xAxis, AccelStepper yAxis1, AccelStepper yAxis2){
		this -> xAxis = xAxis;
		this -> yAxis1 = yAxis1;
		this -> yAxis2 = yAxis2;
	}
	
	Coordinate BasicMovements::circle(Coordinate start, Coordinate startDirection, float rotationPercent, int size){
		
		int xDistance = size;
		int xDirection = startDirection.x;
		int yDistance = size;
		int yDirection = startDirection.y;
		
		xAxis.setSpeed(xAxis.maxSpeed() * xDirection);
		yAxis1.setSpeed(yAxis1.maxSpeed() * yDirection);
		yAxis2.setSpeed(yAxis2.maxSpeed() * yDirection);
		
		//Because nothing moves with 0 as one axis
		int xTraveled = 1;
		int yTraveled = 1;
		
		float relation = 1;
		
		while(xTraveled < xDistance || yTraveled < yDistance){
			
			if(yTraveled <= xTraveled * relation){
				
				while(!yAxis1.runSpeed());
				while(!yAxis2.runSpeed());
				
				yTraveled++;
				
			}
			
			if(xTraveled * relation <= yTraveled){
				
				xTraveled += xAxis.runSpeed();
				
			}
			
			//relation++;
			
		}
		
		return Coordinate(start.x + (xTraveled * xDirection), start.y + (yTraveled * yDirection));
		
	}
	
	Coordinate BasicMovements::line(Coordinate start, Coordinate end){
		
		int xDistance = abs(end.x - start.x);
		int xDirection = (0 < end.x - start.x) - (end.x - start.x < 0);
		int yDistance = abs(end.y - start.y);
		int yDirection = (0 < end.y - start.y) - (end.y - start.y < 0);
		
		xAxis.setSpeed(xAxis.maxSpeed() * xDirection);
		yAxis1.setSpeed(yAxis1.maxSpeed() * yDirection);
		yAxis2.setSpeed(yAxis2.maxSpeed() * yDirection);
		
		//Because nothing moves with 0 as one axis
		int xTraveled = 1;
		int yTraveled = 1;
		
		float relation = (float)yDistance / (float)xDistance;
		
		while(xTraveled < xDistance || yTraveled < yDistance){
			
			if(yTraveled <= xTraveled * relation){
				
				while(!yAxis1.runSpeed());
				while(!yAxis2.runSpeed());
				
				yTraveled ++;
				
			}
			
			if(xTraveled * relation <= yTraveled){
				
				xTraveled += xAxis.runSpeed();
				
			}
			
		}
		
		return Coordinate(start.x + (xTraveled * xDirection), start.y + (yTraveled * yDirection));
		
	}
	
}
