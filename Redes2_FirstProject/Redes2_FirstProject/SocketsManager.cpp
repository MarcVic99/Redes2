#include "SocketsManager.h"

SocketsManager::SocketsManager(OnSocketConnected onSocketConnected)
{
}

SocketsManager::~SocketsManager()
{
	delete _listener;
	for (TcpSocket* socket : _sockets)
	{
		delete socket;
	}
}

void SocketsManager::StartLoop()
{
	_isRunningMutex.lock();

	if (_isRunning)
	{
		_isRunningMutex.unlock();
		return;
	}

	_isRunning = true;
	_isRunningMutex.unlock();

	std::thread* loopThread = new std::thread(&SocketsManager::SelectorLoop, this);
	loopThread->detach();
}

bool SocketsManager::StartListener(unsigned short port)
{
	return false;
}

bool SocketsManager::ConnectToServer(std::string ip, unsigned short port)
{
	return false;
}

void SocketsManager::SelectorLoop()
{
	_isRunningMutex.lock();
	bool isRunning = true;
	_isRunningMutex.unlock();


	while (isRunning)
	{
		if (_selector.Wait())
		{
			//TODO
		}

		_isRunningMutex.lock();
		 isRunning = false;
		_isRunningMutex.unlock();

	}

}

void SocketsManager::CheckListener()
{
}

void SocketsManager::CheckSockets()
{
}

void SocketsManager::AddSocket(TcpSocket* socket)
{
}

void SocketsManager::RemoveSocket(TcpSocket* socket)
{
}

void SocketsManager::RemoveSocketAsync(TcpSocket* socket)
{
}
