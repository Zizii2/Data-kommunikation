#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> // read(), write(), close()
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 
  
// Function designed for chat between client and server. 
void func(int connfd) 
{ 
    char buff[MAX]; 
    int n; 
    // infinite loop for chat 
    for (;;) { 
        bzero(buff, MAX); 
  
        // read the message from client and copy it in buffer 
        read(connfd, buff, sizeof(buff)); 
        // print buffer which contains the client contents 
        printf("From client: %s\t To client : ", buff); 
        bzero(buff, MAX); 
        n = 0; 
        // copy server message in the buffer 
        while ((buff[n++] = getchar()) != '\n') 
            ; 
  
        // and send that buffer to client 
        write(connfd, buff, sizeof(buff)); 
  
        // if msg contains "Exit" then server exit and chat ended. 
        if (strncmp("exit", buff, 4) == 0) { 
            printf("Server Exit...\n"); 
            break; 
        } 
    } 
} 
  
// Driver function 
int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        printf("server accept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server accept the client...\n"); 
  
    // Function for chatting between client and server 
    func(connfd); 
  
    // After chatting close the socket 
    close(sockfd); 
} 













// #include <iostream>
// #include <cstring>
// #include <ws2tcpip.h>
// #include <winsock2.h>

// #pragma comment(lib, "ws2_32.lib")

// #define PORT 8080
// #define BUFFER_SIZE 1024

// int main(int, char**){
//     std::cout << "Hello, from chat_room!\n";

//     WSADATA wsaData;
//     SOCKET serverSocket, clientSocket;
//     struct sockaddr_in serverAddr, clientAddr;
//     char buffer[BUFFER_SIZE];

//     // Initialize Winsock
//     if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
//         std::cerr << "WSAStartup failed.\n";
//         return 1;
//     }

//     // Create server socket
//     serverSocket = socket(AF_INET, SOCK_STREAM, 0);
//     if (serverSocket == INVALID_SOCKET) {
//         std::cerr << "Socket creation failed: " << WSAGetLastError() << std::endl;
//         WSACleanup();
//         return 1;
//     }
//     // Bind address
//     serverAddr.sin_family = AF_INET;
//     serverAddr.sin_addr.s_addr = INADDR_ANY;    
//     serverAddr.sin_port = htons(PORT);

//     if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
//         std::cerr << "Bind failed: " << WSAGetLastError() << std::endl;
//         closesocket(serverSocket);
//         WSACleanup();
//         return 1;
//     }

//     // Listen for connections
//     if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
//         std::cerr << "Listen failed: " << WSAGetLastError() << std::endl;
//         closesocket(serverSocket);
//         WSACleanup();
//         return 1;
//     }
//     while(true){
//         std::cout << "Waiting for connections on port " << PORT << "...\n";
        
//         // Accept client connection
//         int clientLen = sizeof(clientAddr);
//         clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientLen);
//         if (clientSocket == INVALID_SOCKET) {
//             std::cerr << "Accept failed: " << WSAGetLastError() << std::endl;
//             closesocket(serverSocket);
//             WSACleanup();
//             return 1;
//         }
//         break;
//     }
//     std::cout << "Client connected.\n";
//     while(true){
//         // Receive data
//         int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
//         if (bytesReceived > 0) {
//             buffer[bytesReceived] = '\0';
//             std::cout << clientSocket << ": " << buffer << std::endl;
//             if(strcmp(buffer, "END\0") == 0){
//                 break;
//             }
//             // Send response
//             const char* msg = "Hello from server!";
//             send(clientSocket, msg, strlen(msg), 0);
//         }
//     }

//     // Cleanup
//     closesocket(clientSocket);
//     closesocket(serverSocket);
//     WSACleanup();

//     return 0;
// }
