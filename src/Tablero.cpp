#include <Tablero.hh>
#include <iostream>

Tablero::Tablero() : grid(filas, std::vector<int>(columnas, 0)) {}

bool Tablero::colocarFicha(int columna, int jugador) {
    //Coloca el numero representativo del jugador en el grid
    if (columna < 0 || columna >= columnas) return false;
    for (int fila = filas - 1; fila >= 0; --fila) {
        if (grid[fila][columna] == 0) {
            grid[fila][columna] = jugador;
            return true;
        }
    }
    return false;
}

void Tablero::imprimirTablero() const {
    //Imprime el tablero segun el estado del grid
    for (const auto &fila : grid) {
        for (const auto &celda : fila) {
            std::cout << (celda == 0 ? "." : (celda == 1 ? "X" : "O")) << " ";
        }
        std::cout << std::endl;
    }
}

int Tablero::verificarGanador() const {
    // Implementar lógica para verificar si hay un ganador
    return 0;
}

const std::vector<std::vector<int>>& Tablero::getGrid() const {
    return grid;
}
