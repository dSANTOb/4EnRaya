#ifndef JUGADOR_IAFACIL_HH
#define JUGADOR_IAFACIL_HH

#include <IJugador.hh>
#include <Tablero.hh>
#include <vector>

class JugadorIaFacil : public IJugador {
public:
    JugadorIaFacil(const std::string& nombre);
    int realizarMovimiento(Tablero& tableroActual) override;

private:
    std::vector<int> obtenerMovimientos(const Tablero& tablero) const;
};

#endif // JUGADOR_IAFACIL_HH


