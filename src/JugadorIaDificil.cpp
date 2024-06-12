#include <JugadorIaDificil.hh>
#include <cstdlib>
#include <algorithm>

JugadorIaDificil::JugadorIaDificil(const std::string& nombre) : IJugador(nombre) {}

int JugadorIaDificil::realizarMovimiento(Tablero& tableroActual) {
    int movimientoOptimo = -1;
    int valorOptimo = -10000;

    for (int columna : obtenerMovimientos(tableroActual)) {
        Tablero tableroTemp = tableroActual;
        if (tableroTemp.colocarFicha(columna, 1)) { // 1 representa el jugador IA
            int valorMovimiento = minimax(tableroTemp, 5, false);
            if (valorMovimiento > valorOptimo) {
                valorOptimo = valorMovimiento;
                movimientoOptimo = columna;
            }
        }
    }
    return movimientoOptimo;
}

int JugadorIaDificil::minimax(Tablero& tablero, int profundidad, bool esMaximizador) {
    int ganador = 0;
    for (int fila = 0; fila < tablero.getGrid().size(); ++fila) {
        for (int col = 0; col < tablero.getGrid()[0].size(); ++col) {
            if (tablero.getGrid()[fila][col] != 0) {
                ganador = tablero.verificarGanador(fila, col);
                if (ganador != 0) break;
            }
        }
        if (ganador != 0) break;
    }

    if (ganador != 0 || profundidad == 0 || estaLleno(tablero)) {
        return evaluarTablero(tablero);
    }

    if (esMaximizador) {
        int valorOptimo = -10000;
        for (int columna : obtenerMovimientos(tablero)) {
            Tablero tableroTemp = tablero;
            if (tableroTemp.colocarFicha(columna, 1)) { // 1 representa el jugador IA
                int valor = minimax(tableroTemp, profundidad - 1, false);
                valorOptimo = std::max(valorOptimo, valor);
            }
        }
        return valorOptimo;
    } else {
        int peorValor = 10000;
        for (int columna : obtenerMovimientos(tablero)) {
            Tablero tableroTemp = tablero;
            if (tableroTemp.colocarFicha(columna, 2)) { // 2 representa el oponente
                int valor = minimax(tableroTemp, profundidad - 1, true);
                peorValor = std::min(peorValor, valor);
            }
        }
        return peorValor;
    }
}

int JugadorIaDificil::evaluarTablero(const Tablero& tablero) const {
    // Implementar lógica de evaluar tablero
    return 0;
}

std::vector<int> JugadorIaDificil::obtenerMovimientos(const Tablero& tablero) const {
    std::vector<int> movimientos;
    for (int col = 0; col < tablero.getGrid()[0].size(); ++col) {
        if (tablero.getGrid()[0][col] == 0) {
            movimientos.push_back(col);
        }
    }
    return movimientos;
}

bool JugadorIaDificil::estaLleno(const Tablero& tablero) const {
    for (int col = 0; col < tablero.getGrid()[0].size(); ++col) {
        if (tablero.getGrid()[0][col] == 0) {
            return false;
        }
    }
    return true;
}
