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


#include "dci_sink.h"

bool go_exit = false;

ngscope_dci_sink_serv_t dci_sink_serv;



int main(int argc, char** argv){
	sock_init_dci_sink(&dci_sink_serv, 6666);

	cell_config_t cell_config;
	cell_config.nof_cell = 1;
	cell_config.cell_prb[0] = 50;
	cell_config.rnti  	= 1111;

    pthread_t test_thd;
    pthread_create(&test_thd, NULL, dci_sink_server_thread, (void *)&cell_config);

	ue_dci_t ue_dci;
	ue_dci.cell_idx = 0;
	ue_dci.tti  	= 111;
	ue_dci.rnti  	= 1111;

	ue_dci.dl_tbs 	= 1111;
	ue_dci.dl_reTx 	= 1;
	ue_dci.dl_rv_flag 	= false;
	
	ue_dci.ul_tbs 	= 2222;
	ue_dci.ul_reTx 	= 0;
	ue_dci.ul_rv_flag 	= false;

	while(!go_exit){
		sock_send_single_dci(&dci_sink_serv, &ue_dci, 0);	
		usleep(1000);
	}

	pthread_join(test_thd, NULL);

	printf("abs");
    return 1;
}
