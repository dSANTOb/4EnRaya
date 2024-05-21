#include "Tablero.hh"

Tablero::Tablero(int tamaño) : TamañoTablero(tamaño) {}

int Tablero::GetTamañoTablero() const {
    return TamañoTablero;
}

void Tablero::PosicionesOcupadas() {
    // Implementar lógica para verificar las posiciones ocupadas en el tablero
}

void Tablero::AgregarFicha() {
    // Implementar lógica para agregar una ficha al tablero
}

bool Tablero::Victoria() const {
    // Implementar lógica para verificar si hay una condición de victoria
    return false;
}
