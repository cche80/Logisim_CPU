#include <iostream>
#include <list>
#include <queue>
#include <math.h>	// for log function
#include <cstdlib>	// for drand48 ??
#include <random>	// for exponential_distribution class
#include <limits>	// for infinite int in MAXBUFFER

using namespace std;

class Event {
public:
	Event* getNextEvent(void) { return nextEvent; }

	Event* getPreEvent(void) { return preEvent; }

	bool getType(void) { return type; }

	void setType(bool inputType) { type = inputType; }

	double getEventTime(void) { return eventTime; }

	void setEventTime(double inputTime) { eventTime = inputTime; }

private:
	Event* nextEvent;
	Event* preEvent;
	bool type; // 1 for arrival event, 0 for departure event.
	double eventTime;
};

class GEL {
public:
	GEL(void){}
	GEL(Event inputEvent) {} //INCOMPLETE

	void insert(Event &inputEvent) {
		list<Event>::iterator itr;

		for (itr = gel.begin(); itr != gel.end(); itr++) {
			if (inputEvent.getEventTime() <= itr->getEventTime()) { break; }
		}

		gel.insert(itr, inputEvent); // this handles the case of empty gel
	}

	void removeFirst() { //remove first element
		if (!gel.empty())
			gel.pop_front();
	}
private:
	list<Event> gel; //Global Event List 
};

class Packet {
public:
private:
	double length;
};

class Buffer { //implemented as FIFO queue
public:
	Buffer() {}
	void insertPacket(Packet inputPacket) { //pushes to end of queue
		buffer.push(inputPacket);
	}
	void removePacket(){ //just pops off the first element from queue
		buffer.pop();
	}
private:
	queue<Packet> buffer;

};

// I used another C++ library <random>
/*
double negative_exponentially_distributed_time(double rate) { //Function taken from Project Document
	double u;
	u = drand48(); //drand48 returns a double in the range of [0.0, 1.0)
	return ((-1 / rate)*log(1 - u));
}
*/

int main() {

	// Initialization
	// Setting u and lambda and MAXBUFFER
	double lbd = 0.1;
	double u = 1;
	int MAXBUFFER = numeric_limits<int>::max();

	// The following codes are to generate a set of numbers with exp dist
	default_random_engine generator;
	exponential_distribution<double> exp_dist_for_arrival(lbd);
	exponential_distribution<double> exp_dist_for_departure(u);

	// test that the generator actually works
	for (int i = 0; i < 1000; i++) {
		cout << exp_dist_for_arrival(generator) << endl;
	}

	getchar();

	double time = 0;
	int length = 0; //number of packets in buffer's queue



	GEL eventList();
	Buffer buffer();

	//Set service and arrival rate of the packets

	return 0;
}
