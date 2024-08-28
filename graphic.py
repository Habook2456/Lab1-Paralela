import matplotlib.pyplot as plt

# Datos
dimensiones = [500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000]
tiempos_loop1 = [0.00200679, 0.00804081, 0.0177171, 0.0310265, 0.0482466, 0.0699626, 0.0940843, 0.127077, 0.158917, 0.19161]
tiempos_loop2 = [0.00278975, 0.013182, 0.0327691, 0.0604183, 0.0960211, 0.139095, 0.192224, 0.254423, 0.322586, 0.404435]

# Crear el gráfico
plt.figure(figsize=(10, 6))
plt.plot(dimensiones, tiempos_loop1, marker='o', linestyle='-', color='b', label='Loop1')
plt.plot(dimensiones, tiempos_loop2, marker='o', linestyle='-', color='r', label='Loop2')

# Añadir etiquetas y título
plt.xlabel('Dimensión')
plt.ylabel('Tiempo (segundos)')
plt.title('Tiempo de ejecución vs Dimensión')
plt.legend()

# Guardar el gráfico en un archivo
plt.grid(True)
plt.savefig('grafico_tiempos.png')

# Cerrar la figura
plt.close()


import matplotlib.pyplot as plt

# Dimensiones y tiempos
dimensiones = [100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 850, 900, 950, 1000]
tiempos_block = [0.0102795, 0.0330262, 0.0778826, 0.150546, 0.257622, 0.407441, 0.642448, 0.888025, 1.22704, 1.56372, 2.03009, 2.59172, 3.19957, 3.98202, 4.7959, 5.78073, 6.90956, 8.03869, 9.47866]
tiempos_classic = [0.0107556, 0.0349554, 0.0938484, 0.173485, 0.297616, 0.489585, 0.768836, 1.11471, 1.52837, 1.99387, 2.61332, 3.28983, 4.12332, 5.03558, 6.1989, 7.46568, 9.06832, 10.5676, 12.852]

# Crear el gráfico
plt.figure(figsize=(10, 6))
plt.plot(dimensiones, tiempos_block, marker='o', linestyle='-', color='b', label='Block Mult Algorithm')
plt.plot(dimensiones, tiempos_classic, marker='o', linestyle='-', color='r', label='Classic Mult Algorithm')

# Añadir etiquetas y título
plt.xlabel('Dimensión')
plt.ylabel('Tiempo (segundos)')
plt.title('Comparación de Algoritmos de Multiplicación de Matrices')
plt.legend()

# Mostrar la grilla
plt.grid(True)

# Guardar el gráfico en un archivo
plt.savefig('comparacion_algoritmos_multiplicacion.png')

# Cerrar la figura
plt.close()
