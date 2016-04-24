#include "rpc_checkIP.h"

/**
 * Hier wird die konkrete Methode check_ip_1 implementiert
 * //TODO: ist glaub ich gar nicht nötig, es ist eher gefordert, die ip-adresse
 * 				 an den Server zu übermitteln und dessen Antwort zu verarbeiten
 * @param host ?
 * @param ip   ?
 */
void check_ip_1(char *host, ip_str *ip) {
	CLIENT  *clnt;
	int     *result_1;
	ip_str  ip_adress = *ip;

  printf("%s\n", ip_adress);
	printf("Erstelle Client...\n");

	clnt = clnt_create (host, CHECK_IP, CHECK_IP_1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

	printf("Client erfolgreich erstellt!\n");
	printf("Stelle Anfrage an Server...\n");

	result_1 = checkip_1(&ip_adress, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	printf("Anfrage erfolgreich!\nErgebnis:\n");

	switch (*result_1) {
		case 0:
			printf("Alles Gut!\n");
			break;

		default:
			printf("Ungültige Antwort vom Server!\n");
	}

	printf("Beende Programm...\n");

	clnt_destroy (clnt);
}

/**
 * Main
 */
int main (int argc, char *argv[]) {
	char *host;
  ip_str ip_adress = argv[2];

	printf("Anzahl der Argumente: %d\n", argc);

	if (argc < 3) {
		printf ("usage: %s: <client ip> <zu überprüfende adresse>\n", argv[0]);
		exit (1);
	}
	host = argv[1];
  printf("host: %s\n", host);
  printf("ip: %s\n", ip_adress);
	check_ip_1 (host, &ip_adress);
	exit (0);
}
