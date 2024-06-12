#ifndef JUGADOR_IADIFICIL_HH
#define JUGADOR_IADIFICIL_HH

#include <IJugador.hh>
#include <Tablero.hh>
#include <vector>

class JugadorIaDificil : public IJugador {
public:
    JugadorIaDificil(const std::string& nombre);
    int realizarMovimiento(Tablero& tableroActual) override;

private:
    int minimax(Tablero& tablero, int profundidad, bool esMaximizador);
    int evaluarTablero(const Tablero& tablero) const;
    std::vector<int> obtenerMovimientos(const Tablero& tablero) const;
    bool estaLleno(const Tablero& tablero) const;
};

#endif
