#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consumo.h"

int main(int argc, char *argv[]) {
	consumo *maquina = NULL;
	int opcion=0;
	int cant=0;
	int i, j;
	
	do {
		do {
			MostrarMenu();
			printf("\nIngrese la opcion: ");
			scanf("%d", &opcion);
			
			if(opcion <=0 || opcion >5){
				printf("\nOpcion incorrecta ingrese un numero del 1 al 5\n");
			}
		} while(opcion <=0 || opcion >5);
		LimpiarBuffer();
		
		switch(opcion){
			case 1: 
				maquina = IngresarDatos(maquina, &cant);
				break;
			case 2:
				MaxTension(maquina, cant);
				break;
			case 3:
				MaxCorriente(maquina, cant);
				break;
			case 4:
				BuscarMaquina(maquina, cant);
				break;
			case 5:
				printf("\n\n\nAdios...");
				break;
		}
		
	} while(opcion != 5);
	
	
	return 0;
}

void MostrarMenu(){
	printf("\nOpciones: \n");
	printf("1. Ingresar maquina y sus valores. \n");
	printf("2. Valores maximos de tension. \n");
	printf("3. Valores maximos de corriente. \n");
	printf("4. Buscar maquina. \n");
	printf("5. Salir del programa. \n");
}
	
consumo* IngresarDatos(consumo *m, int *c){
	char nombre[31];
	int cantidad = *c + 1;
	int nTension, nCorriente;
	
	consumo *temporal = (consumo*) realloc(m, cantidad * sizeof(consumo));
	if (temporal == NULL){
		printf("\nERROR: No se pudo asignar memoria para la maquina nueva.\n");
		return m;
	}
	m = temporal;
	
	printf("\nIngrese el nombre de la maquina: ");
	fgets(nombre, 31, stdin); 
	nombre[strlen(nombre)-1]='\0';
	strcpy(m[*c].nombreMaquina, nombre);
	
	do {
		printf("\nIngrese la tension: ");
		scanf("%d", &nTension);
		
		if(nTension < 0){
			printf("\nIngrese la tension positiva por favor.\n");
		}
	} while(nTension < 0);
	m[*c].tension = nTension;
	
	do {
		printf("\nIngrese la corriente: ");
		scanf("%d", &nCorriente);
		
		if(nCorriente < 0){
			printf("\nIngrese la corriente positiva por favor.\n");
		}
	} while(nCorriente < 0);
	m[*c].corriente = nCorriente;
	
	LimpiarBuffer();
	
	(*c)++;
	printf("\nMaquina agregada correctamente.\n");
	
	return m;
}
	
void MaxTension(consumo *m, int c){
	int i;
	int lugarTensionAlta1 = -1;
	int lugarTensionAlta2 = -1;
	int tensionAlta1 = 0;
	int tensionAlta2 = 0;
	
	if (c == 0 || m == NULL) {
		printf("\nNo hay maquinas guardadas.\n");
		return;
	}
	
	for (i=0; i<c; i++){
		if (m[i].tension >= tensionAlta1){
			tensionAlta2 = tensionAlta1;
			lugarTensionAlta2 = lugarTensionAlta1;
			
			lugarTensionAlta1 = i;
			tensionAlta1 = m[i].tension;
			
		} else if (m[i].tension >= tensionAlta2){
			lugarTensionAlta2 = i;
			tensionAlta2 = m[i].tension;
		}
	}
	
	printf("\nLa tension mas alta la tiene %s y es de %d\n", m[lugarTensionAlta1].nombreMaquina, m[lugarTensionAlta1].tension);
	printf("La segunda tension mas alta la tiene %s y es de %d\n", m[lugarTensionAlta2].nombreMaquina, m[lugarTensionAlta2].tension);
	
}

void MaxCorriente(consumo *m, int c){
	int i;
	int lugarCorrienteAlta1 = 0;
	int lugarCorrienteAlta2 = 0;
	int corrienteAlta1 = 0;
	int corrienteAlta2 = 0;
	
	if (c == 0 || m == NULL) {
		printf("\nNo hay maquinas guardadas.\n");
		return;
	}
	
	for (i=0; i<c; i++){
		if (m[i].corriente >= corrienteAlta1){
			lugarCorrienteAlta2 = lugarCorrienteAlta1;
			corrienteAlta2 = corrienteAlta1;
			
			lugarCorrienteAlta1 = i;
			corrienteAlta1 = m[i].corriente;
		} else if (m[i].corriente >= corrienteAlta2){
			lugarCorrienteAlta2 = i;
			corrienteAlta2 = m[i].corriente;
		}
	}
	
	printf("\nLa corriente mas alta la tiene %s y es de %d\n", m[lugarCorrienteAlta1].nombreMaquina, m[lugarCorrienteAlta1].corriente);
	printf("La segunda corriente mas alta la tiene %s y es de %d\n", m[lugarCorrienteAlta2].nombreMaquina, m[lugarCorrienteAlta2].corriente);
	
}

void BuscarMaquina(consumo *m, int c){
	int i = 0;
	char buscado[31];
	int encontrado = 0;
	
	if (c == 0 || m == NULL) {
		printf("\nNo hay maquinas guardadas.\n");
		return;
	}
	
	printf("\nIngrese el nombre de la maquina a buscar: ");
	fgets(buscado, 31, stdin);
	
	buscado[strlen(buscado)-1] = '\0';
	printf("Buscando: %s", buscado);
	for (i = 0; i < c; i++) {
		printf(".");
		if (strcmp(m[i].nombreMaquina, buscado) == 0) {
			printf("\nEncontrado: \n");
			printf("%s - Tension: %d - Corriente: %d - Posicion: %d\n", m[i].nombreMaquina, m[i].tension, m[i].corriente, i + 1);
			encontrado = 1;
		}
	}
	
	if (!encontrado) {
		printf("\nNo se encontro ninguna maquina llamada: %s\n", buscado);
		return;
	}
}

void LimpiarBuffer(){
	rewind(stdin);
}
