#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

#include "chatserver.h"

int main() {

	int listen_sock_id, coms_sock_id;
	
	printf("Chatserver Starting on %d\n",CHATSERVER_PORT);

	listen_sock_id = create_listening_socket(CHATSERVER_PORT);

	printf("Chatserver Listening\n");

	coms_sock_id = accept(listen_sock_id, NULL, NULL);
	
	char str[] = "Hello :)\n\x00";
	write(coms_sock_id, str, strlen(str));

	close(listen_sock_id);
}

int create_listening_socket(int port) {
	int listen_socket;

	struct sockaddr_in server_addr;

	bzero( &server_addr, sizeof(server_addr));

	listen_socket = socket(AF_INET,SOCK_STREAM,0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(port);

	bind(listen_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
	
	listen(listen_socket, 1);

	return listen_socket;
}