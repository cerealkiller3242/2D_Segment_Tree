import numpy as np
import matplotlib.pyplot as plt

# Ruta del archivo generado por C++
DATA_PATH = "../data/heatmap_output.txt"

def cargar_heatmap(path):
    return np.loadtxt(path)

def mostrar_heatmap(matriz):
    plt.imshow(matriz, cmap="hot")
    plt.colorbar(label="Valor")
    plt.title("Heatmap generado con Árbol de Segmentos 2D")
    plt.show()

if __name__ == "__main__":
    matriz = cargar_heatmap(DATA_PATH)
    mostrar_heatmap(matriz)
