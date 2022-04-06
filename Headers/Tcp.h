#pragma once
#include <iostream>
#include <string>
#include <WS2tcpip.h>
#include "Socket.h"
#pragma comment(lib, "ws2_32.lib")

using namespace std;

class Tcp :
    public Socket
{
    private:
    
    public:
        void initialize(string ipAddress, int port);
};

