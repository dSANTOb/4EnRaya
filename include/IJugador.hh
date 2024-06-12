#ifndef IJUGADOR_HH
#define IJUGADOR_HH

#include <string>
#include <Tablero.hh>

class IJugador {
protected:
    std::string nombre;
    int puntaje;

public:
    IJugador(const std::string &nombre); //Constructor
    virtual ~IJugador(); //Destructor
    virtual int realizarMovimiento(Tablero& tablero) = 0;
    std::string getNombre() const;
    int getPuntaje() const;
    void incrementarPuntaje();
};

#endif // IJUGADOR_HH

