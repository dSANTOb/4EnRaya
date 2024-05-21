#ifndef JUGADORIAFACIL_HH
#define JUGADORIAFACIL_HH

#include "IJugador.hh"

class JugadorIaFacil : public IJugador {
public:
    void Puntaje() override;
    void Nombre() override;
    void EvaluarMovimiento();
    void CrearFicha() override;
};

#endif // JUGADORIAFACIL_HH
