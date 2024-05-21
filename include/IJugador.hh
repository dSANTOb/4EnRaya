#ifndef IJUGADOR_HH
#define IJUGADOR_HH

class IJugador {
public:
    virtual void Puntaje() = 0;
    virtual void Nombre() = 0;
    virtual void CrearFicha() = 0;
    virtual ~IJugador() {}
};

#endif // IJUGADOR_HH
