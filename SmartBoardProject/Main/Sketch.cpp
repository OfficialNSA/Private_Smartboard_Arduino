#include <Arduino.h>
#include <Servo.h>
#include "include/AccelStepper.h"
#include "include/PenHandler.hpp"
#include "include/BasicMovements.hpp"
#include "include/Coordinate.hpp"

void setup() {
	//drawing::PenHandler penHandler;
	//penHandler.penDown();
	//penHandler.up();
	AccelStepper xAxis(1, 2, 5);
	AccelStepper yAxis1(1, 3, 6);
	AccelStepper yAxis2(1, 4, 7);
	xAxis.setMaxSpeed(300);
	yAxis1.setMaxSpeed(300);
	yAxis2.setMaxSpeed(300);
	drawing::BasicMovements basicMovements(xAxis, yAxis1, yAxis2);
	drawing::Coordinate start(0,0);
	drawing::Coordinate startDirection(1,0);
	float rotationPercent = 1;
	int circlesize = 200;
	//drawing::Coordinate end(0,100);
	basicMovements.circle(start, startDirection, rotationPercent, circlesize);
	/*delay(200);
	end.x = 0;
	end.y = -100;
	basicMovements.line(start, end);
	delay(200);
	end.x = 100;
	end.y = 0;
	basicMovements.line(start, end);
	delay(200);
	end.x = 100;
	end.y = 100;
	basicMovements.line(start, end);
	delay(200);
	end.x = 100;
	end.y = -100;
	basicMovements.line(start, end);
	delay(200);
	end.x = -100;
	end.y = 0;
	basicMovements.line(start, end);
	delay(200);
	end.x = -100;
	end.y = 100;
	basicMovements.line(start, end);
	delay(200);
	end.x = -100;
	end.y = -100;
	basicMovements.line(start, end);
	delay(200);*/
	
}

void loop() {
	
}
