#include <stdio.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include <unistd.h>

#define REQUEST_LIMIT 				1048576 // 1Mb
#define PORT						80
#define HEAD_REQ_PART_1				"GET /"
#define HEAD_REQ_PART_2				" HTTP/1.1\r\nHost: "
#define HEAD_REQ_PART_3 			"\r\n\r\n"

struct sockaddr_in serv_addr; 

int sock;

int main(int argc, char *argv[]) {
	
	char cnt_n_args = 0;

	int *ptr_n_args;

	char **ptr_argv;

	char request[REQUEST_LIMIT];

	char response;

	int byte_count, byte_cnt;

	ptr_n_args = &argc;

	ptr_argv = argv;

	puts("R55-Versione-001");

	printf("Numero parametri ricevuti: %d\n", *ptr_n_args);

	while (*argv!='\0') {
		printf("Parametro [%d]: %s\n", cnt_n_args, *argv++);
		cnt_n_args++;
	}

	memset(&request, '0', sizeof(request));
	memset(&response, '0', sizeof(response));
    memset(&serv_addr, '0', sizeof(serv_addr));   

   	strcpy(request,  HEAD_REQ_PART_1);
	ptr_argv++;
   	strcat(request, *ptr_argv);
   	strcat(request, HEAD_REQ_PART_2);
	ptr_argv++;
	strcat(request, *ptr_argv);
   	strcat(request, HEAD_REQ_PART_3);

    serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT); 

	sock=socket(AF_INET,SOCK_STREAM,0);

	connect(sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr));

	printf("request %s\n",request);

	send(sock,request,strlen(request),0);

	while (read(sock,&response,1) > 0) {
      printf("%c",response);
    }

	return 0;
}



