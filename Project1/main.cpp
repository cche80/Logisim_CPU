#include <iostream>

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

private:
	Event* nextEvent;
	Event* preEvent;
	bool type; // 1 for arrival event, 0 for departure event.
};

int main() {
	cout << "testing" << endl;
	cout << "push" << endl;
	return 0;
}