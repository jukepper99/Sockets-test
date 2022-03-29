#pragma once
#include "Udp.h"
#include <iostream>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")
class ClientUdp :
    public Udp
{
    void communicate();
};

