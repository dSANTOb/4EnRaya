#ifndef TABLERO_HH
#define TABLERO_HH

#include <vector>

class Tablero {
private:
    //TODO: El tablero no debe ser constante, sino que cambia con la ventana
    //Vector int que almacena el estado del tablero (Una matriz de enteros) en grid
    std::vector<std::vector<int>> grid;
    int filas;
    int columnas;

public:
    Tablero(int filas = 6, int columnas = 7);
    bool colocarFicha(int columna, int jugador);
    void imprimirTablero() const;
    int verificarGanador() const;
    
    // Método para obtener el estado actual del tablero
    const std::vector<std::vector<int>>& getGrid() const;
    void redimensionar(int nuevasFilas, int nuevasColumnas);
};

#endif // TABLERO_HH
