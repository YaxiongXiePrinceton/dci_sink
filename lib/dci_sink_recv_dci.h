#ifndef SINK_RECV_DCI_HH
#define SINK_RECV_DCI_HH

#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netinet/in.h>
#include <poll.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

#include "dci_sink_def.h"
#include "dci_sink_ring_buffer.h"
#ifdef __cplusplus
extern "C" {
#endif

int ngscope_dci_sink_recv_buffer(ngscope_dci_sink_CA_t *q, char *recvBuf,
                                 int idx, int recvLen);
#ifdef __cplusplus
}
#endif

#endif
