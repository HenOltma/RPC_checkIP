#include "rpc_checkIP.h"

/**
 * Hier wird die konkrete Methode check_ip_1 implementiert
 * //TODO: ist glaub ich gar nicht nötig, es ist eher gefordert, die ip-adresse
 * 				 an den Server zu übermitteln und dessen Antwort zu verarbeiten
 * @param host ?
 * @param ip   ?
 */
void check_ip_1(char *host, ip_str *ip) {
	CLIENT *clnt;
	int  *result_1;
	ip_str  ip_adress = *ip;
  printf("%s\n", ip_adress);

	#ifndef	DEBUG
	clnt = clnt_create (host, CHECK_IP, CHECK_IP_1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
	#endif	/* DEBUG */

	result_1 = checkip_1(&ip_adress, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	#ifndef	DEBUG
	clnt_destroy (clnt);
	#endif	 /* DEBUG */
}

/**
 * Main
 */
int main (int argc, char *argv[]) {
	char *host;
  ip_str ip_adress = argv[2];

	if (argc < 3) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
  printf("host: %s\n", host);
  printf("ip: %s\n", ip_adress);
	check_ip_1 (host, &ip_adress);
	exit (0);
}
