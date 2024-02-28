// Redes2_FirstProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "ConsoleControl.h"
#include <SFML/Network.hpp>
#include "Chat.h"
#include <SFML/Graphics.hpp>


void RunClient();
void RunServer();
void RunWindows();

unsigned short port = 3001;


int main()
{

    sf::TcpSocket socket;
    char mode;

    RunWindows();

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

    std::cout << std::endl << "Set server IP --> ";

    std::string ip;
    std::getline(std::cin, ip);

    Chat* chat = Chat::Client(ip, port);

}


void RunServer()
{
    std::cout << "Server";

    Chat* chat = Chat::Server(port);

}


void RunWindows()
{
    sf::RenderWindow windows;
    windows.create(sf::VideoMode(800, 600), "Chat");

    sf::Text label;

    sf::Font font;
    font.loadFromFile("Minecraft.ttf");

    label.setFont(font);
    label.setCharacterSize(16);
    label.setFillColor(sf::Color::White);
    label.setString("Hello World");
    label.setPosition(0, 0);

    while (windows.isOpen())
    {
        windows.clear(sf::Color::Black);
        windows.draw(label);
        windows.display();
    }
}