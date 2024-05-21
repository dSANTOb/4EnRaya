#ifndef JUGADORHUMANO_HH
#define JUGADORHUMANO_HH

#include "IJugador.hh"

class JugadorHumano : public IJugador {
public:
    void Puntaje() override;
    void Nombre() override;
    void CrearFicha() override;
};

#endif // JUGADORHUMANO_HH
