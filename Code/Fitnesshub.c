#include <stdio.h>
#include <string.h>
#include <locale.h>

struct socio {
	char nom[100];
	char DNI[10];
	int tipo;	
};

int main ()
{
	setlocale(LC_ALL, "spanish"); 
	searchfile();
	Menu();
		
}

int searchfile(){
	FILE * archivo;
	archivo = fopen("basedatos.txt","r");
	if (archivo == NULL){
		// si no existe el archivo se crea uno.
		fclose (archivo);
		createfile();
	} else {
		fclose (archivo);
		return 0;
	}
}


int createfile(){
	FILE * archivo; 
	archivo = fopen("basedatos.txt","w");
	fclose(archivo);
}



int buscador(char DNIrecibido[20]){
	struct socio socio;
	FILE * archivo;
	archivo = fopen("basedatos.txt","r");	
	if ( archivo == NULL){
		printf ("Error, fichero no encontrado");
		return 0;
	}
	while(fscanf(archivo, "%s %s %d", socio.nom, socio.DNI, &socio.tipo) != EOF){
	if (strcmp(DNIrecibido,socio.DNI) == 0){
			fclose(archivo);
			return 1;
		} 
	}
	fclose (archivo);	
	return 0;
	
}


int Menu(){
	int opcion;
	printf("===== MENÚ PRINCIPAL ===== \n");
	printf("1.- Dar de alta\n");
	printf("2.- Dar de baja\n");
	printf("3.- Modificar datos\n");
	printf("4.- Ver datos\n");
	printf("0.- Salir\n");
	printf("Opción introducida:\n");
	scanf ("%d", &opcion);
	switch(opcion){
		case 1:
			opcion1();
		/*case 2:
			opcion2();
		case 3:
			opcion3();
		case 4:
			opcion4();
		*/
		case 0:
			return 0;
	}
}
int opcion1(){
	int num,comprobarDNI,num3;
	int nm1;
	struct socio socio;
			printf("Bienvenido, usted ha seleccionado 'dar de alta'\n");
			printf("¿Desea continuar? (En caso afirmativo pulse 1, en caso negativo pulse 2)\n");
			scanf ("%d", &num);
			if (num == 1){
				printf ("Para poder darle de alta por favor introduzca su nombre: ");
				scanf("%s", socio.nom);
				fflush(stdin);
				comprobarDNI = 0; 
				while (comprobarDNI == 0){
					printf ("Hola %s introduzca su DNI: ", socio.nom);
					scanf("%s", socio.DNI);
					fflush(stdin);
					printf ("%s ¿es este su DNI? (En caso afirmativo pulse 1, en caso negativo pulse 0)\n", socio.DNI);
					scanf("%d", &comprobarDNI);
					if (comprobarDNI == 1){
						if (buscador(socio.DNI) == 1){
							comprobarDNI=0;
							printf("Error: DNI ya registrado. Inténtelo de nuevo.\n\n"); //se repite siempre esto
						}
					}
					else if (comprobarDNI == 0){
					printf("\n\n");
						}
					}	
						printf ("¿Qué tipo de socio desea ser?\n");
						printf("Tarifa normal (Pulse 1)\n");
						printf("Tarifa VIP (Pulse 2)\n");
						scanf("%d", &socio.tipo);
							if (socio.tipo == 1){
								printf("Usted ha elegido la opción de tarifa normal\n");
								printf("Bienvenido %s %s al Gimnasio UPM. ¡Ahora a ponerse en forma!", socio.nom, socio.DNI);
						   }else if (socio.tipo == 2){
								printf("Usted ha elegido la opción de tarifa VIP\n");
								printf("Bienvenido %s %s al Gimnasio UPM. ¡Ahora a ponerse en forma!", socio.nom, socio.DNI);
					} 	
						
			} else if(num==2){
				system("cls");
				Menu();
			}
			return 0;
		}
		
/*int opcion2();
	int n2;
	printf("Bienvenido, usted ha seleccionado 'bajar de alta'\n");
	printf("¿Desea continuar? (En caso afirmativo pulse 1, en caso negativo pulse 2)\n");
	scanf ("%d", &n2);
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
}*/
	
