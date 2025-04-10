#pragma once
#include <cstdint>

using std::uint16_t;

/// @brief A struct to save paths taken through the zigbee network
struct RouteEntry {
    uint16_t destination;
    uint16_t nextHop;
    int hopCount;
};