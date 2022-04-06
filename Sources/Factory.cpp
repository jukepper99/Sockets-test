#include "Factory.h"
#include "Socket.h"
#include "ClientTcp.h"
#include "ClientUdp.h"
#include "ServerTcp.h"
#include "ServerUdp.h"
#include "Tcp.h"
#include "Udp.h"

Socket* Factory::create(string protocol, string service)
{
	if (protocol != "TCP" && protocol != "UDP") {
		cerr << "Protocol type must be \"TCP\" or \"UDP\"" << endl;
		return nullptr;
	}

	if (service != "CLIENT" && service != "SERVER") {
		cerr << "Service type must be \"CLIENT\" or \"SERVER\"" << endl;
		return nullptr;
	}

	if (protocol == "TCP" && service == "SERVER") {
		return new ServerTcp;
	}else if (protocol == "TCP" && service == "CLIENT") {
		return new ClientTcp;
	}else if (protocol == "UDP" && service == "SERVER") {
		return new ServerUdp;
	}else {
		return new ClientUdp;
	}
}
