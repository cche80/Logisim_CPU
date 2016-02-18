#include <iostream>
#include <list>

using namespace std;

class Event {
public:
	Event* getNextEvent(void) {
		return nextEvent;
	}

	Event* getPreEvent(void) {
		return preEvent;
	}

	bool getType(void) {
		return type;
	}

	void setType(bool inputType) {
		type = inputType;
	}

	double getEventTime(void) {
		return eventTime;
	}

	void setEventTime(double inputTime) {
		eventTime = inputTime;
	}

private:
	Event* nextEvent;
	Event* preEvent;
	bool type; // 1 for arrival event, 0 for departure event.
	double eventTime;
};

class GEL {
public:
	GEL(void){}
	GEL(Event inputEvent) {

	}

	void insert(Event inputEvent) {
		int counter = 0;

		for (list<Event>::iterator itr = gel.begin(); itr != gel.end(); itr++) {
			if (inputEvent.getEventTime() <= itr->getEventTime()) { break; }
			counter++;
		}
		
		gel.insert(inputEvent,counter); // it handles the case of empty gel
	}
private:
	list<Event> gel;
};


int main() {
	return 0;
}