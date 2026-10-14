#ifndef CONSUMO_H
#define CONSUMO_H

#define MAX_NOMBRE 31
#define OPCION_SALIR 5

typedef struct {
	char nombreMaquina[31];
	int tension;
	int corriente;
} consumo;

void MostrarMenu();
consumo* IngresarDatos(consumo *m, int *c);
void MaxTension(consumo *m, int c);
void MaxCorriente(consumo *m, int c);
void BuscarMaquina(consumo *m, int c);
void LimpiarBuffer();

#endif // CONSUMO_H
