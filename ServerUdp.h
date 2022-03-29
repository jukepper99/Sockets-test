#pragma once
#include "Udp.h"
#include <iostream>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")
class ServerUdp :
    public Udp
{
    private:
    
    public:
        void attach();
        void communicate();
};

