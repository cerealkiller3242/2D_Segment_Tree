import numpy as np
import matplotlib
matplotlib.use('Agg')  # Backend sin interfaz gráfica
import matplotlib.pyplot as plt

# Ruta del archivo generado por C++
DATA_PATH = "data/heatmap_output.txt"
OUTPUT_PATH = "data/heatmap_visualization.png"

def cargar_heatmap(path):
    return np.loadtxt(path)

def mostrar_heatmap(matriz):
    plt.figure(figsize=(12, 10))
    plt.imshow(matriz, cmap="hot", interpolation='nearest')
    plt.colorbar(label="Valor")
    plt.title("Heatmap generado con Árbol de Segmentos 2D")
    plt.tight_layout()
    plt.savefig(OUTPUT_PATH, dpi=150, bbox_inches='tight')
    print(f"Heatmap guardado en: {OUTPUT_PATH}")

if __name__ == "__main__":
    matriz = cargar_heatmap(DATA_PATH)
    print(f"Matriz cargada: {matriz.shape[0]}x{matriz.shape[1]}")
    print(f"Valores: min={matriz.min()}, max={matriz.max()}")
    mostrar_heatmap(matriz)
