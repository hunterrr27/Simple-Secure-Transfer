#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

const int BUF_SIZE = 1024;

int main(void) {
    // init sys socket

    // create socket w socket()
    int serverSocket = socket(AF_INET, SOCK_STREAM, PF_INET);

    // bind socket w bind()
    sockaddr_in serverAddress;  // data type used to store address of socket
    serverAddress.sin_family = AF_INET; 
    serverAddress.sin_port = htons(8080);   //converts machine byte order to network byte order
    serverAddress.sin_addr.s_addr = INADDR_ANY; // listens to any available IP for incoming connections
    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    // listen for connection w listen()
    listen(serverSocket, 5);

    // accept connection w accept() and connect()
    int clientSocket = accept(serverSocket, nullptr, nullptr);

    // send and receive data from client w recv(), send(), recvfrom(), sendto()
    std::vector<char> buffer[BUF_SIZE];
    recv(clientSocket, (void *)buffer, sizeof(buffer), 0);
    std::cout << "MESSAGE FROM CLIENT: " << buffer << std::endl;

    // close socket w close()
    close(serverSocket);

    return 0;
}