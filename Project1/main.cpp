#include <iostream>
#include <list>
#include <queue>
#include <math.h> //for log function
#include <cstdlib> //for drand48 ??

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

double negative_exponentially_distributed_time(double rate) { //Function taken from Project Document
	double u;
	u = drand48(); //drand48 returns a double in the range of [0.0, 1.0)
	return ((-1 / rate)*log(1 - u));
}

int main() {

	//Initialization
	double time = 0;
	int length = 0; //number of packets in buffer's queue

	GEL eventList();
	Buffer buffer();

	//Set service and arrival rate of the packets

	return 0;
}
