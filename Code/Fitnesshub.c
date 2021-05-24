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
			break;
		case 2:
			opcion2();
			break;
		case 3:
			opcion3();
			break;
		case 4:
			opcion4();
			break;
		case 0:
			opcion0();
			break;
		default:
			printf("Elección no existente, por favor elija de las opciones del menú");
			Menu();
			return 0;
	}
}
int opcion1(){
	int num,comprobarDNI,num3;
	int nm1;
	int fin;
	struct socio socio;
	
		system("cls");
		printf("Bienvenido, usted ha seleccionado 'Dar de Alta'\n");
		printf("¿Desea continuar? (En caso afirmativo pulse 1, en caso negativo pulse 0)\n");
		scanf ("%d", &num);
		
		if (num == 1){	
		
			system("cls");	
			printf ("Para poder dar de alta, por favor introduzca su nombre:\n");
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
				
					if(socio.tipo == 1){
						printf("Usted ha elegido la opción de tarifa normal\n");
						printf("Bienvenido %s %s al Gimnasio UPM. ¡Ahora a ponerse en forma!\n\n", socio.nom, socio.DNI);
			   		}else if (socio.tipo == 2){
						printf("Usted ha elegido la opción de tarifa VIP\n");
						printf("Bienvenido %s %s al Gimnasio UPM. ¡Ahora a ponerse en forma!\n\n", socio.nom, socio.DNI);
					}
					
			FILE * archivo;
			archivo = fopen("basedatos.txt","a");
			if ( archivo == NULL){
			printf ("Error, fichero no encontrado");
			return 0;
		}
		
			fprintf (archivo, "%s %s %d\n", socio.nom, socio.DNI, socio.tipo);
			fclose (archivo);
			
							
		} 	else if(num==0){
			system("cls");
			Menu();
		}
		
		printf("¿Desea realizar algo más?(1-Sí 0-No)\n");
		scanf("%d", &fin);
		if(fin==1){
		system("cls");	
		Menu();
		
	}	else if (fin==0){
		return 0;
	}
}
		
int opcion2(){
	int n2;
	int fin;
	char DNIrecibido[20];
	struct socio socio;
	
		printf("Bienvenido, usted ha seleccionado 'Dar de Baja'\n");
		printf("¿Desea continuar? (En caso afirmativo pulse 1, en caso negativo pulse 0)\n");
		scanf ("%d", &n2);
	
		if (n2==1){
		printf("Por favor introduzca el DNI con el que se inscribió:\n");
		scanf("%s", DNIrecibido);
		fflush(stdin);
		buscador(DNIrecibido);
	
		FILE * archivo;
		FILE * archivoAuxiliar;
		
		archivo = fopen("basedatos.txt","r");
		archivoAuxiliar = fopen("auxiliar.txt", "w");
		if ( archivo == NULL){
			printf ("Error, fichero no encontrado");
			return 0;
		}
	
		while(fscanf(archivo, "%s %s %d", socio.nom, socio.DNI, &socio.tipo) != EOF){
			 if (strcmp(socio.DNI, DNIrecibido) != 0){
				fprintf (archivoAuxiliar, "%s %s %d\n", socio.nom, socio.DNI, socio.tipo);		
			}
		}
	
		fclose (archivo);
		fclose (archivoAuxiliar);
		remove("basedatos.txt");
		rename("auxiliar.txt", "basedatos.txt");
	
	
  	} 	else if (n2==0){
  		system("cls");
		Menu();
  		}
  		printf("¿Desea realizar algo más?(1-Sí 0-No)\n");
		scanf("%d", &fin);
		if(fin==1){
		Menu();
	} 	
		else if(fin==0){
		return 0;
	}
}
	
int opcion3(){
	char DNIrecibido[20];
	int n3;
	int fin;
	struct socio socio;
	
		printf("Bienvenido, usted ha seleccionado 'Modificar Datos'\n");
		printf("¿Desea continuar? (En caso afirmativo pulse 1, en caso negativo pulse 0)\n");
		scanf("%d", &n3);
		
		if (n3==1){
			printf("Por favor introduzca el DNI con el que se inscribió:\n");
			scanf("%s", DNIrecibido);
			fflush(stdin);
	
			buscador(DNIrecibido);
	
	char nuevoNombre[20];
	char nuevoDNI[10];
	int nuevoTipo;
	
		printf("Por favor introduzca sus nuevos datos:\n");
		printf("Su nombre:\n");
		scanf("%s", nuevoNombre);
		fflush(stdin);
	
		printf("Su DNI:\n");
		scanf("%s", nuevoDNI);
		fflush(stdin);
	
		printf("El tipo de socio:\n");
		scanf("%d", &nuevoTipo);
		
		FILE * archivo;
		FILE * archivoAuxiliar;
	
		archivo = fopen("basedatos.txt","r");
		archivoAuxiliar = fopen("auxiliar.txt", "w");

		if ( archivo == NULL){
			printf ("Error, fichero no encontrado");
			return 0;
		}
	
		while(fscanf(archivo, "%s %s %d", socio.nom, socio.DNI, &socio.tipo) != EOF){
			if (strcmp(socio.DNI, DNIrecibido) != 0){
				fprintf (archivoAuxiliar, "%s %s %d\n", socio.nom, socio.DNI, socio.tipo);	
			}
			else{
				fprintf (archivoAuxiliar, "%s %s %d\n", nuevoNombre, nuevoDNI, nuevoTipo);
			}
		}
		
		fclose (archivo);
		fclose (archivoAuxiliar);
		remove("basedatos.txt");
		rename("auxiliar.txt", "basedatos.txt");
	
	
  	} else if (n3==0){
  		system("cls");
  		Menu();
  		}
  		
		printf("¿Desea realizar algo más?(1-Sí 0-No)\n");
		scanf("%d", &fin);
		if(fin==1){
		Menu();
		
	} 	else if (fin==0){
		return 0;
	}
}
	


int opcion4(){
	char DNIrecibido[20];
	int n4;
	int n5;
	int fin;
	struct socio socio;
	
		printf("Bienvenido, usted ha seleccionado 'Ver Datos'\n");
		printf("¿Desea continuar? (En caso afirmativo pulse 1, en caso negativo pulse 0)\n");
		scanf("%d", &n4);
		fflush(stdin);
		
		if (n4==1){
			printf("Por favor introduzca el DNI con el que se inscribió:\n");
			scanf("%s", DNIrecibido);
			fflush(stdin);
	
			buscador(DNIrecibido);
			
			FILE * archivo;
			archivo = fopen("basedatos.txt","r");

			if ( archivo == NULL){
			printf ("Error, fichero no encontrado");
			return 0;
		}
			while(fscanf(archivo, "%s %s %d", socio.nom, socio.DNI, &socio.tipo) != EOF){
		
			if (strcmp(socio.DNI, DNIrecibido) == 0){
			printf("========================\nLos datos del socio con DNI %s son:\n========================\n", &socio.DNI);
			printf("Nombre: %s\n", socio.nom); 
			printf("DNI: %s\n", socio.DNI);
			printf("Tipo: %d \n", socio.tipo);
			
			if(socio.tipo==1){
				printf("Socio Normal");
			}else if(socio.tipo==2){
				printf("Socio VIP");
			} 
			
			printf("¿Desea modificar algo?(1-Sí, 0-No)");
			scanf("%d", &n5);
			if (n5==1){
				opcion3();
			}else if (n5==0){
				break;
			}
		}
	}
			fclose (archivo);
	
	} 	else if (n4==0){
		system("cls");
  		Menu();
	} 		

		printf("¿Desea realizar algo más?(1-Sí 0-No)\n");
		scanf("%d", &fin);
		if(fin==1){
		Menu();
	} 	
		else if(fin==0){
		return 0;
	}
}

int opcion0(){
		return 0;
	}
	
