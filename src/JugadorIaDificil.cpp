#include "JugadorIaDificil.hh"
#include <cstdlib>
#include <algorithm>

JugadorIaDificil::JugadorIaDificil(const std::string &nombre) : IJugador(nombre) {}

int JugadorIaDificil::realizarMovimiento() { 
    Tablero tableroActual; 
    int MovimientoOptimo = -1;
    int valorOptimo = -10000;

    for (int columna : obtenerMovimientos(tableroActual)) {
        Tablero tableroTemp = tableroActual;
        tableroTemp.colocarFicha(columna, 1); 
        int valorMovimiento = minimax(tableroTemp, 5, false); 
        if (valorMovimiento > valorOptimo) {
            valorOptimo = valorMovimiento;
            MovimientoOptimo = columna;
        }
    }
    return MovimientoOptimo;
}
int JugadorIaDificil::minimax(Tablero &tablero, int profundidad, bool esMaximizador) {
       int ganador = tablero.verificarGanador();
    if (ganador != 0 || profundidad == 0 || estaLleno(tablero)) {
        return evaluarTablero(tablero);
    }

    if (esMaximizador) {
        int valorOptimo = -10000;
        for (int columna : obtenerMovimientos(tablero)) {
            Tablero tableroTemp = tablero;
            tableroTemp.colocarFicha(columna, 1); // 1 representa el jugador IA
            int valor = minimax(tableroTemp, profundidad - 1, false);
            valorOptimo = std::max(valorOptimo, valor);
        }
        return valorOptimo;
    } else {
        int peorValor = 10000;
        for (int columna : obtenerMovimientos(tablero)) {
            Tablero tableroTemp = tablero;
            tableroTemp.colocarFicha(columna, 2); // 2 representa el oponente
            int valor = minimax(tableroTemp, profundidad - 1, true);
            peorValor = std::min(peorValor, valor);
        }
        return peorValor;
    }
}
 int JugadorIaDificil::evaluarTablero(const Tablero &tablero) const {
    // Implementar lógica de evaluar tablero
    return 0; 
}
std::vector<int> JugadorIaDificil::obtenerMovimientos(const Tablero &tablero) const {
    std::vector<int> movimientos;
    for (int col = 0; col < 7; ++col) {
        if (tablero.getGrid()[0][col] == 0) { 
            movimientos.push_back(col);
        }
    }
    return movimientos;
}
bool JugadorIaDificil::estaLleno(const Tablero &tablero) const {
    for (int col = 0; col < 7; ++col) {
        if (tablero.getGrid()[0][col] == 0) {
            return false;
        }
    }
    return true;
}
