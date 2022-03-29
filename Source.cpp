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

using namespace std;


int main() {
	ServerTcp serverTcp;

	serverTcp.initialize("127.0.0.1", 3333);
	serverTcp.attach();
	serverTcp.communicate();

	return 0;
}