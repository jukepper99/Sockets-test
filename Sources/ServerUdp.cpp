#include "ServerUdp.h"
#include "Udp.h"
#include <string>
#include <iostream>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

using namespace std;

void ServerUdp::attach() {
	if (bind(sock, (sockaddr*)&hint, sizeof(hint)) == SOCKET_ERROR)
	{
		cout << "Can't bind socket! " << WSAGetLastError() << endl;
		return;
	}
}

void ServerUdp::communicate() {
	sockaddr_in client;
	int clientLength = sizeof(client);

	char buf[1024];

	while (true)
	{
		ZeroMemory(&client, clientLength); 
		ZeroMemory(buf, 1024); 

		int bytesIn = recvfrom(sock, buf, 1024, 0, (sockaddr*)&client, &clientLength);
		if (bytesIn == SOCKET_ERROR)
		{
			cout << "Error receiving from client " << WSAGetLastError() << endl;
			continue;
		}

		char clientIp[256]; 
		ZeroMemory(clientIp, 256); 
		inet_ntop(AF_INET, &client.sin_addr, clientIp, 256);
		cout << "Message recv from " << clientIp << " : " << buf << endl;

		sendto(sock, buf, 1024, 0, (sockaddr*)&client, sizeof(client));
	}

	closesocket(sock);
}