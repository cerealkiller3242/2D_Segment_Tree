#!/bin/bash

# Script para generar y visualizar el heatmap del Árbol de Segmentos 2D

echo "==================================="
echo "Compilando el proyecto..."
echo "==================================="
cd build
cmake .. && make
if [ $? -ne 0 ]; then
    echo "Error en la compilación"
    exit 1
fi

echo ""
echo "==================================="
echo "Ejecutando heatmap_demo..."
echo "==================================="
./heatmap_demo
if [ $? -ne 0 ]; then
    echo "Error al ejecutar heatmap_demo"
    exit 1
fi

echo ""
echo "==================================="
echo "Generando visualización..."
echo "==================================="
cd ../python
python3 visualize_heatmap.py
if [ $? -ne 0 ]; then
    echo "Error al generar la visualización"
    exit 1
fi

echo ""
echo "==================================="
echo "¡Proceso completado!"
echo "Heatmap guardado en: data/heatmap_visualization.png"
echo "==================================="

