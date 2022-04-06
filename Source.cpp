#include <iostream>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

#include "Socket.h"
#include "ServerTcp.h"
#include "ServerUdp.h"
#include "ClientTcp.h"
#include "ClientUdp.h"
#include "Tcp.h"
#include "Udp.h"
#include "Factory.h"

using namespace std;


int main() {
	Factory factory;
	Socket *socket;
	
	socket = factory.create("TCP", "SERVER");

	socket->initialize("127.0.0.1", 3333);
	socket->attach();
	socket->communicate();

	return 0;
}