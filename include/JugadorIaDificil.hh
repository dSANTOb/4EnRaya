#ifndef JUGADORIADEFICIL_HH
#define JUGADORIADEFICIL_HH

#include "IJugador.hh"

class JugadorIaDificil : public IJugador {
public:
    JugadorIaDificil(const std::string& nombre);

    int GetPuntaje() const override;
    std::string GetNombre() const override;
    void CrearFicha() override;
    void EvaluarMovimiento();
};

#endif // JUGADORIADEFICIL_HH
