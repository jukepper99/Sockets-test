#pragma once
#include <iostream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

class Socket {
	private:
	protected:
		SOCKET sock;
		sockaddr_in hint;
	public:
		virtual void initialize(string ipAddress, int port) {};
		virtual void attach() {};
		virtual void communicate() {};

		void close() {
			WSACleanup();
		};

		virtual ~Socket() {};
};

