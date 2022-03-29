#pragma once
#include "Tcp.h"
#include <iostream>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")
class ClientTcp :
    public Tcp
{
public:
    void attach();
    void communicate();
};

