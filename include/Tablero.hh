#ifndef TABLERO_HH
#define TABLERO_HH

#include <vector>

class Tablero {
private:
    //TODO: El tablero no debe ser constante, sino que cambia con la ventana
    //Vector int que almacena el estado del tablero (Una matriz de enteros) en grid
    std::vector<std::vector<int>> grid;
    bool esValido(int fila, int columna) const;
    bool verificarLinea(int fila, int columna, int deltaFila, int deltaColumna, int jugador) const; // Método auxiliar

public:
    Tablero(int filas, int columnas);
    bool colocarFicha(int columna, int jugador);
    void imprimirTablero() const;
    int verificarGanador(int fila, int columna) const;

    const std::vector<std::vector<int>>& getGrid() const;
    void redimensionar(int nuevasFilas, int nuevasColumnas);
};

#endif
