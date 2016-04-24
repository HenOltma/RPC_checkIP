# RPC_checkerIP

Der Client muss mit folgenden zwei Argumenten gestartet werden:
	1. Client ip
	2. IPv4 Adresse die überprüft werden soll.

to do list:

	Server
	 - IpCheck() Code in rpc_checkIP_server.c / function checkip_1_svc() hinzufügen.

	Client

	 - Validierung der übergebenen IPv4 Adresse

return Values:

0 - success
1 - invalid subnetmask
2 - invalid ip-address
3 - invalid subnetmask && invalid ip-address

- Switch statement eventuell in .x Datei auslagern, mit unions oder so

