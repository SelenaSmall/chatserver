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
	
	print_socket(coms_sock_id, "Hello\n");

	options_menu(coms_sock_id);

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

void options_menu( int s_id) {
	char buffer[1024];

	print_socket(s_id, "Please select an option:\n"); 
	print_socket(s_id, "1: See the Menu \n");
	print_socket(s_id, "2: Make and Order\n");
	print_socket(s_id, "3: See how much I've spent\n");
	print_socket(s_id, "4: Too hard, I quit\n");

	int running = 1;
	while(running) {
		print_socket(s_id, ">");

		gets_socket(s_id, (char*)&buffer);
		int command = atoi(buffer);
		switch(command) {
			case 1: 
				print_menu_1(s_id);
				break;
			case 2: 
				print_menu_2(s_id);
				break;
			case 3: 
				print_socket(s_id, "Total: \n");
				break;
			case 4: 
				running = 0;
				break;
			default:
				print_socket(s_id, "That is not an option!\n");
				break;
		}
	}
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

void print_menu_1(int s_id) {
	print_socket(s_id, "1: Beer \n");
	print_socket(s_id, "2: Wine \n");
	print_socket(s_id, "3: Cocktails \n");
}

void print_menu_2(int s_id) {
	print_socket(s_id, "1: Food \n");
	print_socket(s_id, "2: Drinks \n");
}