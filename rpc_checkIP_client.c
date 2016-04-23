#include "rpc_checkIP.h"

void check_ip_1(char *host, ip_str *ip) {
	CLIENT *clnt;
	int  *result_1;
	ip_str  checkip_1_arg = *ip;
  printf("%s\n", checkip_1_arg);

#ifndef	DEBUG
	clnt = clnt_create (host, CHECK_IP, CHECK_IP_1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = checkip_1(&checkip_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int main (int argc, char *argv[]) {
	char *host;
  ip_str  checkip_1_arg = argv[2];

	if (argc < 3) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
  printf("host: %s\n", host);
  printf("ip: %s\n", checkip_1_arg);
	check_ip_1 (host, &checkip_1_arg);
	exit (0);
}
