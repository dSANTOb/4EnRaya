#ifndef JUGADORHUMANO_HH
#define JUGADORHUMANO_HH

#include "IJugador.hh"

class JugadorHumano : public IJugador {
public:
    JugadorHumano(const std::string &nombre);
    int realizarMovimiento() override; 
};

#endif // JUGADORHUMANO_HH
