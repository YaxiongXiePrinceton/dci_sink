#ifndef SOCK_HH
#define SOCK_HH

#ifdef __cplusplus
extern "C" {
#endif


void sock_setnonblocking(int sockfd);
bool sock_same_sock_addr(struct sockaddr_in *a, struct sockaddr_in *b);
int sock_connectServer_w_config_udp(char serv_IP[40], int serv_port);

int sock_close_and_notify_udp(int sockfd);
struct sockaddr_in sock_create_serv_addr(char serv_IP[40], int serv_port);

#ifdef __cplusplus
}
#endif
#endif
