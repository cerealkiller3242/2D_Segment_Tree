#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "TwoDim_Segment_Tree.h"

using namespace std;

int main() {
    srand(time(NULL));

    int N = 128; // tamaño del heatmap
    vector<vector<long long>> matriz(N, vector<long long>(N, 0));

    // Crear el árbol de segmentos 2D
    ArbolSegmentos2D arbol(matriz);

    // Realizar actualizaciones aleatorias
    for (int i = 0; i < 2000; i++) {
        int x = rand() % N;
        int y = rand() % N;
        long long valor = rand() % 20;
        arbol.actualizar(x, y, valor);
    }

    // Exportar heatmap actual a archivo
    ofstream salida("../data/heatmap_output.txt");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            long long v = arbol.consulta(i, j, i, j);
            salida << v << " ";
        }
        salida << "\n";
    }

    cout << "Heatmap exportado a data/heatmap_output.txt\n";
    return 0;
}
