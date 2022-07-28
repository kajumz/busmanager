#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    buses_to_stops[bus] = stops;
    for (auto& stop : stops) {
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    BusesForStopResponse response;
    if (stops_to_buses.count(stop) == 0) {
        response.stream_response << "No stop" << endl;
    }
    else {
        for (const string& bus : stops_to_buses.at(stop)) {
            response.stream_response << bus << " ";
        }
        response.stream_response << endl;
    }
    return response;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    StopsForBusResponse response;
    if (buses_to_stops.count(bus) == 0) {
        response.stream_response << "No bus" << endl;
    }
    else {
        if (buses_to_stops.count(bus)) {
            for (const string& stop : buses_to_stops.at(bus)) {
                response.stream_response << "Stop " << stop << ": ";

                if (!stops_to_buses.count(stop)) continue;
                if (stops_to_buses.at(stop).size() == 1) {
                    response.stream_response << "no interchange";
                }
                else {
                    for (const string& other_bus : stops_to_buses.at(stop)) {
                        if (bus != other_bus) {
                            response.stream_response << other_bus << " ";
                        }
                    }
                }
                response.stream_response << endl;
            }
        }
    }
    return response;
}

AllBusesResponse BusManager::GetAllBuses() const {
    AllBusesResponse response;
    if (buses_to_stops.empty()) {
        response.stream_response << "No buses" << endl;
    }
    else {
        for (const auto& bus_item : buses_to_stops) {
            response.stream_response << "Bus " << bus_item.first << ": ";
            for (const string& stop : bus_item.second) {
                if (stop == *bus_item.second.begin())
                    response.stream_response << stop;
                else
                    response.stream_response << " " << stop;
            }
            response.stream_response << endl;
        }
    }
    return response;
}