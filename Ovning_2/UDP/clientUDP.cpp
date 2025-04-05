//client
#include <iostream>
#include <cstring>
#include <ws2tcpip.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    SOCKET sock;
    struct sockaddr_in serverAddr;
    char buffer[1024];

    // Initialize Winsock
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // Create socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0){
        std::cerr << "socket failed to create" << std::endl;
        return 1;
    }
    
    // Setup server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5000);
    serverAddr.sin_addr.s_addr = inet_addr("172.16.217.216");

    // Connect
    if (connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Connection failed: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    std::cout << "Connection made" << std::endl;
    
    while(true){
        // Send data
        // std::cout << "bout to send msg" << std::endl;
        const char* msg = "Anton";
        sendto(sock, msg, strlen(msg), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
        // std::cout << "sent msg" << std::endl;
        
        // // Receive response
        // int bytesReceived = recv(sock, buffer, 1024, 0);
        // if (bytesReceived > 0) {
        //     buffer[bytesReceived] = '\0';
        //     std::cout << "Server: " << buffer << std::endl;
        // }
        Sleep(1000);
    }
    // Cleanup
    closesocket(sock);
    WSACleanup();
    return 0;
    
    // TODO: Create TCP socket
    // TODO: Connect to server
    // TODO: Send message to server
    // TODO: Receive echo message
    // TODO: Close connection
    // return 0;
}