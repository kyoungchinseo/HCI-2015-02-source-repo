// socket_win.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

//////////////////////////////////////////////////////////////////////////
// SET PORT NUMBER !!
//////////////////////////////////////////////////////////////////////////
#define LISTEN_PORT 8001
#define BUF_LEN 1024

void ErrorHandling(char* message);

int main(int argc, char* argv[])
{
	int count = 0;

	WSADATA	wsaData;
	SOCKET hServSock, hClntSock;		
	SOCKADDR_IN servAddr, clntAddr;		
	int szClntAddr;
	
	if(WSAStartup(MAKEWORD(2, 2), &wsaData)!=0)
		ErrorHandling("WSAStartup() error!"); 
	
	hServSock=socket(PF_INET, SOCK_STREAM, 0);
	if(hServSock==INVALID_SOCKET)
		ErrorHandling("socket() error");
  
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family=AF_INET;
	servAddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servAddr.sin_port=htons(LISTEN_PORT);
	
	if(bind(hServSock, (SOCKADDR*) &servAddr, sizeof(servAddr))==SOCKET_ERROR)
		ErrorHandling("bind() error");
	
	if(listen(hServSock, 5)==SOCKET_ERROR)
		ErrorHandling("listen() error");

	szClntAddr=sizeof(clntAddr);    	
	hClntSock=accept(hServSock, (SOCKADDR*)&clntAddr,&szClntAddr);
	if(hClntSock==INVALID_SOCKET)
		ErrorHandling("accept() error");  

	char buf[BUF_LEN] = "";
	while(1)
	{
		int recv_len;
		while(1)
		{
			recv_len = recv(hClntSock, buf, BUF_LEN, 0);
			if( recv_len == -1 || recv_len == 0 )
				continue;
			for (int i = 0; i < recv_len; ++i)
			{
				printf("[%d]%c\n", i, buf[i]);

				// IF RECIEVED VALUE IS '1'
				if(buf[i]=='1')
				{
					char send_buf[2];
					// SEND RESPONSE (0/1)
					count++;
					send_buf[0] = count%2 + '0';
					send_buf[1] = '\0';
					send(hClntSock, send_buf, sizeof(send_buf), 0);
					printf("sending : %s\n", send_buf);
				}
			}
			printf("for end\n");
		}
	}
	
	closesocket(hClntSock);
	closesocket(hServSock);
	WSACleanup();
	return 0;
}

void ErrorHandling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
