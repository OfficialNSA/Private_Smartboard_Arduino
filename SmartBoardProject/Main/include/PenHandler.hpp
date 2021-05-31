#ifndef PENHANDLER_HPP
#define PENHANDLER_HPP

#include <Servo.h>

namespace drawing{
	class PenHandler{
		
		public:
			PenHandler();
			void up();
			void penDown();
			void eraserDown();		
			
		private:
			Servo servo;
				
	};

}

#endif