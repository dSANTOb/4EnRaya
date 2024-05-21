#ifndef JUGADORHUMANO_HH
#define JUGADORHUMANO_HH

#include "IJugador.hh"

class JugadorHumano : public IJugador {
public:
    JugadorHumano(const std::string& nombre);
    
    int GetPuntaje() const override;
    std::string GetNombre() const override;
    void CrearFicha() override;
};

#endif // JUGADORHUMANO_HH
