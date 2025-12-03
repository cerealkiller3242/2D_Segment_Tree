#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sys/stat.h>

#include "TwoDim_Segment_Tree.h"

using namespace std;

// Función para verificar si un archivo existe
bool archivoExiste(const string& ruta) {
    struct stat buffer;
    return (stat(ruta.c_str(), &buffer) == 0);
}

int main() {
    srand(time(NULL));

    int N = 128; // tamaño del heatmap
    vector<vector<long long>> matriz(N, vector<long long>(N, 0));

    // Crear el árbol de segmentos 2D
    ArbolSegmentos2D arbol(matriz);

    string rutaInput = "../data/heatmap.txt";
    
    // Verificar si existe el archivo de entrada
    if (archivoExiste(rutaInput)) {
        cout << "Archivo de entrada encontrado. Leyendo datos desde: " << rutaInput << endl;
        
        ifstream entrada(rutaInput);
        if (entrada.is_open()) {
            int x, y;
            long long valor;
            int contador = 0;
            
            while (entrada >> x >> y >> valor) {
                // Validar que las coordenadas estén dentro del rango
                if (x >= 0 && x < N && y >= 0 && y < N) {
                    arbol.actualizar(x, y, valor);
                    contador++;
                } else {
                    cerr << "Advertencia: Coordenadas fuera de rango (" 
                         << x << ", " << y << "). Ignorando..." << endl;
                }
            }
            
            entrada.close();
            cout << "Total de actualizaciones realizadas: " << contador << endl;
        } else {
            cerr << "Error: No se pudo abrir el archivo " << rutaInput << endl;
            cerr << "Generando datos aleatorios por defecto..." << endl;
            
            // Fallback a generación aleatoria
            for (int i = 0; i < 2000; i++) {
                int x = rand() % N;
                int y = rand() % N;
                long long valor = rand() % 20;
                arbol.actualizar(x, y, valor);
            }
        }
    } else {
        cout << "No se encontró archivo de entrada." << endl;
        cout << "Generando datos aleatorios..." << endl;
        
        // Realizar actualizaciones aleatorias (comportamiento por defecto)
        for (int i = 0; i < 2000; i++) {
            int x = rand() % N;
            int y = rand() % N;
            long long valor = rand() % 20;
            arbol.actualizar(x, y, valor);
        }
        
        cout << "Total de actualizaciones aleatorias: 2000" << endl;
    }

    // Exportar heatmap actual a archivo
    cout << "\nExportando heatmap..." << endl;
    ofstream salida("../data/heatmap_output.txt");
    
    if (salida.is_open()) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                long long v = arbol.consulta(i, j, i, j);
                salida << v << " ";
            }
            salida << "\n";
        }
        salida.close();
        cout << "Heatmap exportado exitosamente a: ../data/heatmap_output.txt" << endl;
    } else {
        cerr << "Error: No se pudo crear el archivo de salida" << endl;
        return 1;
    }

    return 0;
}
