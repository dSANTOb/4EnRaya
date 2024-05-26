#include <JugadorIaFacil.hh>
#include <cstdlib>

JugadorIaFacil::JugadorIaFacil(const std::string &nombre) : IJugador(nombre) {}

int JugadorIaFacil::realizarMovimiento() {
    return rand() % 7; //Movimiento random entre las 7 columnas
}

