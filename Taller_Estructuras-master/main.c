#include "estructuras.h"

int main() {
    int opc = 0;
    
    printf("========================================\n");
    printf("    ESTRUCTURAS DE DATOS EN C\n");
    printf("========================================\n");
    printf("SELECCIONE QUE ESTRUCTURA VA A CREAR:\n");
    printf(" 1. COLA (FIFO)\n");
    printf(" 2. PILA (LIFO)\n");
    printf(" 3. SALIR\n");
    printf("Opción: ");
    
    if (scanf("%i", &opc) != 1) {
        printf("Error: Entrada inválida\n");
        return 1;
    }

    if (opc == 1) {
        struct cola *cola = crearCola();
        struct pila *pila = crearPila();
        struct listaDoble *listaDoble = crearListaDoble();
        
        printf("\n=== MODO COLA (FIFO) ===\n");
        
        do {
            printf("\nSELECCIONE UNA OPCION:\n");
            printf(" 1. AGREGAR DATOS\n");
            printf(" 2. VER CONVERSIONES\n");
            printf(" 3. VER COLA\n");
            printf(" 4. SALIR\n");
            printf("Opción: ");
            
            if (scanf("%i", &opc) != 1) {
                printf("Error: Entrada inválida\n");
                break;
            }
            if (opc == 1) {
                int dato = 0;
                printf("\nINGRESE EL DATO DEL NODO: ");
                
                if (scanf("%i", &dato) != 1) {
                    printf("Error: Entrada inválida\n");
                    continue;
                }

                nodo *nuevoNodo = crearNodo(dato);
                encolar(cola, nuevoNodo);

                nodoPila *nodoPila = crearNodoPila(dato);
                apilar(pila, nodoPila);

                nodoLista *nodoLista = crearNodoLista(dato);
                agregarOrdenadoDobles(listaDoble, nodoLista);

                printf("✓ Dato %d agregado a todas las estructuras\n", dato);
            }
            if (opc == 2) {
                int estructuraMigrar = 0;
                nodoLista *nodoTemporalDoble = listaDoble->inicio;

                printf("\nSeleccione la estructura para mostrar conversión:\n");
                printf(" 1. VER COMO PILA (LIFO)\n");
                printf(" 2. VER COMO LISTA ORDENADA\n");
                printf("Opción: ");
                
                if (scanf("%i", &estructuraMigrar) != 1) {
                    printf("Error: Entrada inválida\n");
                    continue;
                }


                if (estructuraMigrar == 1) {
                    printf("\n=== VISTA COMO PILA (LIFO) ===\n");
                    nodoPila *nodoTemporal = pila->cima;
                    if (nodoTemporal == NULL) {
                        printf("La pila está vacía\n");
                    } else {
                        printf("Elementos (del más reciente al más antiguo):\n");
                        while (nodoTemporal != NULL) {
                            printf(" |  %i  |\n", nodoTemporal->datoPila);
                            nodoTemporal = nodoTemporal->siguienteNodoPila;
                        }
                    }
                } else if (estructuraMigrar == 2) {
                    printf("\n=== VISTA COMO LISTA ORDENADA ===\n");
                    if (nodoTemporalDoble == NULL) {
                        printf("La lista está vacía\n");
                    } else {
                        printf("Elementos (en orden ascendente):\n");
                        while (nodoTemporalDoble != NULL) {
                            printf(" |  %i  |\n", nodoTemporalDoble->id);
                            nodoTemporalDoble = nodoTemporalDoble->nodoSiguiente;
                        }
                    }
                } else {
                    printf("Opción inválida\n");
                }

            }

            if (opc == 3) {
                printf("\n=== CONTENIDO DE LA COLA (FIFO) ===\n");
                printf("Número de elementos: %i\n", length(cola));
                
                nodo *nodoTemporal = cola->inicio;
                if (nodoTemporal == NULL) {
                    printf("La cola está vacía\n");
                } else {
                    printf("Elementos (del primero al último):\n");
                    while (nodoTemporal != NULL) {
                        printf(" |  %i  |\n", nodoTemporal->dato);
                        nodoTemporal = nodoTemporal->nodoSiguiente;
                    }
                }
                printf("\n");
            }
        } while (opc != 4);

        // Liberar memoria antes de salir
        liberarCola(cola);
        liberarPila(pila);
        liberarListaDoble(listaDoble);
    } else if (opc == 2) {
        struct cola *cola = crearCola();
        struct pila *pila = crearPila();
        struct listaDoble *listaDoble = crearListaDoble();
        
        printf("\n=== MODO PILA (LIFO) ===\n");
        
        do {
            printf("\nSELECCIONE UNA OPCION:\n");
            printf(" 1. AGREGAR DATOS\n");
            printf(" 2. VER CONVERSIONES\n");
            printf(" 3. VER PILA\n");
            printf(" 4. SALIR\n");
            printf("Opción: ");
            
            if (scanf("%i", &opc) != 1) {
                printf("Error: Entrada inválida\n");
                break;
            }
            if (opc == 1) {
                int dato = 0;
                printf("INGRESE EL DATO DEL NODO \n");
                scanf("%i", &dato);

                nodo *nuevoNodo = crearNodo(dato);
                encolar(cola, nuevoNodo);

                nodoPila *nodoPila = crearNodoPila(dato);
                apilar(pila, nodoPila);

                nodoLista *nodoLista = crearNodoLista(dato);
                agregarOrdenadoDobles(listaDoble, nodoLista);

            }
            if (opc == 2) {
                int estructuraMigrar = 0;
                nodoLista *nodoTemporalDoble = listaDoble->inicio;

                printf("Seleccion la estructura a migrar la pila: \n1. COLA \n2. LISTA  \n");
                scanf("%i", &estructuraMigrar);


                if (estructuraMigrar == 1) {
                    printf("COLA: \n");
                    nodo *nodoTemporal = cola->inicio;
                    while (nodoTemporal != NULL) {
                        printf(" |  %i  | \n", nodoTemporal->dato);
                        nodoTemporal = nodoTemporal->nodoSiguiente;
                    }
                } else if (estructuraMigrar == 2) {

                    printf("LISTA ORDENADA: \n");
                    while (nodoTemporalDoble != NULL) {
                        printf(" |  %i  | \n", nodoTemporalDoble->id);
                        nodoTemporalDoble = nodoTemporalDoble->nodoSiguiente;
                    }

                }

            }

            if (opc == 3) {
                printf("NUMERO DE ELEMENTOS: %i\n", lengthPila(pila));
                nodoPila *nodoTemporalPila = pila->cima;
                while (nodoTemporalPila != NULL) {
                    printf(" |  %i  | \n", nodoTemporalPila->datoPila);
                    nodoTemporalPila = nodoTemporalPila->siguienteNodoPila;
                }
                printf("\n");
            }
        } while (opc != 4);

        // Liberar memoria antes de salir
        liberarCola(cola);
        liberarPila(pila);
        liberarListaDoble(listaDoble);
    }
    return 0;
}