# cine-multisalas-gestion
Sistema en C++ para gestionar cines multisalas, permitiendo registrar empresas, salas, sesiones y películas utilizando estructuras dinámicas enlazadas. La aplicación se ejecuta exclusivamente en consola, sin interfaz gráfica.


## 📌 Funcionalidades principales

- Registrar cines (empresas)
- Registrar salas dentro de cada cine
- Registrar días de la semana para cada sala
- Registrar sesiones (películas) con detalles como hora, protagonista y clasificación
- Buscar y modificar películas
- Listar películas por clasificación de edad
- Mostrar información completa de una sala específica
- Listar la cartelera de todos los cines registrados

## 📁 Estructuras utilizadas

El sistema utiliza listas doblemente enlazadas para representar la jerarquía:

Cada nivel tiene punteros a su anterior y siguiente elemento para facilitar el manejo dinámico.

## 🚀 Cómo usar

1. Compila el programa con un compilador de C++:
   ```bash
   g++ -o gestion_cine gestion_cine.cpp

