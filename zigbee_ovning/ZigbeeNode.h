#include "RouteEntry.h"
#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>

using std::cout;
using std::endl;
using std::uint16_t;
using std::vector;
using std::unordered_map;
using std::unordered_set;

/// @brief This is the node class, which can be either a ZC, ZR or ZED
class ZigbeeNode {
    public:
        uint16_t address;
        vector<ZigbeeNode*> neighbors;
        vector<RouteEntry> routingTable;
        unordered_map<uint16_t, ZigbeeNode*> reversePath;

        /// @brief CLass constructer
        /// @param addr the adress of the node (use hexadecimal system)
        explicit ZigbeeNode(uint16_t addr) : address(addr) {}

        /// @brief Adds the instagater node and reciver node to their respective `neighboors` vector
        /// @param neighbor The reciver node pointer that should be added to the `neighboors` vector 
        void addNeighbor(ZigbeeNode* neighbor) {
            neighbors.push_back(neighbor);
            neighbor->neighbors.push_back(this);
        }
        
        /// @brief Send a RREQ, which searches for the node with the same address as the `destination` specifes
        /// , also the start of a recurive chain with the `receiveRouteRequest` function
        /// @param destination 16-bit address that the RREQ is looking for
        /// @param visited Unordered map of all the previosly cheacked nodes in the network
        void sendRouteRequest(uint16_t destination, unordered_set<uint16_t>& visited) {
            cout << "[" << address << "] Broadcasting RREQ for destination " << destination << endl;
            visited.insert(address);
            for (size_t i = 0; i < neighbors.size(); ++i) {
                if (!visited.count(neighbors[i]->address)) {
                    neighbors[i]->receiveRouteRequest(address, destination, address, 1, visited);
                }
            }
        }
        /// @brief The recusive loop that goes through in DFS? order which started from the `sendRouteRequest` function
        /// @param source 16-bit address of the current node
        /// @param destination 16-bit address that the RREQ is looking for
        /// @param origin 16-bit address from the node that started the RREQ
        /// @param hopCount Depth of the recursion
        /// @param visited Unordered map of all the previosly cheacked nodes in the network
        void receiveRouteRequest(uint16_t source, uint16_t destination, uint16_t origin, int hopCount, unordered_set<uint16_t>& visited) {
            reversePath[origin] = findNeighborByAddress(source);
            //Base/end condition of the recursive loop
            if (address == destination) {
                cout << "[" << address << "] Destination reached. Sending RREP back to origin." << endl;
                receiveRouteReply(origin, address, hopCount);
            } else {
                visited.insert(address);
                for (size_t i = 0; i < neighbors.size(); ++i) {
                    if (!visited.count(neighbors[i]->address)) {
                        neighbors[i]->receiveRouteRequest(address, destination, origin, hopCount + 1, visited);
                    }
                }
            }
        }
        
        /// @brief Print function for when the recusive loop of `receiveRouteRequest` end
        /// @param origin 16-bit address from the node that started the RREQ
        /// @param nextHop Amount of nodes from the origin to the target
        /// @param hopCount Depth of the recursion
        void receiveRouteReply(uint16_t origin, uint16_t nextHop, int hopCount) {
            cout << "[" << address << "] Received RREP to reach " << origin << " via " << nextHop << ", hops: " << hopCount << endl;
            routingTable.push_back({origin, nextHop, hopCount});
            if (reversePath.count(origin)) {
                reversePath[origin]->receiveRouteReply(origin, address, hopCount + 1);
            }
        }
        
        /// @brief printing function for the saved routing tables on this node
        void printRoutingTable() const {
            cout << "\n[Routing Table @ Node " << address << "]" << endl;
            for (size_t i = 0; i < routingTable.size(); ++i) {
                const RouteEntry& entry = routingTable[i];
                cout << "  Destination: " << entry.destination
                     << ", NextHop: " << entry.nextHop
                     << ", Hops: " << entry.hopCount << endl;
            }
        }
    
    private:
        /// @brief Private function that looks through all neigboors to see of the given address is a match with one of them
        /// @param addr The address which might be one of the neighboors
        /// @return `ZigbeeNode` pointer of the neighboor who has the same address as `addr` OR a `nullptr`
        ZigbeeNode* findNeighborByAddress(uint16_t addr) {
            for (size_t i = 0; i < neighbors.size(); ++i) {
                if (neighbors[i]->address == addr) return neighbors[i];
            }
            return nullptr;
        }
    };