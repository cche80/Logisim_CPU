#include <iostream>
#include <list>
#include <queue>

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

class Buffer { //implemented as FIFO queue
public:
private:
};

int main() {
	return 0;
}
