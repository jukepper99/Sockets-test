#include "ClientUdp.h"
#include "Udp.h"
#include <string>
#include <iostream>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

using namespace std;

void ClientUdp::communicate() {
	char buf[1024];
	string userInput;
	ZeroMemory(buf, 1024);

	do {
		cout << ">";
		getline(cin, userInput);

		if (userInput.size() > 0) {
			int sendOk = sendto(sock, userInput.c_str(), 1024, 0, (sockaddr*)&hint, sizeof(hint));

			if (sendOk == SOCKET_ERROR)
			{
				cout << "That didn't work! " << WSAGetLastError() << endl;
			}

			ZeroMemory(buf, 1024);
			int bytesReceived = recv(sock, buf, 1024, 0);
			if (bytesReceived > 0)
			{
				cout << "SERVER> " << string(buf, 0, bytesReceived) << endl;
			}
		}

	} while (userInput.size() > 0);

	closesocket(sock);
}
