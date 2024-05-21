#ifndef IJUGADOR_HH
#define IJUGADOR_HH

#include <string>

class IJugador {
protected:
    std::string nombre;
    int puntaje;

public:
    IJugador(const std::string &nombre); //Constructor
    virtual ~IJugador(); //DEstructor
    virtual int realizarMovimiento() = 0;
    std::string getNombre() const;
    int getPuntaje() const;
    void incrementarPuntaje();
};

#endif // IJUGADOR_HH

