#include "Chat.h"
#include <iostream>
#include <thread>
#include "ConsoleControl.h"

void Chat::ShowMessage(std::string message)
{
	_messageMutex.lock();
	_messages.push_back(message);
	_messageMutex.unlock();

	ConsoleControl::LockMutex();
	std::cout << std::endl << message;
	ConsoleControl::UnlockMutex();
}

void Chat::ShowWarning(std::string message)
{
	ConsoleControl::LockMutex();
	ConsoleControl::SetColor(ConsoleControl::YELLOW);
	std::cout << std::endl << message;
	ConsoleControl::SetColor(ConsoleControl::WHITE);
	ConsoleControl::UnlockMutex();
}

void Chat::ShowError(std::string message)
{
	ConsoleControl::LockMutex();
	ConsoleControl::SetColor(ConsoleControl::RED);
	std::cout << std::endl << message;
	ConsoleControl::SetColor(ConsoleControl::WHITE);
	ConsoleControl::UnlockMutex();
}

void Chat::ListenClientsConnections(unsigned short port)
{


}

Chat* Chat::Server(unsigned short port)
{
	Chat* chat = new Chat();
	chat->_serverAddress = sf::IpAddress::getLocalAddress();




	return chat;
}

Chat* Chat::Client(std::string ip, unsigned short port)
{
	Chat* chat = new Chat();
	chat->_serverAddress = sf::IpAddress::getLocalAddress();

	return chat;
}

