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

void print_menu_1(int s_id) {
	print_socket(s_id, "1: Beer \n");
	print_socket(s_id, "2: Wine \n");
	print_socket(s_id, "3: Cocktails \n");
}

void print_menu_2(int s_id) {
	print_socket(s_id, "1: Food \n");
	print_socket(s_id, "2: Drinks \n");
}