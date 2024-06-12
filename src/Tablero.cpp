#include <Tablero.hh>
#include <iostream>

#include "Tablero.hh"

Tablero::Tablero(int filas, int columnas) : grid(filas, std::vector<int>(columnas, 0)) {}

bool Tablero::colocarFicha(int columna, int jugador) {
    for (int fila = grid.size() - 1; fila >= 0; --fila) {
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

int Tablero::verificarGanador(int fila, int columna) const {
    int jugador = grid[fila][columna];
    if (jugador == 0) return 0;

    if (verificarLinea(fila, columna, 1, 0, jugador) || // Vertical
        verificarLinea(fila, columna, 0, 1, jugador) || // Horizontal
        verificarLinea(fila, columna, 1, 1, jugador) || // Diagonal /
        verificarLinea(fila, columna, 1, -1, jugador)) { // Diagonal \ return jugador;
    }
    return 0;
}

const std::vector<std::vector<int>>& Tablero::getGrid() const {
    return grid;
}

void Tablero::redimensionar(int nuevasFilas, int nuevasColumnas) {
    grid.resize(nuevasFilas);
    for (auto& fila : grid) {
        fila.resize(nuevasColumnas, 0);
    }
}

bool Tablero::esValido(int fila, int columna) const {
    return fila >= 0 && fila < grid.size() && columna >= 0 && columna < grid[0].size();
}

bool Tablero::verificarLinea(int fila, int columna, int deltaFila, int deltaColumna, int jugador) const {
    int count = 0;
    for (int i = -3; i <= 3; ++i) {
        int newRow = fila + i * deltaFila;
        int newCol = columna + i * deltaColumna;
        if (esValido(newRow, newCol) && grid[newRow][newCol] == jugador) {
            if (++count == 4) return true;
        } else {
            count = 0;
        }
    }
    return false;
}