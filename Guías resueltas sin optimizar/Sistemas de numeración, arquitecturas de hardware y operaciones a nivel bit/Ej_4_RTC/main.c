#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#define P 0x70 /* RTC */

unsigned char in (unsigned char reg){
  outb (reg, P);
  return inb(P + 1);
  }

void out (unsigned char valor, unsigned char reg){
  outb (reg, P);
  outb (valor, P + 1);
  }

 unsigned char bcd_to_binary(unsigned char bcd) {
    return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

unsigned char binary_to_bcd(unsigned char binary) {
    return ((binary / 10) << 4) | (binary % 10);
}

int main(void){
  unsigned char hora, min, seg, a, b, c, i;

    /*Leer minutos*/
    min = in(0x02);

    /*Leer hora*/
    hora = in(0x04);

    seg = in(0x00);


    seg = bcd_to_binary(seg);
    min = bcd_to_binary(min);
    hora = bcd_to_binary(hora);

    seg = seg + 5;
    if (seg >= 60) {
        seg -= 60;
        min++;
        if (min >= 60) {
            min = 0;
            hora++;
            if (hora >= 24) {
                hora = 0;
            }
        }
    }
    seg = binary_to_bcd(seg);
    min = binary_to_bcd(min);
    hora = binary_to_bcd(hora);


  /* Dar permisos a los ports 70 y 71 */
  if (ioperm(P, 2, 1)) {
     perror("ioperm");
     printf("Verifique que esta ejecutando con usuario root o en modo root con sudo\n");
     exit(1);
  }

  out (seg, 0x01);  /* Setear segundos alarma */
  out (min, 0x03);  /* Setear minutos alarma */
  out (hora, 0x05); /* Setear hora alarma */

  c = in (0x0C); /* Borro flags anteriores */
  /* Hacer polling del reg C */
  printf ("Esperando las alarmas (no se activaran en una maquina virtual)...\n");
  for (i = 0; i < 120; i++){ /* Espera 60 segundos en total */
    c = in (0x0C);
    /* Verif bit 5 (AF) */
    if (c & 0x20)
	    printf ("Alarma\n");
    usleep(500000);   /* Esperar 500ms */
  }

  /* Retirar permisos */
  if (ioperm(P, 2, 0)) {
     perror("ioperm");
     exit(1);
  }
  return 0;
}
