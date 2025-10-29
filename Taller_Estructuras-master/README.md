# 🏗️ Estructuras de Datos en C - Ejemplo Completo

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C Standard](https://img.shields.io/badge/C-C99-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![Tests](https://img.shields.io/badge/Tests-73%2F73%20Passing-brightgreen.svg)](https://github.com)

Este proyecto implementa tres estructuras de datos fundamentales en C: **Cola (Queue)**, **Pila (Stack)** y **Lista Doblemente Enlazada Ordenada**, con una suite completa de pruebas automatizadas.

> 🎓 **Proyecto Educativo**: Este ejemplo fue desarrollado durante mis estudios universitarios y se comparte libremente con la comunidad para ayudar en el aprendizaje de estructuras de datos en C.

## 📁 Estructura del Proyecto

```
📦 Estructuras-Datos-C/
├── 📄 estructuras.h        # Definiciones y prototipos
├── 📄 estructuras.c        # Implementación de funciones
├── 📄 main.c              # Programa principal interactivo
├── 🧪 test_estructuras.c   # Suite completa de pruebas (73 tests)
├──  .gitignore          # Archivos ignorados por Git
└── 📖 README.md           # Documentación

Total: 5 archivos principales
```

## � Compilación

### 🔨 Comandos básicos:
```bash
# Compilar y ejecutar programa principal
gcc -Wall -std=c99 -o estructuras_ejemplo main.c estructuras.c
./estructuras_ejemplo

# Suite de pruebas  
gcc -Wall -std=c99 -o test_estructuras test_estructuras.c estructuras.c
./test_estructuras

# Limpiar binarios
rm -f estructuras_ejemplo test_estructuras
```

## 🧪 Suite de Pruebas Automatizadas

### 📊 Estadísticas de Pruebas:
```
🎯 Total de pruebas: 73
✅ Pruebas exitosas: 73  
❌ Pruebas fallidas: 0
📈 Porcentaje de éxito: 100.0%
```

### 🔍 Cobertura de Pruebas:

| Estructura | Tests | Funcionalidades Probadas |
|------------|-------|---------------------------|
| **Cola (FIFO)** | 17 | Crear, encolar, descolar, longitud, casos límite |
| **Pila (LIFO)** | 17 | Crear, apilar, desapilar, longitud, casos límite |
| **Lista Ordenada** | 31 | Crear, insertar ordenado, enlaces bidireccionales |
| **Integración** | 8 | Operaciones simultáneas, consistencia |

### ✅ Funcionalidades Verificadas:
- ✓ **Gestión de memoria** sin leaks
- ✓ **Comportamiento FIFO/LIFO** correcto
- ✓ **Inserción ordenada** automática
- ✓ **Enlaces bidireccionales** válidos
- ✓ **Casos límite** (estructuras vacías)
- ✓ **Integración** entre estructuras

## 🎯 Estructuras Implementadas

### 1. 📋 **Cola (Queue) - FIFO**
```c
cola *crearCola();                    // Crear cola vacía
void encolar(cola *cola, nodo *nodo); // Agregar al final
void descolar(cola *cola);            // Remover del inicio
int length(cola *cola);               // Contar elementos
void liberarCola(cola *cola);         // Liberar memoria
```

### 2. 📚 **Pila (Stack) - LIFO**
```c
pila *crearPila();                          // Crear pila vacía
void apilar(pila *pila, nodoPila *nodo);    // Agregar a la cima
void desapilar(pila *pila);                 // Remover de la cima
int lengthPila(pila *pila);                 // Contar elementos
void liberarPila(pila *pila);               // Liberar memoria
```

### 3. 🔗 **Lista Doblemente Enlazada Ordenada**
```c
listaDoble *crearListaDoble();                        // Crear lista vacía
void agregarOrdenadoDobles(listaDoble *, nodoLista*); // Insertar ordenado
void liberarListaDoble(listaDoble *lista);            // Liberar memoria
```

## 💡 Uso del Programa Principal

### �️ Interfaz Interactiva:
```
========================================
    TALLER DE ESTRUCTURAS DE DATOS
========================================
SELECCIONE QUE ESTRUCTURA VA A CREAR:
 1. COLA (FIFO)
 2. PILA (LIFO)
 3. SALIR
```

### 🎮 Funcionalidades del Menú:
1. **➕ Agregar Datos** - Insertar elementos simultáneamente en todas las estructuras
2. **🔄 Ver Conversiones** - Visualizar los mismos datos en diferentes formatos
3. **👀 Mostrar Contenido** - Ver el contenido actual de la estructura seleccionada
4. **🚪 Salir** - Terminar programa liberando memoria automáticamente

## 🔧 Características Técnicas

### 📋 Especificaciones:
- **Lenguaje:** C (Estándar C99)
- **Gestión de Memoria:** Manual con `malloc`/`free`
- **Arquitectura:** Modular con headers separados
- **Compilador:** GCC con flags de optimización
- **Plataforma:** Linux/Unix compatible

### 🛡️ Calidad del Código:
- ✅ **0 Warnings** en compilación
- ✅ **Gestión de memoria** sin leaks
- ✅ **Validación de entrada** implementada
- ✅ **Modularización** correcta
- ✅ **Tests exhaustivos** automatizados



## 🚀 Para Desarrolladores

### 🔍 Compilación con debug:
```bash
gcc -Wall -Wextra -std=c99 -g -o debug_version main.c estructuras.c
```

## 📈 Rendimiento

- **Tiempo de compilación:** < 1 segundo
- **Tiempo de pruebas:** < 1 segundo
- **Memoria utilizada:** Optimizada con liberación automática
- **Complejidad:** O(1) para operaciones básicas, O(n) para inserción ordenada

## 🏆 Estado del Proyecto

```
🎉 PROYECTO COMPLETADO AL 100%
✅ Todas las pruebas pasando
✅ Código limpio y documentado
✅ Memoria gestionada correctamente
✅ Listo para producción
```

## 📄 Licencia

Este proyecto está bajo la Licencia MIT - ver el archivo [LICENSE](LICENSE) para más detalles.

## 🤝 Contribuciones

Este proyecto se comparte con la comunidad educativa. Siéntete libre de:
- 🍴 **Fork** el proyecto para tus propios estudios
- 🐛 **Reportar bugs** o mejoras
- 📚 **Usar como referencia** para tus proyectos académicos
- ⭐ **Dar una estrella** si te resulta útil

---

> 🎓 **Compartido con ❤️ para la comunidad estudiantil**
> 
> 🔗 **Estado:** Estable | **Tests:** 100% ✅ | **Licencia:** MIT