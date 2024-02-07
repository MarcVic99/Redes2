// Redes2_FirstProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <conio.h>
#include <iostream>
#include <SFML/Network.hpp>

void RunClient();
void RunServer();

int main()
{

    std::cout << "Select"<<std::endl<< "Client -> C " << std::endl << "Server -> S" << std::endl;

    char mode = ' ';

    do
    {
        if (_kbhit())
        {
            mode = _getch();
        }
    } while (mode != 'C' && mode != 'c' && mode != 'S' && mode != 's');

    switch (mode)
    {
    case 'c':
    case 'C':

        RunClient();

        break;
    case 's':
    case 'S':

        RunServer();

        break;
    default:
        break;
    }

    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("192.168.0.5", 53000);
    if (status != sf::Socket::Done)
    {
        // error...
    }
}

void RunClient()
{

}

void RunServer()
{
    std::cout << "Server";

    sf::TcpListener listener;

}
