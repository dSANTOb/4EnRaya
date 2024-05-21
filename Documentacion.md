Documentación Proyecto #2 - 4 en raya

Integrantes: 
-Gabriel Cordero Quesada C32296 
-Javier Chacón Rosales C32052 
-Santiago Vega Robles C38351

Pasos para compilacion:
Correr en la terminal

cmake -S . -B build -G Ninja
cmake --build build

El proyecto consta con las clases de encabezado IJugador, JugadorHumano, JugadorIaFacil, JugadorIaDificil y Tablero, cada una con su implementacion en el folder src.

Por trabajar:
Agregar una clase juego que ejecute todo, implementar la interfaz, el algoritmo de minimax, implementar la logica de condicion de victoria y probar el juego total en la terminal.

Errores conocidos:
Los tests no funcionan, porque las clases encabezado no estan siendo detectadas en los tests.