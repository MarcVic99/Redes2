#pragma once
#include <iostream>
#include <mutex>
#include <SFML/Network.hpp>
#include <vector>


class Chat
{
private:
	Chat() {};
	sf::IpAddress serverAddres;

	void ShowMessage(std::string);
	void ShowWarning(std::string);
	void ShowError(std::string);

	std::vector<std::string> messages;
	std::mutex messagesMutex;

	void ListenClientsConnections(unsigned short port);
public:
	static Chat* Server(unsigned short port);
	static Chat* Client(std::string ip, unsigned short port);
};

