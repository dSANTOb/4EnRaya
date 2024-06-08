#ifndef JUGADORIADIFICIL_HH
#define JUGADORIADIFICIL_HH

#include "IJugador.hh"
#include "Tablero.hh"

class JugadorIaDificil : public IJugador {
public:
    JugadorIaDificil(const std::string &nombre);
    int realizarMovimiento() override;

private:
  int minimax(Tablero &tablero, int profundidad, bool esMaximizador);
    int evaluarTablero(const Tablero &tablero) const;
    std::vector<int> obtenerMovimientosValidos(const Tablero &tablero) const;
    bool estaLleno(const Tablero &tablero) const;
};

#endif // JUGADORIADIFICIL_HH
