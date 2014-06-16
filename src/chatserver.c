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
	print_socket(s_id, "1: See the Drinks Menu \n");
	print_socket(s_id, "2: Make an Order\n");
	print_socket(s_id, "3: See how much I've spent\n");
	print_socket(s_id, "4: Too hard, I quit\n");

	int running = 1;
	while(running) {
		print_socket(s_id, ">");

		gets_socket(s_id, (char*)&buffer);
		int command = atoi(buffer);
		switch(command) {
			case 1: 
				print_menu_drinks(s_id);
				break;
			case 2: 
				print_menu_order(s_id);
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

void print_menu_drinks(int s_id) { /* needs to be seperate loop from above*/
	char buffer[1024]; 

	print_socket(s_id, "1: Beer \n");
	print_socket(s_id, "2: Wine \n");
	print_socket(s_id, "3: Cocktails \n");
	print_socket(s_id, "4: Go Back \n");

	int running = 2;
	while(running) {
		print_socket(s_id, ">");

		gets_socket(s_id, (char*)&buffer);
		int command = atoi(buffer);
		switch(command) {
			case 1: 
				print_beer_options(s_id);
				break;
			case 2: 
				print_wine_options(s_id);
				break;
			case 3: 
				print_cocktail_options(s_id);
				break;
			case 4: 
				options_menu(s_id); /*should return to print options menu */
				break;
			default:
				print_socket(s_id, "That is not an option!\n");
				break; 
		}
	} 
}

void print_beer_options(int s_id) {
	char buffer[1024];

	print_socket(s_id, "1: Pilsner \n");
	print_socket(s_id, "2: IPA \n");
	print_socket(s_id, "3: Pale Ale \n");
	print_socket(s_id, "4: Dark Ale \n");
	print_socket(s_id, "5: Blonde Ale \n");
	print_socket(s_id, "6: Go Back \n");

	int running = 3;
	while(running) {
		print_socket(s_id, ">");

		gets_socket(s_id, (char*)&buffer);
		int command = atoi(buffer);
		switch(command) {
			case 1: 
				print_socket(s_id, "Pilsner\n");
				break;
			case 2: 
				print_socket(s_id, "IPA\n");
				break;
			case 3: 
				print_socket(s_id, "Pale Ale\n");
				break;
			case 4: 
				print_socket(s_id, "Dark Ale\n");
				break;
			case 5: 
				print_socket(s_id, "Blonde Ale\n");
				break;
			case 6: 
				print_menu_drinks(s_id); /*should return to print options menu - it does but its not a loop and doesnt say anything*/
				break;
			default:
				print_socket(s_id, "That is not an option!\n");
				break;
		}
	}

}

void print_wine_options(int s_id) {
	char buffer[1024];

	print_socket(s_id, "1: Red Wine \n");
	print_socket(s_id, "2: White Wine \n");
 	print_socket(s_id, "3: Go Back \n");

 	int running = 3;
	while(running) {
		print_socket(s_id, ">");

		gets_socket(s_id, (char*)&buffer);
		int command = atoi(buffer);
		switch(command) {
			case 1: 
				print_socket(s_id, "Red Wine\n");
				break;
			case 2: 
				print_socket(s_id, "White Wine\n");
				break;
			case 3: 
				print_menu_drinks(s_id);
				break;
			default:
				print_socket(s_id, "That is not an option!\n");
				break;
		}
	}	
}

void print_cocktail_options(int s_id) {
	char buffer[1024];

	print_socket(s_id, "1: Martini \n");
	print_socket(s_id, "2: Margarita \n");
	print_socket(s_id, "3: Go Back \n");

	int running = 3;
	while(running) {
		print_socket(s_id, ">");

		gets_socket(s_id, (char*)&buffer);
		int command = atoi(buffer);
		switch(command) {
			case 1: 
				print_socket(s_id, "Martini\n");
				break;
			case 2: 
				print_socket(s_id, "Margarita\n");
				break;
			case 3: 
				print_menu_drinks(s_id);
				break;
			default:
				print_socket(s_id, "That is not an option!\n");
				break;
		}
	}
}

void print_menu_order(int s_id) {
	char buffer[1024];

	print_socket(s_id, "1: Food \n");
	print_socket(s_id, "2: Drinks \n");
	print_socket(s_id, "2: Go Back \n");

	int running = 3;
	while(running) {
		print_socket(s_id, ">");

		gets_socket(s_id, (char*)&buffer);
		int command = atoi(buffer);
		switch(command) {
			case 1: 
				print_socket(s_id, "Food\n");
				break;
			case 2: 
				print_socket(s_id, "Drinks\n");
				break;
			case 3: 
				print_menu_drinks(s_id);
				break;
			default:
				print_socket(s_id, "That is not an option!\n");
				break;
		}
	}		
}