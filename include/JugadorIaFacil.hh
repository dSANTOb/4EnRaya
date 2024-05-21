#ifndef JUGADORIAFACIL_HH
#define JUGADORIAFACIL_HH

#include "IJugador.hh"

class JugadorIaFacil : public IJugador {
public:
    JugadorIaFacil(const std::string &nombre);
    int realizarMovimiento() override;
};

#endif // JUGADORIAFACIL_HH

