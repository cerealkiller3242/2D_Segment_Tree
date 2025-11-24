#include <iostream>
#include <vector>
#include "TwoDim_Segment_Tree.h"

using namespace std;

int main() {
    vector<vector<long long>> matriz = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    ArbolSegmentos2D arbol(matriz);

    cout << "Suma completa: " << arbol.consulta(0, 0, 2, 2) << "\n";
    cout << "Suma submatriz (1,1)-(2,2): " << arbol.consulta(1, 1, 2, 2) << "\n";

    cout << "Actualizando (0,0) a 10...\n";
    arbol.actualizar(0, 0, 10);

    cout << "Nueva suma completa: " << arbol.consulta(0, 0, 2, 2) << "\n";

    return 0;
}
