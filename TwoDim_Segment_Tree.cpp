#include "TwoDim_Segment_Tree.h"
using ll = long long;
using std::vector;

/* =============================
   CONSTRUCTOR Y CONSTRUCCIÓN
   ============================= */

ArbolSegmentos2D::ArbolSegmentos2D(const vector<vector<ll>>& matriz) {
    n = matriz.size();
    m = matriz[0].size();
    base = matriz;

    arbol.assign(4 * n, vector<ll>(4 * m, 0));
    construir_x(1, 0, n - 1);
}

void ArbolSegmentos2D::construir_x(int nodo_x, int lx, int rx) {
    if (lx == rx) {
        construir_y(nodo_x, lx, rx, 1, 0, m - 1);
    } else {
        int mid = (lx + rx) / 2;
        construir_x(nodo_x * 2, lx, mid);
        construir_x(nodo_x * 2 + 1, mid + 1, rx);
        construir_y(nodo_x, lx, rx, 1, 0, m - 1);
    }
}

void ArbolSegmentos2D::construir_y(int nodo_x, int lx, int rx, int nodo_y, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx) {
            nodo(nodo_x, nodo_y) = base[lx][ly];
        } else {
            nodo(nodo_x, nodo_y) =
                nodo(nodo_x * 2,     nodo_y) +
                nodo(nodo_x * 2 + 1, nodo_y);
        }
    } else {
        int mid = (ly + ry) / 2;
        construir_y(nodo_x, lx, rx, nodo_y * 2, ly, mid);
        construir_y(nodo_x, lx, rx, nodo_y * 2 + 1, mid + 1, ry);

        nodo(nodo_x, nodo_y) =
            nodo(nodo_x, nodo_y * 2) +
            nodo(nodo_x, nodo_y * 2 + 1);
    }
}

/* =============================
   ACTUALIZACIÓN PUNTUAL
   ============================= */

void ArbolSegmentos2D::actualizar(int x, int y, ll nuevo_valor) {
    actualizar_x(1, 0, n - 1, x, y, nuevo_valor);
    base[x][y] = nuevo_valor;
}

void ArbolSegmentos2D::actualizar_x(int nodo_x, int lx, int rx, int x, int y, ll nuevo_valor) {
    if (lx == rx) {
        actualizar_y(nodo_x, lx, rx, 1, 0, m - 1, x, y, nuevo_valor);
    } else {
        int mid = (lx + rx) / 2;
        if (x <= mid)
            actualizar_x(nodo_x * 2, lx, mid, x, y, nuevo_valor);
        else
            actualizar_x(nodo_x * 2 + 1, mid + 1, rx, x, y, nuevo_valor);

        actualizar_y(nodo_x, lx, rx, 1, 0, m - 1, x, y, nuevo_valor);
    }
}

void ArbolSegmentos2D::actualizar_y(int nodo_x, int lx, int rx, int nodo_y, int ly, int ry, int x, int y, ll nuevo_valor) {
    if (ly == ry) {
        if (lx == rx) {
            nodo(nodo_x, nodo_y) = nuevo_valor;
        } else {
            nodo(nodo_x, nodo_y) =
                nodo(nodo_x * 2,     nodo_y) +
                nodo(nodo_x * 2 + 1, nodo_y);
        }
    } else {
        int mid = (ly + ry) / 2;
        if (y <= mid)
            actualizar_y(nodo_x, lx, rx, nodo_y * 2, ly, mid, x, y, nuevo_valor);
        else
            actualizar_y(nodo_x, lx, rx, nodo_y * 2 + 1, mid + 1, ry, x, y, nuevo_valor);

        nodo(nodo_x, nodo_y) =
            nodo(nodo_x, nodo_y * 2) +
            nodo(nodo_x, nodo_y * 2 + 1);
    }
}

/* =============================
   Queries
   ============================= */

ll ArbolSegmentos2D::consulta(int x1, int y1, int x2, int y2) const {
    return consulta_x(1, 0, n - 1, x1, x2, y1, y2);
}

ll ArbolSegmentos2D::consulta_x(int nodo_x, int lx, int rx,
                                int qx1, int qx2, int qy1, int qy2) const {
    if (qx2 < lx || rx < qx1) return 0;
    if (qx1 <= lx && rx <= qx2)
        return consulta_y(nodo_x, lx, rx, 1, 0, m - 1, qy1, qy2);

    int mid = (lx + rx) / 2;
    return consulta_x(nodo_x * 2, lx, mid, qx1, qx2, qy1, qy2) +
           consulta_x(nodo_x * 2 + 1, mid + 1, rx, qx1, qx2, qy1, qy2);
}

ll ArbolSegmentos2D::consulta_y(int nodo_x, int lx, int rx,
                                int nodo_y, int ly, int ry,
                                int qy1, int qy2) const {
    if (qy2 < ly || ry < qy1) return 0;
    if (qy1 <= ly && ry <= qy2)
        return nodo(nodo_x, nodo_y);

    int mid = (ly + ry) / 2;
    return consulta_y(nodo_x, lx, rx, nodo_y * 2, ly, mid, qy1, qy2) +
           consulta_y(nodo_x, lx, rx, nodo_y * 2 + 1, mid + 1, ry, qy1, qy2);
}
