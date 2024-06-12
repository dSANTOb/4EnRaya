#include <JugadorHumano.hh>

JugadorHumano::JugadorHumano(const std::string& nombre) : IJugador(nombre) {}

int JugadorHumano::realizarMovimiento(Tablero& tableroActual) {
    // El movimiento se maneja por el evento de clic del ratón en el tablero.
    return -1; // Este valor no se usa.
}

