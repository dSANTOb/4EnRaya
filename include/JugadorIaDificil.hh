#ifndef JUGADORIADIFICIL_HH
#define JUGADORIADIFICIL_HH

#include "IJugador.hh"

class JugadorIaDificil : public IJugador {
public:
    void Puntaje() override;
    void Nombre() override;
    void EvaluarMovimiento();
    void CrearFicha() override;
};

#endif // JUGADORIADIFICIL_HH
