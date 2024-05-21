#include "IJugador.hh"

IJugador::IJugador(const std::string &nombre) : nombre(nombre), puntaje(0) {}

IJugador::~IJugador() {}

std::string IJugador::getNombre() const {
    return nombre;
}

int IJugador::getPuntaje() const {
    return puntaje;
}

void IJugador::incrementarPuntaje() {
    puntaje++;
}
