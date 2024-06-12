#ifndef JUGADORHUMANO_HH
#define JUGADORHUMANO_HH

#include <IJugador.hh>
#include <Tablero.hh>

class JugadorHumano : public IJugador {
public:
    JugadorHumano(const std::string &nombre);
    int realizarMovimiento(Tablero& tableroActual) override;
};

#endif
