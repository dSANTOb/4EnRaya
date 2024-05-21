#ifndef JUGADORIADIFICIL_HH
#define JUGADORIADIFICIL_HH

#include "IJugador.hh"
#include "Tablero.hh"

class JugadorIaDificil : public IJugador {
public:
    JugadorIaDificil(const std::string &nombre);
    int realizarMovimiento() override;

private:
    //Sin implementar
    int minimax(Tablero &tablero, int profundidad, bool esMaximizador);
};

#endif // JUGADORIADIFICIL_HH
