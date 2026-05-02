#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>

const int BUF_SIZE = 1024;

int main(void) {
    // init sys socket

    // create socket w socket()
    int clientSocket = socket(AF_INET, SOCK_STREAM, PF_INET);

    // bind socket w bind()
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // request connection to server w connect()
    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    // send and receive data from client w recv(), send(), recvfrom(), sendto()
    const std::string message = "Hello, server!\n";
    send(clientSocket, message.c_str(), message.length(), 0);

    // receive response from server
    //std::vector<char> buffer[BUF_SIZE];
    //recv(clientSocket, buffer.data(), buffer.size(), 0);
    //std::cout << "SERVER RESPONSE: " << buffer << std::endl;

    // close socket w closesocket()
    close(clientSocket);
    
    return 0;
}