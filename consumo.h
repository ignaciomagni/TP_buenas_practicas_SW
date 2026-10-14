#ifndef CONSUMO_H
#define CONSUMO_H

#define MAX_NOMBRE 31
#define OPCION_SALIR 5

// Definicion de la estructura para el relevamiento de consumo eléctrico
typedef struct {
	char nombreMaquina[31];
	int tension;
	int corriente;
} consumo;

/**
 * Muestra el menu principal de opciones en pantalla.
 */
void MostrarMenu();

/**
* Ingresa una nueva máquina utilizando memoria dinámica.
* @param m Puntero al arreglo dinámico de consumos.
* @param c Puntero a la cantidad actual de máquinas registradas.
* @return Puntero actualizado al arreglo de consumos.
*/
consumo* IngresarDatos(consumo *m, int *c);

/**
* Imprime en pantalla las 2 tensiones más altas y sus máquinas correspondientes.
* @param m Puntero al arreglo de consumos.
* @param c Cantidad total de máquinas.
*/
void MaxTension(consumo *m, int c);

/**
* Imprime en pantalla las 2 corrientes más altas y sus máquinas correspondientes.
* @param m Puntero al arreglo de consumos.
* @param c Cantidad total de máquinas.
*/
void MaxCorriente(consumo *m, int c);

/**
* Busca una máquina por su nombre utilizando operaciones de cadenas.
* @param m Puntero al arreglo de consumos.
* @param c Cantidad total de máquinas.
*/
void BuscarMaquina(consumo *m, int c);

/**
* Limpia el búfer de entrada estándar.
*/
void LimpiarBuffer();

#endif // CONSUMO_H
