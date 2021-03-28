#include <stdio.h>
#include <locale.h>
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
	printf("Opción introducida: ");
	scanf ("%d", &opcion);
		switch(opcion){	
		case 1:
			// Realizar lo que tenga que hacer la llamada funcion de dar de alta
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
