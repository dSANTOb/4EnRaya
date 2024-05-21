#include "JugadorHumano.hh"

JugadorHumano::JugadorHumano(const std::string& nombre) : IJugador(nombre) {}

int JugadorHumano::GetPuntaje() const {
    return Puntaje;
}

std::string JugadorHumano::GetNombre() const {
    return Nombre;
}

void JugadorHumano::CrearFicha() {
    // Implementar lógica para crear una ficha para el jugador humano
}