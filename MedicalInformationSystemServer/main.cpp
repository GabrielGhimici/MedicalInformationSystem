#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <iostream>
#include <vector>
#include <process.h>
#pragma comment(lib,"ws2_32.lib" )

#include "Tokenizer.h"

unsigned int __stdcall  ServClient(void *data);

enum InternalMessages {UNDEFINED_MESSAGE, LOGIN_MESSAGE};

inline std::string ToString(InternalMessages v)
{
	switch (v)
	{
	case LOGIN_MESSAGE:   
		return "LOGIN";
	default:      
		return "[UM]";
	}
}

inline InternalMessages FromString(std::string str)
{
	if (str == "LOGIN") return LOGIN_MESSAGE;
	return UNDEFINED_MESSAGE;
}

int main(int argc, char* argv[])
{

	WSADATA wsaData;
	int iResult;
	sockaddr_in address;
	SOCKET sock, client;

	address.sin_family = AF_INET;
	address.sin_port = htons(2222);
	address.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iResult)
	{
		printf("WSA startup failed");
		return 0;
	}
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		printf("Invalid socket");
		return 0;
	}
	iResult = bind(sock, (sockaddr*)&address, sizeof(sockaddr_in));
	if (iResult)
	{
		printf("Bind failed %u", GetLastError());
		return 0;
	}
	iResult = listen(sock, SOMAXCONN);
	if (iResult)
	{
		printf("iResult failed %u", GetLastError());
		return 0;
	}

	std::cout << "Server started!" << std::endl;
	std::cout << "Listenind on: 127.0.0.1:2222" << std::endl;

	while (client = accept(sock, 0, 0))
	{
		if (client == INVALID_SOCKET)
		{
			printf("Invalid client socket", GetLastError());
			continue;
		}
		_beginthreadex(0, 0, ServClient, (void*)&client, 0, 0);
	}
	return 0;
}

unsigned int __stdcall ServClient(void *data)
{
	SOCKET* client = (SOCKET*)data;
	SOCKET Client = *client;
	printf("Client connected %d\n", GetCurrentThreadId());
	char chunk[5000];
	while (recv(Client, chunk, 5000, 0))
	{
		std::string message(chunk);
		std::vector<std::string> messageTokens = MedicalInformationSystemServer::Tokenizer::tokenize(message, '>');
		switch (FromString(messageTokens[0]))
		{
		case UNDEFINED_MESSAGE:
			std::cout << chunk << std::endl;
			break;
		case LOGIN_MESSAGE:
			std::cout << ">>> Login as " << messageTokens[1].c_str() << std::endl;
			char logingResponse[5000];
			if (GetCurrentProcessId() % 6 == 0) {
				sprintf(logingResponse, "OK.......");
				send(Client, logingResponse, 5000, 0);
			}
			else {
				sprintf(logingResponse, "NOT OK.......");
				send(Client, logingResponse, 5000, 0);
			}
			break;
		default:
			break;
		}
	}
	return 0;
}