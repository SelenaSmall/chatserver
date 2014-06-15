#define CHATSERVER_PORT 1024

int create_listening_socket(int port);

void print_socket(int s_id, char *str);

void gets_socket(int s_id, char *str);

void options_menu( int s_id);

void print_menu_1(int s_id);

void print_menu_2(int s_id);