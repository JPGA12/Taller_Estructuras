#include <stdio.h>
#include <malloc.h>


typedef struct nodo {
    int dato;
    struct nodo *nodoSiguiente;
} nodo;

typedef struct cola {
    struct nodo *inicio;
    struct nodo *fin;
} cola;

cola *crearCola() {
    struct cola *nuevaCola = malloc(sizeof(cola));
    nuevaCola->inicio = NULL;
    nuevaCola->fin = NULL;
    return nuevaCola;
}

nodo *crearNodo(int dato) {
    struct nodo *nuevoNodo = malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->nodoSiguiente = NULL;
    return nuevoNodo;
}

void eliminarNodoMemoria(nodo *nodo) {
    nodo->nodoSiguiente = NULL;
    free(nodo);
}

void encolar(cola *cola, nodo *nuevoNodo) {
    if (cola->inicio == NULL) {
        cola->inicio = nuevoNodo;
        cola->fin = nuevoNodo;
    } else {
        cola->fin->nodoSiguiente = nuevoNodo;
        cola->fin = nuevoNodo;
    }
}

void descolar(cola *cola) {
    if (cola->inicio != NULL) {
        nodo *nodoDescolar = cola->inicio;
        cola->inicio = cola->inicio->nodoSiguiente;
        eliminarNodoMemoria(nodoDescolar);
        if (cola->inicio == NULL) {
            cola->fin = NULL;
        }
    } else {
        puts("LA COLA ESTÁ VACÍA");
    }
}


typedef struct nodoPila {
    int datoPila;
    struct nodoPila *siguienteNodoPila;
} nodoPila;

typedef struct pila {
    struct nodoPila *cima;
    struct nodoPila *base;
} pila;

nodoPila *crearNodoPila(int datoPila) {
    struct nodoPila *nuevoNodoPila = malloc(sizeof(nodoPila));
    nuevoNodoPila->datoPila = datoPila;
    nuevoNodoPila->siguienteNodoPila = NULL;
    return nuevoNodoPila;
}

pila *crearPila() {
    struct pila *nuevaPila = malloc(sizeof(pila));
    nuevaPila->cima = NULL;
    nuevaPila->base = NULL;
    return nuevaPila;
}

void eliminarNodoMemoriaPila(nodoPila *nodoPila) {
    nodoPila->siguienteNodoPila = NULL;
    free(nodoPila);
}

void apilar(pila *pila, nodoPila *nuevoNodoPila) {
    if (pila->cima == NULL) {
        pila->cima = nuevoNodoPila;
        pila->base = nuevoNodoPila;
    } else {
        nuevoNodoPila->siguienteNodoPila = pila->cima;
        pila->cima = nuevoNodoPila;
    }
}

void desapilar(pila *pila) {
    if (pila->cima != NULL) {
        nodoPila *nodoEliminarPila = pila->cima;
        pila->cima = nodoEliminarPila->siguienteNodoPila;
        eliminarNodoMemoriaPila(nodoEliminarPila);

        if (pila->cima == NULL) {
            pila->base = NULL;
        }
    } else {
        printf("LA PILA ESTA VACIA");
    }
}


typedef struct nodoLista {
    int id;
    struct nodoLista *nodoSiguiente;
    struct nodoLista *nodoAnterior;
} nodoLista;

typedef struct listaDoble {
    struct nodoLista *inicio;
    struct nodoLista *fin;
} listaDoble;

listaDoble *crearListaDoble() {
    struct listaDoble *nuevaLista = malloc(sizeof(listaDoble));
    nuevaLista->inicio = NULL;
    nuevaLista->fin = NULL;
    return nuevaLista;
}

nodoLista *crearNodoLista(int id) {
    struct nodoLista *nuevoNodo = malloc(sizeof(nodoLista));
    nuevoNodo->id = id;
    nuevoNodo->nodoSiguiente = NULL;
    nuevoNodo->nodoAnterior = NULL;
    return nuevoNodo;
}

void agregarOrdenadoDobles(listaDoble *lista, nodoLista *nuevoNodo) {
    if (lista->inicio != NULL) {
        if (lista->inicio->id >= nuevoNodo->id) {
            nuevoNodo->nodoSiguiente = lista->inicio;
            lista->inicio = nuevoNodo;
        } else if (lista->fin->id <= nuevoNodo->id) {
            lista->fin->nodoSiguiente = nuevoNodo;
            nuevoNodo->nodoAnterior = lista->fin;
            lista->fin = nuevoNodo;
        } else {
            struct nodoLista *nodoTemporal = lista->inicio;
            while (nodoTemporal != NULL) {
                if (nuevoNodo->id <= nodoTemporal->id) {
                    nuevoNodo->nodoAnterior = nodoTemporal->nodoAnterior;
                    nuevoNodo->nodoSiguiente = nodoTemporal;
                    nodoTemporal->nodoAnterior = nuevoNodo;
                    nuevoNodo->nodoAnterior->nodoSiguiente = nuevoNodo;
                    break;
                } else {
                    nodoTemporal = nodoTemporal->nodoSiguiente;
                }
            }
        }
    } else {
        lista->inicio = nuevoNodo;
        lista->fin = nuevoNodo;
    }
}


int length(cola *cola) {
    int cont = 0;
    nodo *nodoTemporalCola = cola->inicio;

    while (nodoTemporalCola != NULL) {
        cont++;
        nodoTemporalCola = nodoTemporalCola->nodoSiguiente;
    }
    return cont;
}

int lengthPila(pila *pila) {
    int cont = 0;
    nodoPila *nodoTemporalPila = pila->cima;

    while (nodoTemporalPila != NULL) {
        cont++;
        nodoTemporalPila = nodoTemporalPila->siguienteNodoPila;
    }
    return cont;
}

int main() {
    int opc = 0;
    printf("SELECCIONE QUE ESTRUCTURA VA A CREAR \n 1. COLA\n 2. PILA \n 3. SALIR \n");
    scanf("%i", &opc);

    if (opc == 1) {
        struct cola *cola = crearCola();
        struct pila *pila = crearPila();
        struct listaDoble *listaDoble = crearListaDoble();
        do {
            printf("SELECCIONE UNA OPCION \n 1. AGREGAR DATOS \n 2. SELECIONAR CONVERSION \n 3. VER COLA \n 4. SALIR \n");
            scanf("%i", &opc);
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
                nodoPila *nodoTemporalPila = pila->cima;
                nodoLista *nodoTemporalDoble = listaDoble->inicio;

                printf("Seleccion la estructura a migrar la cola: \n1. PILA \n2. LISTA  \n");
                scanf("%i", &estructuraMigrar);


                if (estructuraMigrar == 1) {
                    printf("PILA: \n");
                    nodoPila *nodoTemporal = pila->cima;
                    while (nodoTemporal != NULL) {
                        printf(" |  %i  | \n", nodoTemporal->datoPila);
                        nodoTemporal = nodoTemporal->siguienteNodoPila;
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
                printf("NUMERO DE ELEMENTOS: %i\n", length(cola));
                nodo *nodoTemporal = cola->inicio;
                while (nodoTemporal != NULL) {
                    printf(" |  %i  | \n", nodoTemporal->dato);
                    nodoTemporal = nodoTemporal->nodoSiguiente;
                }
                printf("\n");
            }
        } while (opc != 4);

    }


    if (opc == 2) {
        struct cola *cola = crearCola();
        struct pila *pila = crearPila();
        struct listaDoble *listaDoble = crearListaDoble();
        do {
            printf("SELECCIONE UNA OPCION \n 1. AGREGAR DATOS \n 2. SELECIONAR CONVERSION \n 3. VER PILA \n 4. SALIR \n");
            scanf("%i", &opc);
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
                nodoPila *nodoTemporalPila = pila->cima;
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


    }
    return 0;
}
1