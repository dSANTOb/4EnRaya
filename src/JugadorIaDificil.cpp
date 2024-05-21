#include "JugadorIaDificil.hh"

JugadorIaDificil::JugadorIaDificil(const std::string& nombre) : IJugador(nombre) {}

int JugadorIaDificil::GetPuntaje() const {
    return Puntaje;
}

std::string JugadorIaDificil::GetNombre() const {
    return Nombre;
}

void JugadorIaDificil::CrearFicha() {
    // Implementar lógica para crear una ficha para la IA difícil
}

void JugadorIaDificil::EvaluarMovimiento() {
    // Implementar lógica para evaluar el movimiento de la IA difícil
}
