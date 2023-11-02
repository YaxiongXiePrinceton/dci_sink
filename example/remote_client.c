#include <assert.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/time.h>
#include <unistd.h>

#include "dci_sink_client.h"
#include "dci_sink_ring_buffer.h"

bool go_exit = false;

ngscope_dci_sink_CA_t dci_CA_buf;

int main(int argc, char** argv){
    pthread_t test_thd;
    pthread_create(&test_thd, NULL, dci_sink_client_thread, NULL);
	pthread_join(test_thd, NULL);

	printf("abs");
    return 1;
}
