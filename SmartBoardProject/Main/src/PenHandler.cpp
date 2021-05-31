#include <Arduino.h>
#include "../include/PenHandler.hpp"

namespace drawing{
	
	PenHandler::PenHandler() {
		// put your setup code here, to run once:
		servo.attach(48);
		up();
	}

	void PenHandler::up(){
		servo.write(90);
		delay(200);
	}

	void PenHandler::penDown(){
		servo.write(0);
		delay(200);
	}

	void PenHandler::eraserDown(){
		servo.write(180);
		delay(200);
	}

}
