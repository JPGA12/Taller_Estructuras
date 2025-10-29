#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "estructuras.h"

// Colores para output
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

// Contadores globales para estadísticas
int tests_passed = 0;
int tests_failed = 0;
int total_tests = 0;

// Macro para test assertion
#define ASSERT_TEST(condition, test_name) do { \
    total_tests++; \
    if (condition) { \
        printf(GREEN "✓ PASS: " RESET "%s\n", test_name); \
        tests_passed++; \
    } else { \
        printf(RED "✗ FAIL: " RESET "%s\n", test_name); \
        tests_failed++; \
    } \
} while(0)

// Funciones auxiliares para verificar estructuras
int verificar_cola_vacia(cola *c) {
    return c->inicio == NULL && c->fin == NULL && length(c) == 0;
}

int verificar_pila_vacia(pila *p) {
    return p->cima == NULL && p->base == NULL && lengthPila(p) == 0;
}

int verificar_lista_vacia(listaDoble *l) {
    return l->inicio == NULL && l->fin == NULL;
}

int verificar_orden_lista(listaDoble *lista) {
    if (lista->inicio == NULL) return 1;
    
    nodoLista *actual = lista->inicio;
    while (actual->nodoSiguiente != NULL) {
        if (actual->id > actual->nodoSiguiente->id) {
            return 0; // No está ordenada
        }
        actual = actual->nodoSiguiente;
    }
    return 1; // Está ordenada
}

int contar_elementos_lista(listaDoble *lista) {
    int count = 0;
    nodoLista *actual = lista->inicio;
    while (actual != NULL) {
        count++;
        actual = actual->nodoSiguiente;
    }
    return count;
}

// ========================= TESTS PARA COLA =========================
void test_cola_crear() {
    printf(BLUE "\n--- TESTING COLA ---\n" RESET);
    
    cola *c = crearCola();
    ASSERT_TEST(c != NULL, "Crear cola - memoria asignada");
    ASSERT_TEST(verificar_cola_vacia(c), "Cola recién creada está vacía");
    
    free(c);
}

void test_cola_encolar_un_elemento() {
    cola *c = crearCola();
    nodo *n = crearNodo(10);
    
    encolar(c, n);
    
    ASSERT_TEST(c->inicio == n, "Inicio apunta al nodo encolado");
    ASSERT_TEST(c->fin == n, "Fin apunta al nodo encolado");
    ASSERT_TEST(length(c) == 1, "Tamaño de cola es 1");
    ASSERT_TEST(c->inicio->dato == 10, "Dato correcto en el nodo");
    
    free(c);
}

void test_cola_encolar_multiples_elementos() {
    cola *c = crearCola();
    
    // Encolar 5, 10, 15
    nodo *n1 = crearNodo(5);
    nodo *n2 = crearNodo(10);
    nodo *n3 = crearNodo(15);
    
    encolar(c, n1);
    encolar(c, n2);
    encolar(c, n3);
    
    ASSERT_TEST(length(c) == 3, "Tamaño correcto después de encolar 3 elementos");
    ASSERT_TEST(c->inicio->dato == 5, "Primer elemento correcto (FIFO)");
    ASSERT_TEST(c->fin->dato == 15, "Último elemento correcto");
    
    // Verificar orden FIFO
    ASSERT_TEST(c->inicio->nodoSiguiente->dato == 10, "Segundo elemento correcto");
    ASSERT_TEST(c->inicio->nodoSiguiente->nodoSiguiente->dato == 15, "Tercer elemento correcto");
    
    free(c);
}

void test_cola_descolar() {
    cola *c = crearCola();
    
    // Llenar cola
    nodo *n1 = crearNodo(1);
    nodo *n2 = crearNodo(2);
    nodo *n3 = crearNodo(3);
    
    encolar(c, n1);
    encolar(c, n2);
    encolar(c, n3);
    
    // Descolar primer elemento
    descolar(c);
    ASSERT_TEST(length(c) == 2, "Tamaño después de descolar");
    ASSERT_TEST(c->inicio->dato == 2, "Nuevo primer elemento después de descolar");
    
    // Descolar segundo elemento
    descolar(c);
    ASSERT_TEST(length(c) == 1, "Tamaño después de segundo descolar");
    ASSERT_TEST(c->inicio->dato == 3, "Elemento restante correcto");
    
    // Descolar último elemento
    descolar(c);
    ASSERT_TEST(verificar_cola_vacia(c), "Cola vacía después de descolar todos");
    
    free(c);
}

void test_cola_descolar_vacia() {
    cola *c = crearCola();
    
    // Capturar salida para verificar mensaje de error
    printf("Esperando mensaje de cola vacía: ");
    descolar(c); // Debería imprimir "LA COLA ESTÁ VACÍA"
    
    ASSERT_TEST(verificar_cola_vacia(c), "Cola sigue vacía después de intentar descolar");
    
    free(c);
}

// ========================= TESTS PARA PILA =========================
void test_pila_crear() {
    printf(BLUE "\n--- TESTING PILA ---\n" RESET);
    
    pila *p = crearPila();
    ASSERT_TEST(p != NULL, "Crear pila - memoria asignada");
    ASSERT_TEST(verificar_pila_vacia(p), "Pila recién creada está vacía");
    
    free(p);
}

void test_pila_apilar_un_elemento() {
    pila *p = crearPila();
    nodoPila *n = crearNodoPila(20);
    
    apilar(p, n);
    
    ASSERT_TEST(p->cima == n, "Cima apunta al nodo apilado");
    ASSERT_TEST(p->base == n, "Base apunta al nodo apilado (primer elemento)");
    ASSERT_TEST(lengthPila(p) == 1, "Tamaño de pila es 1");
    ASSERT_TEST(p->cima->datoPila == 20, "Dato correcto en la cima");
    
    free(p);
}

void test_pila_apilar_multiples_elementos() {
    pila *p = crearPila();
    
    // Apilar 1, 2, 3
    nodoPila *n1 = crearNodoPila(1);
    nodoPila *n2 = crearNodoPila(2);
    nodoPila *n3 = crearNodoPila(3);
    
    apilar(p, n1);
    apilar(p, n2);
    apilar(p, n3);
    
    ASSERT_TEST(lengthPila(p) == 3, "Tamaño correcto después de apilar 3 elementos");
    ASSERT_TEST(p->cima->datoPila == 3, "Último elemento en la cima (LIFO)");
    ASSERT_TEST(p->base->datoPila == 1, "Primer elemento sigue siendo la base");
    
    // Verificar orden LIFO
    ASSERT_TEST(p->cima->siguienteNodoPila->datoPila == 2, "Segundo elemento desde la cima");
    ASSERT_TEST(p->cima->siguienteNodoPila->siguienteNodoPila->datoPila == 1, "Base accesible desde cima");
    
    free(p);
}

void test_pila_desapilar() {
    pila *p = crearPila();
    
    // Llenar pila
    nodoPila *n1 = crearNodoPila(10);
    nodoPila *n2 = crearNodoPila(20);
    nodoPila *n3 = crearNodoPila(30);
    
    apilar(p, n1);
    apilar(p, n2);
    apilar(p, n3);
    
    // Desapilar primer elemento (último agregado)
    desapilar(p);
    ASSERT_TEST(lengthPila(p) == 2, "Tamaño después de desapilar");
    ASSERT_TEST(p->cima->datoPila == 20, "Nueva cima después de desapilar");
    
    // Desapilar segundo elemento
    desapilar(p);
    ASSERT_TEST(lengthPila(p) == 1, "Tamaño después de segundo desapilar");
    ASSERT_TEST(p->cima->datoPila == 10, "Elemento restante correcto");
    ASSERT_TEST(p->cima == p->base, "Cima y base son el mismo cuando hay un elemento");
    
    // Desapilar último elemento
    desapilar(p);
    ASSERT_TEST(verificar_pila_vacia(p), "Pila vacía después de desapilar todos");
    
    free(p);
}

void test_pila_desapilar_vacia() {
    pila *p = crearPila();
    
    printf("Esperando mensaje de pila vacía: ");
    desapilar(p); // Debería imprimir "LA PILA ESTA VACIA"
    
    ASSERT_TEST(verificar_pila_vacia(p), "Pila sigue vacía después de intentar desapilar");
    
    free(p);
}

// ========================= TESTS PARA LISTA DOBLE =========================
void test_lista_crear() {
    printf(BLUE "\n--- TESTING LISTA DOBLE ORDENADA ---\n" RESET);
    
    listaDoble *l = crearListaDoble();
    ASSERT_TEST(l != NULL, "Crear lista - memoria asignada");
    ASSERT_TEST(verificar_lista_vacia(l), "Lista recién creada está vacía");
    
    free(l);
}

void test_lista_agregar_un_elemento() {
    listaDoble *l = crearListaDoble();
    nodoLista *n = crearNodoLista(50);
    
    agregarOrdenadoDobles(l, n);
    
    ASSERT_TEST(l->inicio == n, "Inicio apunta al nodo agregado");
    ASSERT_TEST(l->fin == n, "Fin apunta al nodo agregado");
    ASSERT_TEST(contar_elementos_lista(l) == 1, "Tamaño de lista es 1");
    ASSERT_TEST(l->inicio->id == 50, "ID correcto en el nodo");
    
    free(l);
}

void test_lista_orden_ascendente() {
    listaDoble *l = crearListaDoble();
    
    // Agregar elementos en orden: 10, 20, 30
    nodoLista *n1 = crearNodoLista(20);
    nodoLista *n2 = crearNodoLista(10);
    nodoLista *n3 = crearNodoLista(30);
    
    agregarOrdenadoDobles(l, n1);
    agregarOrdenadoDobles(l, n2);
    agregarOrdenadoDobles(l, n3);
    
    ASSERT_TEST(contar_elementos_lista(l) == 3, "Tamaño correcto después de agregar 3 elementos");
    ASSERT_TEST(verificar_orden_lista(l), "Lista mantiene orden ascendente");
    ASSERT_TEST(l->inicio->id == 10, "Menor elemento al inicio");
    ASSERT_TEST(l->fin->id == 30, "Mayor elemento al final");
    
    // Verificar orden completo
    nodoLista *actual = l->inicio;
    ASSERT_TEST(actual->id == 10, "Primer elemento: 10");
    actual = actual->nodoSiguiente;
    ASSERT_TEST(actual->id == 20, "Segundo elemento: 20");
    actual = actual->nodoSiguiente;
    ASSERT_TEST(actual->id == 30, "Tercer elemento: 30");
    
    free(l);
}

void test_lista_elementos_duplicados() {
    listaDoble *l = crearListaDoble();
    
    // Agregar elementos duplicados
    nodoLista *n1 = crearNodoLista(15);
    nodoLista *n2 = crearNodoLista(15);
    nodoLista *n3 = crearNodoLista(15);
    
    agregarOrdenadoDobles(l, n1);
    agregarOrdenadoDobles(l, n2);
    agregarOrdenadoDobles(l, n3);
    
    ASSERT_TEST(contar_elementos_lista(l) == 3, "Acepta elementos duplicados");
    ASSERT_TEST(verificar_orden_lista(l), "Mantiene orden con duplicados");
    
    free(l);
}

void test_lista_insercion_compleja() {
    listaDoble *l = crearListaDoble();
    
    // Agregar elementos desordenados: 50, 25, 75, 12, 37, 62, 87
    int valores[] = {50, 25, 75, 12, 37, 62, 87};
    int n_valores = sizeof(valores) / sizeof(valores[0]);
    
    for (int i = 0; i < n_valores; i++) {
        nodoLista *n = crearNodoLista(valores[i]);
        agregarOrdenadoDobles(l, n);
    }
    
    ASSERT_TEST(contar_elementos_lista(l) == n_valores, "Todos los elementos agregados");
    ASSERT_TEST(verificar_orden_lista(l), "Lista mantiene orden después de inserciones complejas");
    
    // Verificar orden final esperado: 12, 25, 37, 50, 62, 75, 87
    int orden_esperado[] = {12, 25, 37, 50, 62, 75, 87};
    nodoLista *actual = l->inicio;
    
    for (int i = 0; i < n_valores; i++) {
        char test_name[50];
        sprintf(test_name, "Posición %d tiene valor %d", i, orden_esperado[i]);
        ASSERT_TEST(actual != NULL && actual->id == orden_esperado[i], test_name);
        if (actual) actual = actual->nodoSiguiente;
    }
    
    free(l);
}

void test_lista_enlaces_bidireccionales() {
    listaDoble *l = crearListaDoble();
    
    // Agregar 3 elementos
    nodoLista *n1 = crearNodoLista(1);
    nodoLista *n2 = crearNodoLista(2);
    nodoLista *n3 = crearNodoLista(3);
    
    agregarOrdenadoDobles(l, n2); // Agregar 2 primero
    agregarOrdenadoDobles(l, n1); // Agregar 1 (debería ir al inicio)
    agregarOrdenadoDobles(l, n3); // Agregar 3 (debería ir al final)
    
    // Verificar enlaces hacia adelante
    ASSERT_TEST(l->inicio->nodoSiguiente != NULL, "Primer nodo tiene siguiente");
    ASSERT_TEST(l->inicio->nodoSiguiente->id == 2, "Enlace hacia adelante correcto");
    
    // Verificar enlaces hacia atrás
    ASSERT_TEST(l->fin->nodoAnterior != NULL, "Último nodo tiene anterior");
    ASSERT_TEST(l->fin->nodoAnterior->id == 2, "Enlace hacia atrás correcto");
    
    // Verificar que el primer nodo no tiene anterior
    ASSERT_TEST(l->inicio->nodoAnterior == NULL, "Primer nodo no tiene anterior");
    
    // Verificar que el último nodo no tiene siguiente
    ASSERT_TEST(l->fin->nodoSiguiente == NULL, "Último nodo no tiene siguiente");
    
    free(l);
}

// ========================= TESTS DE INTEGRACIÓN =========================
void test_integracion_estructuras() {
    printf(BLUE "\n--- TESTING INTEGRACIÓN ---\n" RESET);
    
    cola *c = crearCola();
    pila *p = crearPila();
    listaDoble *l = crearListaDoble();
    
    // Agregar los mismos datos a todas las estructuras
    int datos[] = {5, 2, 8, 1, 9};
    int n_datos = sizeof(datos) / sizeof(datos[0]);
    
    for (int i = 0; i < n_datos; i++) {
        // Agregar a cola
        nodo *nCola = crearNodo(datos[i]);
        encolar(c, nCola);
        
        // Agregar a pila
        nodoPila *nPila = crearNodoPila(datos[i]);
        apilar(p, nPila);
        
        // Agregar a lista
        nodoLista *nLista = crearNodoLista(datos[i]);
        agregarOrdenadoDobles(l, nLista);
    }
    
    ASSERT_TEST(length(c) == n_datos, "Cola tiene todos los elementos");
    ASSERT_TEST(lengthPila(p) == n_datos, "Pila tiene todos los elementos");
    ASSERT_TEST(contar_elementos_lista(l) == n_datos, "Lista tiene todos los elementos");
    
    // Verificar que cada estructura mantiene su comportamiento
    ASSERT_TEST(c->inicio->dato == 5, "Cola mantiene FIFO - primer elemento");
    ASSERT_TEST(p->cima->datoPila == 9, "Pila mantiene LIFO - último elemento en cima");
    ASSERT_TEST(verificar_orden_lista(l), "Lista mantiene orden ascendente");
    ASSERT_TEST(l->inicio->id == 1, "Lista - menor elemento al inicio");
    ASSERT_TEST(l->fin->id == 9, "Lista - mayor elemento al final");
    
    free(c);
    free(p);
    free(l);
}

// ========================= FUNCIÓN PRINCIPAL DE TESTS =========================
void mostrar_estadisticas() {
    printf(YELLOW "\n====== ESTADÍSTICAS DE PRUEBAS ======\n" RESET);
    printf("Total de pruebas: %d\n", total_tests);
    printf(GREEN "Pruebas exitosas: %d\n" RESET, tests_passed);
    printf(RED "Pruebas fallidas: %d\n" RESET, tests_failed);
    
    if (tests_failed == 0) {
        printf(GREEN "🎉 ¡TODAS LAS PRUEBAS PASARON! 🎉\n" RESET);
    } else {
        printf(RED "❌ Hay %d pruebas que fallaron\n" RESET, tests_failed);
    }
    
    double porcentaje = (double)tests_passed / total_tests * 100;
    printf("Porcentaje de éxito: %.1f%%\n", porcentaje);
    printf("=====================================\n");
}

int main() {
    printf(BLUE "🔬 INICIANDO SUITE DE PRUEBAS - ESTRUCTURAS DE DATOS\n" RESET);
    printf("=====================================================\n");
    
    // Tests para Cola
    test_cola_crear();
    test_cola_encolar_un_elemento();
    test_cola_encolar_multiples_elementos();
    test_cola_descolar();
    test_cola_descolar_vacia();
    
    // Tests para Pila
    test_pila_crear();
    test_pila_apilar_un_elemento();
    test_pila_apilar_multiples_elementos();
    test_pila_desapilar();
    test_pila_desapilar_vacia();
    
    // Tests para Lista Doble
    test_lista_crear();
    test_lista_agregar_un_elemento();
    test_lista_orden_ascendente();
    test_lista_elementos_duplicados();
    test_lista_insercion_compleja();
    test_lista_enlaces_bidireccionales();
    
    // Tests de integración
    test_integracion_estructuras();
    
    // Mostrar estadísticas finales
    mostrar_estadisticas();
    
    return tests_failed == 0 ? 0 : 1;
}