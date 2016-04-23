/* checkIP Defintion */
/* max. länge von IPv.4 in "dotted decimal notation" */
const MAXLEN = 19;

/* string für ip adresse */
typedef string ip_str<MAXLEN>;

/* checkIP programm definition */
program CHECK_IP {
    version CHECK_IP_1 {
        int CHECKIP(ip_str) = 1;
    } = 1;
} = 0x2fffffff;