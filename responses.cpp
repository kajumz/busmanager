#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	auto b = r.stream_response.str();
	os << r.stream_response.str();
	return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	auto b = r.stream_response.str();
	os << r.stream_response.str();
	return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	auto b = r.stream_response.str();
	os << r.stream_response.str();
	return os;
}