
#include "Timer.hpp"

Timer::Timer(){
	start_ = 0;
}

void Timer::start(){
	// Store the start time
	time(&start_);
}

double Timer::currentTime(){
	// Retrieve the current time
	time_t now;
	time(&now);
	
	return difftime(now, start_);
}

