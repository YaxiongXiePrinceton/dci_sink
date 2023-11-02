#ifndef DCI_SINK_SOCK_HH
#define DCI_SINK_SOCK_HH
#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netinet/in.h>
#include <poll.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

#include "dci_sink_def.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  struct sockaddr_in client_addr[MAX_CLIENT];
  int nof_client;
  pthread_mutex_t mutex;
} client_list_t;

// remote file sink / server
typedef struct {
  client_list_t client_list; // the list that stores all the clients
  int sink_port;             // the port of the server
  int sink_sockfd;           // serv sock filedescriptor
} ngscope_dci_sink_serv_t;


bool sock_init_dci_sink(ngscope_dci_sink_serv_t *q, int port);
void sock_update_client_list_addr(client_list_t *q, struct sockaddr_in *addr);

int sock_send_config(ngscope_dci_sink_serv_t *q, cell_config_t *cell_config);
int sock_send_single_dci(ngscope_dci_sink_serv_t *q, ue_dci_t *ue_dci,
                         int proto_v);

// The client connect with the server
int sock_connectServer_w_config_udp(char serv_IP[40], int serv_port);

// The client close the connection and notify the server
int sock_close_and_notify_udp(int sockfd);

#ifdef __cplusplus
}
#endif

#endif
