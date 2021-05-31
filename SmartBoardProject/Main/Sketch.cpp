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
	AccelStepper yAxis(1, 3, 6);
	xAxis.setMaxSpeed(300);
	yAxis.setMaxSpeed(300);
	//AccelStepper zAxis(1, 4, 7);
	drawing::BasicMovements basicMovements(xAxis, yAxis);
	drawing::Coordinate start(0,0);
	drawing::Coordinate end(0,100);
	basicMovements.line(start, end);
	delay(200);
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
	delay(200);
	
}

void loop() {
	
}
