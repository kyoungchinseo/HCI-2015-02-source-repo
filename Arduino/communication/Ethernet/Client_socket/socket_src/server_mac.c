#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

//////////////////////////////////////////////////////////////////////////
// SET PORT NUMBER !!
//////////////////////////////////////////////////////////////////////////
#define LISTEN_PORT 8001
#define BUF_LEN 1024

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int count = 0;

	int serv_sock;
	int clnt_sock;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;
	
	serv_sock=socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1)
		error_handling("socket() error");
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(LISTEN_PORT);
	
	if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1 )
		error_handling("bind() error"); 
	
	if(listen(serv_sock, 5)==-1)
		error_handling("listen() error");
	
	clnt_addr_size=sizeof(clnt_addr);  
	clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr,&clnt_addr_size);
	if(clnt_sock==-1)
		error_handling("accept() error");  

	char buf[BUF_LEN] = "";
	while(1)
	{
		int recv_len;
		while(1)
		{
			recv_len = read(clnt_sock, buf, BUF_LEN-1);
			printf("recv : %d\n", recv_len);
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
					write(clnt_sock, send_buf, sizeof(send_buf));
					printf("sending : %s\n", send_buf);
				}
				printf("for end\n");
			}
		}
	}
	
	close(clnt_sock);	
	close(serv_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
