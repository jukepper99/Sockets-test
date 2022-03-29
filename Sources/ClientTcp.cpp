#include "ClientTcp.h"
#include "Tcp.h"
#include <string>
#include <iostream>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

void ClientTcp::attach() {
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		cerr << "Can't connect to server, Err #" << WSAGetLastError() << endl;
		closesocket(sock);
		WSACleanup();
	}
}


void ClientTcp::communicate() {
	char buf[4096];
	string userInput;

	do
	{
		cout << "> ";
		getline(cin, userInput);

		if (userInput.size() > 0)
		{
			int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
			if (sendResult != SOCKET_ERROR)
			{
				ZeroMemory(buf, 4096);
				int bytesReceived = recv(sock, buf, 4096, 0);
				if (bytesReceived > 0)
				{
					cout << "SERVER> " << string(buf, 0, bytesReceived) << endl;
				}
			}
		}
	} while (userInput.size() > 0);

	closesocket(sock);
}