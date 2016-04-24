#include "rpc_checkIP.h"

/**
 * Lässt check_ip_1 auf dem Server laufen
 * @param host die ip vom client
 * @param ip   Die zu testende ip-adresse
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
			printf("IP-Adresse ist gültig und befindet sich im Subnetz des Hosts\n");
			break;

		case 1:
			printf("Die Subnetzmaske ist ungülitg\n");
			break;

		case 2:
			printf("IP-Adresse ist ungültig\n");
			break;

		case 3:
			printf("IP-Adresse und Subnetzmaske sind ungültig\n");
			break;

		case 4:
			printf("IP-Adresse befindet sich nicht im Subnetz des Hosts\n");
			break;

		case 5:
			printf("IP-Adresse ist die Broadcastadresse des Subnetzes\n");
			break;

		case 6:
			printf("IP-Adresse ist die Routeradresse des Subnetzes\n");
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
    int result;
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
