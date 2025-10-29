#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <stdio.h>
#include <stdlib.h>

// Definición de estructuras para Cola
typedef struct nodo {
    int dato;
    struct nodo *nodoSiguiente;
} nodo;

typedef struct cola {
    struct nodo *inicio;
    struct nodo *fin;
} cola;

// Definición de estructuras para Pila
typedef struct nodoPila {
    int datoPila;
    struct nodoPila *siguienteNodoPila;
} nodoPila;

typedef struct pila {
    struct nodoPila *cima;
    struct nodoPila *base;
} pila;

// Definición de estructuras para Lista Doble
typedef struct nodoLista {
    int id;
    struct nodoLista *nodoSiguiente;
    struct nodoLista *nodoAnterior;
} nodoLista;

typedef struct listaDoble {
    struct nodoLista *inicio;
    struct nodoLista *fin;
} listaDoble;

// Funciones para Cola
cola *crearCola();
nodo *crearNodo(int dato);
void eliminarNodoMemoria(nodo *nodo);
void encolar(cola *cola, nodo *nuevoNodo);
void descolar(cola *cola);
int length(cola *cola);

// Funciones para Pila
pila *crearPila();
nodoPila *crearNodoPila(int datoPila);
void eliminarNodoMemoriaPila(nodoPila *nodoPila);
void apilar(pila *pila, nodoPila *nuevoNodoPila);
void desapilar(pila *pila);
int lengthPila(pila *pila);

// Funciones para Lista Doble
listaDoble *crearListaDoble();
nodoLista *crearNodoLista(int id);
void agregarOrdenadoDobles(listaDoble *lista, nodoLista *nuevoNodo);

// Funciones para liberar memoria
void liberarCola(cola *cola);
void liberarPila(pila *pila);
void liberarListaDoble(listaDoble *lista);

#endif