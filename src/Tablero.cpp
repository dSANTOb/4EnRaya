#include <Tablero.hh>
#include <iostream>

Tablero::Tablero(int filas, int columnas) : filas(filas), columnas(columnas), grid(filas, std::vector<int>(columnas, 0)) {}

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
    // Verificar horizontalmente
    for (int fila = 0; fila < filas; ++fila) {
        for (int columna = 0; columna <= columnas - 4; ++columna) {
            int jugador = grid[fila][columna];
            if (jugador != 0 && jugador == grid[fila][columna + 1] && 
                jugador == grid[fila][columna + 2] && jugador == grid[fila][columna + 3]) {
                return jugador;
            }
        }
    }

    // Verificar verticalmente
    for (int fila = 0; fila <= filas - 4; ++fila) {
        for (int columna = 0; columna < columnas; ++columna) {
            int jugador = grid[fila][columna];
            if (jugador != 0 && jugador == grid[fila + 1][columna] && 
                jugador == grid[fila + 2][columna] && jugador == grid[fila + 3][columna]) {
                return jugador;
            }
        }
    }

    // Verificar diagonal ascendente
    for (int fila = 3; fila < filas; ++fila) {
        for (int columna = 0; columna <= columnas - 4; ++columna) {
            int jugador = grid[fila][columna];
            if (jugador != 0 && jugador == grid[fila - 1][columna + 1] && 
                jugador == grid[fila - 2][columna + 2] && jugador == grid[fila - 3][columna + 3]) {
                return jugador;
            }
        }
    }

    // Verificar diagonal descendente
    for (int fila = 0; fila <= filas - 4; ++fila) {
        for (int columna = 0; columna <= columnas - 4; ++columna) {
            int jugador = grid[fila][columna];
            if (jugador != 0 && jugador == grid[fila + 1][columna + 1] && 
                jugador == grid[fila + 2][columna + 2] && jugador == grid[fila + 3][columna + 3]) {
                return jugador;
            }
        }
    }

    // Si no hay ganador, retorna 0
    return 0;
}

const std::vector<std::vector<int>>& Tablero::getGrid() const {
    return grid;
}

void Tablero::redimensionar(int nuevasFilas, int nuevasColumnas) {
    std::vector<std::vector<int>> nuevoGrid(nuevasFilas, std::vector<int>(nuevasColumnas, 0));

    for (int i = 0; i < std::min(filas, nuevasFilas); ++i) {
        for (int j = 0; j < std::min(columnas, nuevasColumnas); ++j) {
            nuevoGrid[i][j] = grid[i][j];
        }
    }

    filas = nuevasFilas;
    columnas = nuevasColumnas;
    grid = nuevoGrid;
}