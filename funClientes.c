#include "funClientes.h"
#include "fun.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menuLogin(){
	char str[2];
	int num;

		printf("\nLOGIN CLIENTE:\n");
		printf("\t1. Cliente\n");
		printf("\t2. Nuevo cliente\n");
		printf("Seleccione una opcion: ");

		fgets(str, 2, stdin);
		clear_if_needed(str);

		sscanf(str, "%d", &num);
		printf("\n");

	return num;
}


int menuCliente(){
	char str[2];
	int num;

	printf("\nCLIENTES:\n");
	printf("\t1. Buscar un libro\n");
	printf("\t2. Ver la cesta\n");
	printf("\t3. Lista de deseos\n");
	printf("\t4. Modificar perfil\n");
	printf("\t5. Agregar fondos a la cuenta\n");
	printf("\t6. Salir\n");
	printf("Seleccione una opcion: ");
clear_if_needed(str);
	fgets(str, 2, stdin);
	clear_if_needed(str);

	sscanf(str, "%d", &num);
	printf("\n");

	return num;
}


void menuComprarLibro(){
	char str[2];
	int num;

	printf("\nBUSCAR:\n");
	printf("\t1. Mostrar libros.\n");
	printf("\t2. Buscar por autor.\n");
	printf("\t3. Buscar por titulo.\n");
	printf("\t4. Atras\n");
	printf("Seleccione una opcion: ");

	fgets(str, 2, stdin);
	clear_if_needed(str);
	sscanf(str, "%d", &num);

	switch(num){
		case 1: readLib();
				menuComprarLibro();
				break;
		case 2: menuComprarLibro();
				break;
		case 3: menuComprarLibro();
				break;
		case 4: break;
		default: error();
	}

	sscanf(str, "%d", &num);
	printf("\n");
}

void writeCl(Cliente* cl){
	FILE* f;
        int c;

	f = fopen("clientes.txt", "a");

	fprintf(f, "%s\n", cl->usuario);
	fprintf(f, "%s\n", cl->password);

	//cerrar fichero
	fclose(f);
}

int comparacion (Cliente* cl, int opc){
	FILE* f;
    char c;
    char leer[20];
	char linea[50];
	int counter = 1;
	int comp = 0;
	int aux = 0;

	//abrir fichero para lectura
	f = fopen("clientes.txt", "r");

    if (f==NULL){
    	printf("Error al abrir el fichero\n");

    }else{
		while (fgets(linea, 20, f)) {
			
			if(opc == 1){ //LOG IN
				clear_if_needed(linea);
				if (counter % 2 != 0){
					sscanf(linea, "%s", &leer);
					if (strcmp(leer, cl->usuario) == 0)
						aux = 1;
				}
				if (aux==1){
					counter++;
					clear_if_needed(linea);
					if (counter % 2 == 0){
						sscanf(linea, "%s", &leer);
						if (strcmp(leer,cl->password) == 0)
							comp = 1;
					}
				}
			
			} else if(opc == 2){ //NUEVO CLIENTE
				
				if (counter % 2 != 0){
					sscanf(linea, "%s", &leer);
					if (strcmp(leer, cl->usuario) == 0){
						comp = 1;
					}
				}
			}
			counter++;
		}
	}

	//cerrar fichero
	fclose(f);
	return comp;
}