#include <stdio.h>
#include <locale.h>
struct socio {
	char nom[100];
	int nDNI;
	char lDNI;
	int tipo;
	
};


int main ()
{
	setlocale(LC_ALL, "spanish");
	int opcion;
	printf("===== MENÚ PRINCIPAL ==== \n");
	printf("1.- Dar de alta\n");
	printf("2.- Dar de baja\n");
	printf("3.- Modificar datos\n");
	printf("4.- Ver datos\n");
	printf("0.- Salir\n");
	Menu();
}
int Menu(){
	int opcion;
	printf("Opción introducida:\n");
	scanf ("%d", &opcion);
	int num,num2,num3;
	struct socio socio;
		switch(opcion){	
		case 1:
			printf("Bienvenido, usted ha seleccionado 'dar de alta'\n");
			printf("¿desea continuar? (En caso afirmativo pulse 1, en caso negativo pulse 2)\n");
			scanf ("%d", &num);
			if (num==1){
				printf ("Para poder darle de alta por favor introduzca su nombre completo: ");
				scanf ("%s", socio.nom);
				fflush(stdin);
				num2=2; 
				while (num2 == 2){
					printf ("Hola %s introduzca su DNI: ", socio.nom);
					scanf("%d %c", &socio.nDNI, &socio.lDNI);
					printf ("%d %c ¿es este su DNI? (En caso afirmativo pulse 1, en caso negativo pulse 2)\n", socio.nDNI, socio.lDNI);
					scanf("%d", &num2);
					system("cls");	
					}	
						printf ("Qué tipo de socio desea ser:\n");
						printf("Tarifa normal(Pulse 1)\n");
						printf("Tarifa VIP(Pulse 2)\n");
						scanf("%d", &socio.tipo);
							if (socio.tipo == 1){
								printf("Usted ha elegido la opción de tarifa normal\n");
								printf("Bienvenido %s (%d%c) al Gimnasio UPM ahora a ponerse en forma", socio.nom, socio.nDNI, socio.lDNI);
						   }else if (socio.tipo==2){
								printf("Usted ha elegido la opción de tarifa VIP\n");
								printf("Bienvenido %s (%d%c) al Gimnasio UPM ahora a ponerse en forma", socio.nom, socio.nDNI, socio.lDNI);
					} 	
						
			} else if(num==2){
				system("cls");
				return main();
			}
			return 0;
		case 2:
			// Realizar lo que tenga que hacer la llamada funcion de dar de baja
			return 0;	
		case 3:
			// Realizar lo que tenga que hacer la llamada funcion de modificar datos
			return 0;
		case 4:
			// Realizar lo que tenga que hacer la llamada funcion de ver datos
			return 0;
		case 0:
			// Realizar lo que tenga que hacer la llamada salir
			return 0;
		default:
			//Opcion no dada
			return 0;
	}
	}

