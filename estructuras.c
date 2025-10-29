#include "estructuras.h"

// ========================= FUNCIONES PARA COLA =========================

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

int length(cola *cola) {
    int cont = 0;
    nodo *nodoTemporalCola = cola->inicio;

    while (nodoTemporalCola != NULL) {
        cont++;
        nodoTemporalCola = nodoTemporalCola->nodoSiguiente;
    }
    return cont;
}

// ========================= FUNCIONES PARA PILA =========================

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

int lengthPila(pila *pila) {
    int cont = 0;
    nodoPila *nodoTemporalPila = pila->cima;

    while (nodoTemporalPila != NULL) {
        cont++;
        nodoTemporalPila = nodoTemporalPila->siguienteNodoPila;
    }
    return cont;
}

// ========================= FUNCIONES PARA LISTA DOBLE =========================

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
            lista->inicio->nodoAnterior = nuevoNodo;
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
                    nodoTemporal->nodoAnterior->nodoSiguiente = nuevoNodo;
                    nodoTemporal->nodoAnterior = nuevoNodo;
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

// ========================= FUNCIONES PARA LIBERAR MEMORIA =========================

void liberarCola(cola *cola) {
    if (cola == NULL) return;
    
    while (cola->inicio != NULL) {
        nodo *temp = cola->inicio;
        cola->inicio = cola->inicio->nodoSiguiente;
        free(temp);
    }
    free(cola);
}

void liberarPila(pila *pila) {
    if (pila == NULL) return;
    
    while (pila->cima != NULL) {
        nodoPila *temp = pila->cima;
        pila->cima = pila->cima->siguienteNodoPila;
        free(temp);
    }
    free(pila);
}

void liberarListaDoble(listaDoble *lista) {
    if (lista == NULL) return;
    
    while (lista->inicio != NULL) {
        nodoLista *temp = lista->inicio;
        lista->inicio = lista->inicio->nodoSiguiente;
        free(temp);
    }
    free(lista);
}