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
    Tablero();
    bool colocarFicha(int columna, int jugador);
    void imprimirTablero() const;
    int verificarGanador() const;
    
    // Método para obtener el estado actual del tablero
    const std::vector<std::vector<int>>& getGrid() const;
};

#endif // TABLERO_HH
