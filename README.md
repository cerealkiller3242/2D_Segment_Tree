# Árbol de Segmentos 2D (2D Segment Tree)

Implementación eficiente de un Árbol de Segmentos Bidimensional en C++ con visualización de heatmap en Python.

## Características

- **Operaciones soportadas:**
  - Construcción desde una matriz inicial
  - Actualización puntual: `actualizar(x, y, nuevo_valor)`
  - Consulta de rango rectangular: `consulta(x1, y1, x2, y2)`

- **Complejidad:**
  - Construcción: O(n × m)
  - Actualización puntual: O(log n × log m)
  - Consulta por rango: O(log n × log m)

## Estructura del Proyecto

# Árbol de Segmentos 2D (2D Segment Tree)

Implementación eficiente de un Árbol de Segmentos Bidimensional en C++ con un pequeño demo que genera un heatmap y una visualización en Python.

## Qué contiene este repositorio

Estructura principal:

```
. 
├── CMakeLists.txt
├── include/TwoDim_Segment_Tree.h
├── src/TwoDim_Segment_Tree.cpp
├── src/heatmap_demo.cpp
├── python/visualize_heatmap.py
├── data/ (salidas generadas)
└── run_heatmap.sh
```

## Requisitos

- CMake 3.10+ y compilador C++ (C++17)
- Python 3.x con numpy y matplotlib

Instala las dependencias de Python:

```bash
pip install numpy matplotlib
```

## Cómo ejecutar el demo (rápido)

El repositorio incluye `run_heatmap.sh` que automatiza la compilación, ejecución del demo y la visualización.

Hazlo ejecutable y ejecútalo:

```bash
chmod +x run_heatmap.sh
./run_heatmap.sh
```

Qué hace `run_heatmap.sh` (resumen):
- Crea/usa la carpeta `build/`, ejecuta CMake y make
- Lanza el binario `heatmap_demo` que genera `data/heatmap_output.txt`
- Llama al script Python `python/visualize_heatmap.py` para generar `data/heatmap_visualization.png`


## Enfoque principal: ¿Cómo y para qué se usa el 2D Segment Tree en el demo?

Esta sección explica detalladamente el rol del 2D Segment Tree (`ArbolSegmentos2D`) en `heatmap_demo.cpp`.

- Construcción:
  - En `heatmap_demo.cpp` se crea primero una matriz N×N (N = 128) inicializada a cero.
  - Se construye el árbol con `ArbolSegmentos2D arbol(matriz);`. La construcción prepara una estructura capaz de responder consultas de suma en subrectángulos y aplicar actualizaciones puntuales eficientemente.

- Actualizaciones (cómo se usa):
  - El demo realiza 2000 operaciones aleatorias: `arbol.actualizar(x, y, valor);`.
 
- Lectura / Exportación:
  - Para escribir el heatmap final, el demo recorre todas las posiciones (i, j) y usa `arbol.consulta(i, j, i, j)` para leer el valor puntual almacenado. Es decir, usa la consulta de rango pero con un rectángulo de un solo punto.
  - El archivo `data/heatmap_output.txt` es la matriz resultante que luego carga el script Python para visualizarla.

- Para qué se usa el 2DST en este demo:
  - Mostrar la API de un árbol de segmentos 2D: construcción, actualización puntual y consultas de rango.
  - Permitir actualizaciones y consultas asintóticamente eficientes (O(log n · log m)).
  - Aunque en el demo sólo se realizan actualizaciones puntuales y lecturas puntuales, la misma estructura sirve para consultas más generales de suma en rectángulos (por ejemplo sumar todos los valores en un subrectángulo) sin recorrer las celdas una a una.

## API resumida de `ArbolSegmentos2D`

```cpp
// Constructor
ArbolSegmentos2D(const std::vector<std::vector<long long>>& matriz);

// Actualiza (asigna) el valor en (x, y)
void actualizar(int x, int y, long long nuevo_valor);

// Devuelve la suma en el rectángulo [x1..x2] × [y1..y2]
long long consulta(int x1, int y1, int x2, int y2) const;

// Dimensiones
int filas() const;
int columnas() const;
```

## Ejemplo corto

```cpp
std::vector<std::vector<long long>> matriz(128, std::vector<long long>(128, 0));
ArbolSegmentos2D arbol(matriz);
arbol.actualizar(10, 20, 5); // set
long long v = arbol.consulta(10,20,10,20); // leer punto
```
