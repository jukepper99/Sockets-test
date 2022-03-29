#include "ServerTcp.h"
#include "Tcp.h"
#include <string>
#include <iostream>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

using namespace std;

void ServerTcp::attach() {
	bind(sock, (sockaddr*)&hint, sizeof(hint));
	listen(sock, SOMAXCONN);

	sockaddr_in client;
	int clientSize = sizeof(client);

	clientSocket = accept(sock, (sockaddr*)&client, &clientSize);
	if (clientSocket == INVALID_SOCKET)
	{
		cerr << "Invalid client socket" << endl;
	}

	char host[NI_MAXHOST];
	char service[NI_MAXSERV];
	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
		cout << host << "Connected on port" << service << endl;
	}
	else
	{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		cout << host << "Connected on port" << ntohs(client.sin_port) << endl;
	}

	closesocket(sock);
}

void ServerTcp::communicate() {
	char buf[4096];

	while (true)
	{
		ZeroMemory(buf, 4096);

		int bytesReceived = recv(clientSocket, buf, 4096, 0);
		if (bytesReceived == SOCKET_ERROR)
		{
			cerr << "Error ir recv" << endl;
		}

		char result[4096];
		ZeroMemory(result, 4096);
		int i, l;
		l = strlen(buf);
		for (i = 0; i < l; i++) {
			result[i] = buf[l - i - 1];
		}

		send(clientSocket, result, bytesReceived, 0);
	}

	closesocket(clientSocket);
}