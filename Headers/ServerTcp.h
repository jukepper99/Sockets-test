#pragma once
#include "Tcp.h"
#include <iostream>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")
class ServerTcp :
    public Tcp
{
    private:
        SOCKET clientSocket;
    public:
        void attach();
        void communicate();
};

