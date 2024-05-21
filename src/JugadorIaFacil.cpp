#include "JugadorIaFacil.hh"

JugadorIaFacil::JugadorIaFacil(const std::string& nombre) : IJugador(nombre) {}

int JugadorIaFacil::GetPuntaje() const {
    return Puntaje;
}

std::string JugadorIaFacil::GetNombre() const {
    return Nombre;
}

void JugadorIaFacil::CrearFicha() {
    // Implementar lógica para crear una ficha para la IA fácil
}

void JugadorIaFacil::EvaluarMovimiento() {
    // Implementar lógica para evaluar el movimiento de la IA fácil
}
