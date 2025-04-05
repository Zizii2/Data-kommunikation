// Ethernet Frame Parser Exercise (Stub)
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdint>

// TODO: Implement this function to print a MAC address
void print_mac(const uint8_t* mac, std::string tag) {
    const int max_count = 6;
    std::cout << tag << " = ";
    for(int i=0; i<max_count; i++){
        std::cout << std::setbase(16) << std::setw(2) << std::setfill('0') << (int)mac[i];
        if(i+1 != max_count){
            std::cout << ":";
        }
    }
    std::cout << "\n";
    // Example output: ff:ff:ff:ff:ff:ff
}

// TODO: Implement this function to parse EtherType
uint16_t parse_ethertype(const uint8_t* frame) {
    return (frame[12] << 8) | frame[13];
}

int main(void) {
    // Ethernet frame hex dump
    uint8_t frame[] = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x0c, 0x29, 0x3e, 0x5b, 0xc4,
        0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x1c, 0x46, 0x40, 0x00, 0x40, 0x06,
        0xb1, 0xe6, 0xc0, 0xa8, 0x00, 0x68, 0xc0, 0xa8, 0x00, 0x01
    };

    // TODO: Print Destination MAC address
    print_mac(frame, "Dest");

    // TODO: Print Source MAC address
    print_mac(&frame[6], "Src");

    // TODO: Parse and print EtherType
    uint16_t result = parse_ethertype(frame);
    std::cout << "Ethernet type = 0x" << std::hex << std::setw(4) << std::setfill('0') << result << std::endl;

    // TODO (Optional): Print Payload

    return 0;
}