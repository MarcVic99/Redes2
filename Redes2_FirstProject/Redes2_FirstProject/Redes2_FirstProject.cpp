// Redes2_FirstProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "ConsoleControl.h"
#include <SFML/Network.hpp>

void RunClient();
void RunServer();
bool CheckError(sf::Socket::Status STATUS, std::string error);
unsigned short port = 3001;


int main()
{
    sf::TcpSocket socket;
    char mode;
    do
    {
        std::cout << "Enter mode (S for Server, C for Client): ";
        mode = ConsoleControl::WaitForReadNextChar();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer del teclado

    } while (mode != 's' && mode != 'S' && mode != 'C' && mode != 'c');

    switch (mode)
    {
    case 'S':
    case 's':
        RunServer();
        break;
    case 'C':
    case 'c':
        RunClient();
        break;
    default:
        break;
    }

    while (true != false)
    {

    }
}
void RunClient() 
{
    std::cout << "Client";

    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("10.40.1.162", port);

    if (CheckError(status,"Error on connecto to Server"))
        return;

    while (true != false)
    {
        std::cout << std::endl << "Next Message: ";
        std::string message;
        std::getline(std::cin, message);

        char data[100];

        //message.copy(data, sizeof(data));

        int stringSize = std::min(static_cast<int>(message.length()), 99); // Limitar el tamaño para evitar desbordamiento del arreglo
        message.copy(data, stringSize);
        data[stringSize] = '\0';

        if (CheckError(socket.send(data,100), "Error sending message"))
            return;
    }

}
void RunServer()
{
    std::cout << "Server";

    sf::TcpListener listener;

    if (CheckError(listener.listen(port),"Error on accept client"))
        return;

    sf::IpAddress ipAdress = sf::IpAddress::getLocalAddress();
    std::cout << std::endl << "Listening to IP:" << ipAdress.toString();

    sf::TcpSocket client;

    if (CheckError(listener.accept(client),"Error on accept client"))
        return;

    std::cout << std::endl << "Client connected" << client.getRemoteAddress().toString();


    while (true != false)
    {
        char data[100];
        std::size_t received;
        std::string message;


        if (!CheckError(client.receive(data,100,received), "Error receive message"))
        {
            int stringSize = std::min(static_cast<int>(message.length()), 99); // Limitar el tamaño para evitar desbordamiento del arreglo
            message.copy(data, stringSize);
            data[stringSize] = '\0';

            std::cout << std::endl << message;
        }
    }

}
bool CheckError(sf::Socket::Status STATUS, std::string error)
{
    if (STATUS != sf::Socket::Done)
    {
        std::cout << std::endl << error;
        return true;
    }
    return false;
}
