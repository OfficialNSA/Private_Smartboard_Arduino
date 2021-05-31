#ifndef BASEFIGURES_HPP
#define BASEFIGURES_HPP

#include "AccelStepper.h"
#include "Coordinate.hpp"

namespace drawing{
	
	class BasicMovements{
		
		public:
		BasicMovements(AccelStepper xAxis, AccelStepper yAxis);
		Coordinate circle(Coordinate start, Coordinate startDirection, float rotationPercent, int size);
		Coordinate line(Coordinate start, Coordinate end);
		
		private:
		AccelStepper xAxis;
		AccelStepper yAxis;
		
	};

}

#endif
