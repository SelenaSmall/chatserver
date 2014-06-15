#define CHATSERVER_PORT 1024

int create_listening_socket(int port);

void print_socket(int s_id, char *str);

void gets_socket(int s_id, char *str);