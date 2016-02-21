#include <iostream>
#include <list>
#include <queue>
#include <math.h> //for log function
#include <cstdlib> //for drand48 in linux

// Part of 3.2
// Declare some variables as global
const int MAXBUFFER = 4;

//Set service (mu) and arrival (lambda) rate of the packets
const double ARRIVALRATE = 0.1;
const double SERVICERATE = 0.1;

double globalTime = 0;		// Global time
int bufferLength = 0;		// Number of packets in buffer's queue (includeing the one being transmitted)
int packetsDropped = 0;		// Count of total packets droppedeventList


using namespace std;

///////////////////// Packet Class //////////////////////////
class Packet {
public:
	Packet(double inputTime) { packetServiceTime = inputTime; }

	void setPacketServiceTime(double inputTime) { packetServiceTime = inputTime; }
	double getPacketServiceTime() { return packetServiceTime; }
private:
//	double packetLength;
	double packetServiceTime; //the service time for EACH individual packet, theoretically based on the different packet lengths
};


///////////////////// Buffer Class //////////////////////////
class Buffer { //implemented as FIFO queue
public:
	Buffer(int inputMaxBuffer) { maxBuffer = inputMaxBuffer; }

	bool insertPacket(Packet& inputPacket) {	// pushes to end of queue
											// return 0 (fail) if the packet has to be dropped
		if (buffer.size() >= maxBuffer) { return 0; }

		else {
			buffer.push(inputPacket);
			cout << "Service time right after pushing: " << buffer.front().getPacketServiceTime() << endl;
			return 1;
		}
	}

	Packet accessPacket() {
		buffer.front();
	}

	void removePacket() { //just pops off the first element from queue
		buffer.pop();
	}

	int getBufferSize() { return buffer.size(); }
private:
	queue<Packet> buffer;
	int maxBuffer;
};


int main() {

	Buffer buffer(MAXBUFFER);

	Packet newPacket(0.25);

	buffer.insertPacket(newPacket);
	cout << "Service Time when retrieving from the queue: " << buffer.accessPacket().getPacketServiceTime() << endl;
}
