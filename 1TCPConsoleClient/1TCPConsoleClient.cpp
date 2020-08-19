// 1TCPConsoleClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "stdafx.h"
#define IP "127.0.0.1"
#define PORT 10001
int main()
{
	std::cout << "Hello Client side!\n";
	WSADATA wSADATA;
	WSAStartup(MAKEWORD(2, 2), &wSADATA);
	SOCKET wsock = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_addr.S_un.S_addr = inet_addr(IP);
	serAddr.sin_port = htons(PORT);

	int port, n, i, a, b;
	char ip[30];
	char buffer[30];

	if (wsock < 0) std::cout << "loi khoi tao socket";
	if (connect(wsock, (struct sockaddr*)&serAddr, sizeof(serAddr)) < 0)
		std::cout << "loi ket noi";
	else {
		std::cout << "ket noi thanh cong";
		while (1) {
			std::cout << "Bieu thuc can tinh";
			scanf("%d", &i);
			if (i == 0) break;
			_itoa(i, buffer, 10);
			send(wsock, buffer, sizeof(buffer), 0);
			if (i == 1 || i == 2 || i == 3) {
				std::cout << "Nhap n: ";
				scanf("%d", &n);
			}
			else if (i == 4 || i == 5 || i == 6) {
				std::cout << "Nhap a: ";
				scanf("%d", &a);
				_itoa(a, buffer, 10);
				send(wsock, buffer, sizeof(buffer), 0);

				std::cout << "Nhap b: ";
				scanf("%d", &b);
				_itoa(b, buffer, 10);
				send(wsock, buffer, sizeof(buffer), 0);

				recv(wsock, buffer, 30, 0);
				printf("Tong la: %s\n", buffer);
			}
			else if (i == 7) {
				std::cout << "Nhap n: ";
				scanf("%d", &a);
				if (a <= 0)break;

				_itoa(a, buffer, 10);
				send(wsock, buffer, sizeof(buffer), 0);
				recv(wsock, buffer, 30, 0);
				printf("Tong s2=1+2+3+...+n n(%d)=%s\n", a,buffer);

				recv(wsock, buffer, 30, 0);
				printf("Tong s2=1*2*3*...*n n(%d)=%s\n", a, buffer);

			}
		}
		closesocket(wsock);
		WSACleanup();
		return 0;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
