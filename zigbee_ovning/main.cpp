#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>

#include "ZigbeeNode.h"

using std::cout;
using std::endl;
using std::uint16_t;
using std::vector;
using std::unordered_map;
using std::unordered_set;

int main() {
    ZigbeeNode coordinator(0x0000);
    ZigbeeNode router1(0x1001);
    ZigbeeNode router2(0x1002);
    ZigbeeNode router3(0x1003);
    ZigbeeNode endDevice(0x2001);

    // This is how the coordinator and router1 get connected.
    coordinator.addNeighbor(&router1);
    coordinator.addNeighbor(&router2);
    router2.addNeighbor(&router3);
    router1.addNeighbor(&endDevice);

    // Continue building the network here.

    unordered_set<uint16_t> visited;
    router2.sendRouteRequest(0x2001, visited);

    router2.printRoutingTable();
    router3.printRoutingTable();
    endDevice.printRoutingTable();

    return 0;
}

