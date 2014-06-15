#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

#include "chatserver.h"

int main() {
	char buffer[1024];

	int listen_sock_id, coms_sock_id;
	
	printf("Chatserver Starting on %d\n",CHATSERVER_PORT);

	listen_sock_id = create_listening_socket(CHATSERVER_PORT);

	printf("Chatserver Listening\n");

	coms_sock_id = accept(listen_sock_id, NULL, NULL);
	
	print_socket(coms_sock_id, "Hello\n");

	print_socket(coms_sock_id, "Please select an option:\n"); 
	print_socket(coms_sock_id, "1: See the Menu \n");
	print_socket(coms_sock_id, "2: Make and Order\n");
	print_socket(coms_sock_id, "3: See how much I've spent\n");
	print_socket(coms_sock_id, "4: Too hard, I quit\n");

	int running = 1;
	while(running) {
		print_socket(coms_sock_id, ">");

		gets_socket(coms_sock_id, (char*)&buffer);
		int command = atoi(buffer);
		switch(command) {
			case 1: 
				print_socket(coms_sock_id, "Beer \n Wine \n Cocktails \n");
				break;
			case 2: 
				print_socket(coms_sock_id, "Food \n Drinks \n");
				break;
			case 3: 
				print_socket(coms_sock_id, "Total: \n");
				break;
			case 4: 
				running = 0;
				break;
			default:
				print_socket(coms_sock_id, "That is not an option!\n");
				break;
		}
	}

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

void print_socket(int s_id, char *str) {
	write(s_id, str, strlen(str));
}

void gets_socket(int s_id, char *str) {
	char c;
	while(1) {
		read(s_id, &c, 1);
		if (c == 10) break;
		*str = c;
		str++;
	}
	*str = 0;
}