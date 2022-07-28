#pragma once

#include <string>
#include <vector>
#include <map>
#include "responses.h"

// Да, я знаю что так делать нельзя. Но это для экономии времени.
using namespace std;

class BusManager {
public:

	void AddBus(const string& bus, const vector<string>& stops);

	BusesForStopResponse GetBusesForStop(const string& stop) const;
	StopsForBusResponse GetStopsForBus(const string& bus) const;
	AllBusesResponse GetAllBuses() const;

private:
	map<string, vector<string>> buses_to_stops, stops_to_buses;
};
