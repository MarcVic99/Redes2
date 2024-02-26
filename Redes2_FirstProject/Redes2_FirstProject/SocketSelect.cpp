#include "SocketSelect.h"

bool SocketSelect::Wait()
{
	_mutex.lock();
	bool ready = wait();
	_mutex.unlock();

	return false;
}

bool SocketSelect::IsReady(TcpListener* listener)
{
	return false;
}

bool SocketSelect::IsReady(TcpSocket& socket)
{
	return false;
}

void SocketSelect::Add(TcpListener* listener)
{
}

void SocketSelect::Add(TcpSocket& socket)
{
}

void SocketSelect::Remove(TcpListener* listener)
{
}

void SocketSelect::Remove(TcpSocket& socket)
{
}
