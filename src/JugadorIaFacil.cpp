#include <JugadorIaFacil.hh>
#include <cstdlib>
#include <ctime>

JugadorIaFacil::JugadorIaFacil(const std::string& nombre) : IJugador(nombre) {
    std::srand(std::time(nullptr)); // Inicializar la semilla aleatoria
}

int JugadorIaFacil::realizarMovimiento(Tablero& tableroActual) {
    std::vector<int> movimientos = obtenerMovimientos(tableroActual);
    if (!movimientos.empty()) {
        int randomIndex = std::rand() % movimientos.size();
        return movimientos[randomIndex];
    }
    return -1; // Si no hay movimientos disponibles, devolver -1.
}

std::vector<int> JugadorIaFacil::obtenerMovimientos(const Tablero& tablero) const {
    std::vector<int> movimientos;
    for (int col = 0; col < tablero.getGrid()[0].size(); ++col) {
        if (tablero.getGrid()[0][col] == 0) {
            movimientos.push_back(col);
        }
    }
    return movimientos;
}
