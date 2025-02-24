#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <vector>
#include <thread>

#pragma comment(lib, "ws2_32.lib")

void handle_client(SOCKET client_socket, std::vector<SOCKET>& clients)
{
    char buffer[1024] = {0};
    int valread;

    while (true) {
        memset(buffer, 0, sizeof(buffer)); // Clear the buffer
        valread = recv(client_socket, buffer, 1024, 0);
        if (valread == SOCKET_ERROR || valread == 0) {
            std::cout << "Client disconnected" << std::endl;
            closesocket(client_socket);
            break;
        }

        std::cout << "Received: " << buffer << std::endl;

        // Send the message to all other clients
        for (SOCKET sock : clients) {
            if (sock != client_socket) {
                send(sock, buffer, valread, 0);
            }
        }
    }
}

int main()
{
    WSADATA wsaData;
    int iResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }

    SOCKET server_fd = INVALID_SOCKET;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET) {
        std::cerr << "Socket creation error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt)) == SOCKET_ERROR) {
        std::cerr << "setsockopt failed: " << WSAGetLastError() << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        std::cerr << "bind failed: " << WSAGetLastError() << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }
    if (listen(server_fd, 3) == SOCKET_ERROR) {
        std::cerr << "listen failed: " << WSAGetLastError() << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    std::vector<SOCKET> clients;
    while (true) {
        SOCKET new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);
        if (new_socket == INVALID_SOCKET) {
            std::cerr << "accept failed: " << WSAGetLastError() << std::endl;
            continue;
        }
        clients.push_back(new_socket);
        std::thread(handle_client, new_socket, std::ref(clients)).detach();
    }

    closesocket(server_fd);
    WSACleanup();
    return 0;
}
