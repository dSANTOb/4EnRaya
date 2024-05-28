#ifndef TABLERO_HH
#define TABLERO_HH

#include <vector>

class Tablero {
private:
    //Vector int que almacena el estado del tablero (Una matriz de enteros) en grid
    std::vector<std::vector<int>> grid;
    const int filas = 6;
    const int columnas = 7;

public:
    // Constructor de la clase Tablero
    Tablero();

    // Método para colocar una ficha en una columna específica para un jugador dado
    // Retorna true si la ficha se pudo colocar, false si la columna está llena
    bool colocarFicha(int columna, int jugador);

    // Método para imprimir el tablero actual
    void imprimirTablero() const;

    // Método para verificar si hay un ganador en el tablero
    // Retorna el número del jugador que ganó (1 o 2), o 0 si no hay ganador
    int verificarGanador() const;

    // Método para obtener el estado actual del tablero
    const std::vector<std::vector<int>>& getGrid() const;
};

#endif // TABLERO_HH
