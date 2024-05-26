#include <JugadorIaDificil.hh>
#include <cstdlib>

JugadorIaDificil::JugadorIaDificil(const std::string &nombre) : IJugador(nombre) {}

int JugadorIaDificil::realizarMovimiento() {
    // Aquí se debe agregar el metodo de minimax para decifrar la columna optima
    return rand() % 7; //por el momento random
}

int JugadorIaDificil::minimax(Tablero &tablero, int profundidad, bool esMaximizador) {
    // Implementar el algoritmo Minimax aquí
    return 0; // Placeholder
}

