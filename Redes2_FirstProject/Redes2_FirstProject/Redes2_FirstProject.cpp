// Redes2_FirstProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <conio.h>
#include <iostream>
#include <SFML/Network.hpp>
#include "ConsoleControl.h"

unsigned short port = 3000;

void RunClient();
void RunServer();

int main()
{

    std::cout << "Select"<<std::endl<< "Client -> C " << std::endl << "Server -> S" << std::endl;
    while (true)
    {
    char mode = ' ';

    do
    {

            mode = ConsoleControl::WaitForReadNextChar();
        
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



    }

}

void RunClient()
{
    std::cout << "Client";

    //sf::TcpSocket socket;
    //sf::Socket::Status status = socket.connect("10.40.2.49", port);

    //if (status != sf::Socket::Done) {
    //    std::cout << std::endl << "Error on connect to server";
    //    return;
    //}

    //while (true)
    //{



    //    std::cout << std::endl << "Next message: ";
    //    std::string message;
    //    std::getline(std::cin, message);
    //    char data[100];
    //    int stringSize = message.length();
    //    for (int i = 0; i < stringSize; i++)
    //    {
    //        char c = message[i];
    //        data[i] = c;

    //    }

    //    if (socket.send(data, 100) != sf::Socket::Done)
    //    {
    //        std::cout << std::endl << "Error on sending message";

    //    }
    //}


}

void RunServer()
{
    std::cout << "Server";

  /*  sf::TcpListener listener;
    
    if (listener.listen(3000) != sf::Socket::Done)
    {
        std::cout << std::endl << "Error on start listener";
        return;
    }

    sf::IpAddress ipAddress = sf::IpAddress::getLocalAddress();
    std::cout << std::endl << "Listening on IP: " +ipAddress.toString();

    sf::TcpSocket client;

    if (listener.accept(client) != sf::Socket::Done)
    {
        std::cout << std::endl << "Error on accept Client";
        return;
    }

    std::cout << std::endl << "Client Connected";


    while (true)
    {

        char data[100];
        std::size_t received;

        std::string message;

        if (client.receive(data, 100, received) != sf::Socket::Done)
        {
            std::cout << std::endl << "Error ";

        }
        else
        {
            for (size_t i = 0; i < received; i++)
            {
                char c = data[i];
                message += c;


            }
            std::cout << std::endl << message;

        }


    }*/

}
