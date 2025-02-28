/*
Codigo que imprime los bits de los registros A,B,C y D del RTC cada 0.5 segundos, N veces.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#include <time.h>
#define P 0x70 /* RTC */


unsigned char in (unsigned char reg){
    outb (reg, P);
    return inb(P + 1);
}

void out (unsigned char valor, unsigned char reg){
    outb (reg, P);
    outb (valor, P + 1);
}

//funcion que convierte a binario
int *toBin2(unsigned char dato, int *p){  
    int resto = 0, bin = 0;
    int j=8,i;

    for (i = 0; i < 8; i++){ //incializo el vector a 0
        p[i]=0;
    }

    while(dato > 0){ 
        resto = dato % 2;
        j-=1;
        p[j]=resto;
        dato = dato/2;
    }
    return p;
}

void UIP(){
    unsigned char regA;
    regA=in(0x0A);
    if((regA & 0x80)!=0){
        usleep(1984);     //Tiempo maximo de espera
    }
}

int main(){
    unsigned char a, b, c, d;
    int j,h; 
    int p[8]={0,0,0,0,0,0,0,0};
    float time=0.0;

    if(ioperm(P, 2, 1)){
        perror("ioperm"); 
        exit(1);
    }

    for (j = 0; j < 120; j++){  
        system("clear"); //limpia la pantalla
        printf(".===============================================.\n");
        printf("|__________________REGISTRO A___________________|\n");
            printf("| UIP | DV2 | DV1 | DV0 | RS3 | RS2 | RS1 | RS0 |\n");
        UIP();
        a = in(0x0A);
        toBin2(a,p);
        for (h = 0; h < 8; h++){
            printf("|  %d  ",p[h]);   
        }
        printf("|\n");

        printf("|===============================================|\n");
        printf("|__________________REGISTRO B___________________|\n");
        printf("| SET | PIE | AIE | UIE | SQWE|  DM |24/12| DSE |\n");
        b = in(0x0B);
        toBin2(b,p);  
        for (h = 0; h < 8; h++){
            printf("|  %d  ",p[h]);   
        }
        printf("|\n");

        printf("|===============================================|\n");
        printf("|__________________REGISTRO C___________________|\n");
        printf("| IRQF|  PF |  AF |  UF |  0  |  0  |  0  |  0  |\n");
        c = in(0x0C);
        toBin2(c,p);
        for (h = 0; h < 8; h++){
            printf("|  %d  ",p[h]);   
        }
        printf("|\n");

        printf("|===============================================|\n");
        printf("|__________________REGISTRO D___________________|\n");  
        printf("| VRT |  0  |  0  |  0  |  0  |  0  |  0  |  0  |\n");
        d = in(0x0D);
        toBin2(d,p);
        for (h = 0; h < 8; h++){
            printf("|  %d  ",p[h]);   
        }
        printf("|\n");

        printf("·===============================================·\n\n");
        printf("          %0.2f segundos transcurridos\n",time);
        time+=0.5;
        usleep(500000);  //tiempo de espera: 0.5 segundos
        system("clear"); //funcion que limpia la pantalla
    }
    if (ioperm(P, 2, 0)){
        perror("ioperm");
        exit(1);
    }
    return 0;
}
