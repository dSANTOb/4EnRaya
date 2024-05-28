Documentación Proyecto #2 - 4 en raya

Integrantes: 
-Gabriel Cordero Quesada C32296 
-Javier Chacón Rosales C32052 
-Santiago Vega Robles C38351

Pasos para compilacion:
Correr en la terminal

cmake -S . -B build -G Ninja
cmake --build build

El proyecto consta con las clases de encabezado IJugador, JugadorHumano, JugadorIaFacil, JugadorIaDificil, Tablero, App y Frame, cada una con su implementacion en el folder src.

TODO:
Agragar el algoritmo de minimax, implementar la logica de condicion de victoria, que el tablero se modifique segun la ventana, implementar el menu

Errores conocidos:
Error al crear ejecutable debido a una declaración de clase incompleta o a la falta de implementación de los métodos virtuales puros en la clase App. Esto provoca que el enlazador no pueda encontrar las referencias a la vtable.

Los tests siguen sin funcionar.