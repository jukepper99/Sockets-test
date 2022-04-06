#pragma once
#include "Socket.h"
#include "ClientTcp.h"
#include "ClientUdp.h"
#include "ServerTcp.h"
#include "ServerUdp.h"
#include "Tcp.h"
#include "Udp.h"

class Factory
{
	public: 
		Socket* create(string protocol, string service);
};

