#ifndef TWODIM_SEGMENT_TREE_H
#define TWODIM_SEGMENT_TREE_H

#include <vector>
#include <cstdint>
#include <cassert>

/*
 Árbol de Segmentos Bidimensional (2D Segment Tree)
 -------------------------------------------------
 Operaciones soportadas (índices 0-indexados):

 - Construcción desde una matriz inicial.
 - update(x, y, nuevo_valor): actualiza un punto.
 - consulta(x1, y1, x2, y2): devuelve la suma en el rectángulo.

 Complejidad:
 - Construcción: O(n * m)
 - Actualización puntual: O(log n * log m)
 - Consulta por rango: O(log n * log m)

 Esta implementación está orientada a SUMAS.
*/

class ArbolSegmentos2D {
public:
    using ll = long long;

    ArbolSegmentos2D(const std::vector<std::vector<ll>>& matriz);

    // Cambiar el valor de (x, y)
    void actualizar(int x, int y, ll nuevo_valor);

    // Consultar suma en el rectángulo [x1..x2] x [y1..y2]
    ll consulta(int x1, int y1, int x2, int y2) const;

    int filas() const { return n; }
    int columnas() const { return m; }

private:
    int n, m;
    std::vector<std::vector<ll>> base;
    std::vector<std::vector<ll>> arbol; // arbol[nodo_x][nodo_y]

    // Construcción
    void construir_x(int nodo_x, int lx, int rx);
    void construir_y(int nodo_x, int lx, int rx, int nodo_y, int ly, int ry);

    // Actualización
    void actualizar_x(int nodo_x, int lx, int rx, int x, int y, ll nuevo_valor);
    void actualizar_y(int nodo_x, int lx, int rx, int nodo_y, int ly, int ry, int x, int y, ll nuevo_valor);

    // Consulta
    ll consulta_x(int nodo_x, int lx, int rx, int qx1, int qx2, int qy1, int qy2) const;
    ll consulta_y(int nodo_x, int lx, int rx, int nodo_y, int ly, int ry, int qy1, int qy2) const;

    // Atajos
    inline ll& nodo(int nx, int ny) { return arbol[nx][ny]; }
    inline const ll& nodo(int nx, int ny) const { return arbol[nx][ny]; }
};

#endif