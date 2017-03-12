#ifndef Timer_hpp
#define Timer_hpp

#include <ctime>

class Timer {
	time_t start_;
	
public:
	Timer();
	
	void start();
	double currentTime();
};

#endif /* Timer_hpp */
