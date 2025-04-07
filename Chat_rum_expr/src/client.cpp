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
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        std::cerr << "socket failed to create" << std::endl;
        return 1;
    }
    
    // Setup server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect
    if (connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Connection failed: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }
    
    while(true){
        // Send data
        char* msg;
        msg = "lol";
        std::cout << "Write a msg: ";
        std::cin >> msg;
        send(sock, msg, strlen(msg), 0);
        if(strcmp(msg, "END\0") == 0){
            break;
        }
        // Receive response
        int bytesReceived = recv(sock, buffer, 1024, 0);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0';
            std::cout << "Server: " << buffer << std::endl;
        }
    }
    // Cleanup
    closesocket(sock);
    WSACleanup();
    return 0;
}