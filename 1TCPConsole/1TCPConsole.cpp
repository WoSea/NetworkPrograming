// 1TCPConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "stdafx.h"
#define MYPORT 10001

int main()
{
    std::cout << "Hello World!\n";
	WSADATA wSADATA;
	struct sockaddr_in serAddr, cliAddr;
	int cliAddrLen;

	int wSock = WSAStartup(MAKEWORD(2, 2), &wSADATA);
	if (wSock != 0) {
		std::cout << "Khong the khoi tao winsock.\n";
	}
	SOCKET wsck = socket(AF_INET, SOCK_STREAM, 0);
	serAddr.sin_family = AF_INET;
	serAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	serAddr.sin_port = htons(MYPORT);

	if(bind(wsck,(struct sockaddr*)&serAddr,sizeof(serAddr))<0)
		std::cout << "Loi binding\n";
	listen(wsck, 5);
	cliAddrLen = sizeof(cliAddr);
	SOCKET newWsck;

	char buffer[30], n1[30], a1[30], b1[30];
	int n, a, b;
	std::cout << "Dang cho client ket noi\n";

	newWsck = accept(wsck, (struct sockaddr*)&cliAddr, &cliAddrLen);
	if(newWsck<0)  std::cout << "Loi ket noi\n";
	else  std::cout << "Ket noi thanh cong\n";

	int count = 0;
	while (1) {
		recv(newWsck, buffer, sizeof(buffer), 0);
		int i = atoi(buffer);
		count += 1;
		int kq;
		if (strcmp(buffer, "1") == 0) {
			recv(newWsck, n1, sizeof(n1), 0);
			n = atoi(n1);
			kq = TinhTonga(n);
			_itoa(kq, buffer, 10);
			send(newWsck, buffer, sizeof(buffer), 0);
		}
		else if (strcmp(buffer, "2") == 0) {
			recv(newWsck, n1, sizeof(n1), 0);
			n = atoi(n1);
			kq = TinhTongb(n);
			_itoa(kq, buffer, 10);
			send(newWsck, buffer, sizeof(buffer), 0);
		}
		else if (strcmp(buffer, "3") == 0) {
			recv(newWsck, n1, sizeof(n1), 0);
			n = atoi(n1);
			kq = TinhTongc(n);
			_itoa(kq, buffer, 10);
			send(newWsck, buffer, sizeof(buffer), 0);
		}
		else if (strcmp(buffer, "4") == 0) {
			recv(newWsck, a1, sizeof(a1), 0);
			a = atoi(a1);
			recv(newWsck, b1, sizeof(b1), 0);
			b = atoi(b1);
			kq = TinhTongd(a,b);
			_itoa(kq, buffer, 10);
			send(newWsck, buffer, sizeof(buffer), 0);
		}
		else if (strcmp(buffer, "5") == 0) {
			recv(newWsck, a1, sizeof(a1), 0);
			a = atoi(a1);
			recv(newWsck, b1, sizeof(b1), 0);
			b = atoi(b1);
			kq = TinhTonge(a, b);
			_itoa(kq, buffer, 10);
			send(newWsck, buffer, sizeof(buffer), 0);
		}
		else if (strcmp(buffer, "6") == 0) {
			recv(newWsck, a1, sizeof(a1), 0);
			a = atoi(a1);
			recv(newWsck, b1, sizeof(b1), 0);
			b = atoi(b1);
			kq = TinhTongf(a, b);
			_itoa(kq, buffer, 10);
			send(newWsck, buffer, sizeof(buffer), 0);
		}
		else if (strcmp(buffer, "7") == 0) {
			recv(newWsck, n1, sizeof(n1), 0);
			a = atoi(n1);
			if (a <= 0)break;
			int kq;

			kq = TinhTongg(a);
			_itoa(kq, buffer, 10);
			send(newWsck, buffer, sizeof(buffer), 0);
			kq = TinhTongh(a);
			_itoa(kq, buffer, 10);
			send(newWsck, buffer, sizeof(buffer), 0);
		}
		else break;
		printf("\nCp %d client da duoc ket noi\n", count);
	}

	closesocket(newWsck);
	closesocket(wsck);
	std::cout << "Server da dong\n";
	WSACleanup();
	return 0;



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
