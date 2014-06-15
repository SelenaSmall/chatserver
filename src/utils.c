#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

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

