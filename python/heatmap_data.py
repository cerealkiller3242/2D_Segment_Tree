import random
import math

def generar_datos_heatmap(num_registros=100000, tamano_mapa=128):
    """
    Genera datos para un heatmap con concentración en zonas específicas
    Simula un patrón realista con múltiples focos de actividad
    """
    
    # Definir zonas de concentración (centros de actividad)
    zonas = [
        {"x": 64, "y": 64, "peso": 0.5, "radio": 20},   # Zona principal (50% de los datos)
        {"x": 40, "y": 80, "peso": 0.25, "radio": 15},  # Zona secundaria (25%)
        {"x": 90, "y": 50, "peso": 0.15, "radio": 12},  # Zona terciaria (15%)
    ]
    
    datos = []
    
    for i in range(num_registros):
        # Decidir si este punto pertenece a una zona concentrada o es aleatorio
        if random.random() < 0.90:  # 90% en zonas concentradas
            # Seleccionar zona según pesos
            rand = random.random()
            acumulado = 0
            zona_seleccionada = zonas[0]
            
            for zona in zonas:
                acumulado += zona["peso"]
                if rand < acumulado:
                    zona_seleccionada = zona
                    break
            
            # Generar punto con distribución normal alrededor del centro
            angulo = random.uniform(0, 2 * math.pi)
            distancia = abs(random.gauss(0, zona_seleccionada["radio"] / 2))
            
            x = int(zona_seleccionada["x"] + distancia * math.cos(angulo))
            y = int(zona_seleccionada["y"] + distancia * math.sin(angulo))
            
            # Asegurar que está dentro del mapa
            x = max(0, min(tamano_mapa - 1, x))
            y = max(0, min(tamano_mapa - 1, y))
            
            # Valor más alto en zonas concentradas
            valor = random.randint(5, 19)
        else:
            # 10% de puntos dispersos (ruido de fondo)
            x = random.randint(0, tamano_mapa - 1)
            y = random.randint(0, tamano_mapa - 1)
            valor = random.randint(1, 8)
        
        datos.append(f"{x} {y} {valor}")
    
    return datos

# Generar los datos
print("Generando 100000 registros para el heatmap...")
registros = generar_datos_heatmap(100000, 128)

# Guardar en archivo
nombre_archivo = "data/heatmap_input100000.txt"
with open(nombre_archivo, 'w') as f:
    for registro in registros:
        f.write(registro + '\n')

print(f"✓ Archivo '{nombre_archivo}' generado con éxito!")
print(f"✓ Total de registros: {len(registros)}")
print(f"\nPrimeros 10 registros:")
for i in range(10):
    print(f"  {registros[i]}")
print("\nDatos generados con concentración en zonas:")
print("  - Zona principal: centro (64, 64) - 50% de los datos")
print("  - Zona secundaria: (40, 80) - 25% de los datos")
print("  - Zona terciaria: (90, 50) - 15% de los datos")
print("  - Dispersión aleatoria: 10% de los datos")