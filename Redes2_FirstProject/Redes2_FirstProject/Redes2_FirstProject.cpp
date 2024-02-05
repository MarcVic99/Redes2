// Redes2_FirstProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <SFML/Network.hpp>


int main()
{
    std::cout << "Hello mundooooo soy gay!\n";
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("192.168.0.5", 53000);
    if (status != sf::Socket::Done)
    {
        // error...
    }
}
