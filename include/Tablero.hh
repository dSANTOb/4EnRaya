#ifndef TABLERO_HH
#define TABLERO_HH

class Tablero {
private:
    int TamañoTablero;

public:
    Tablero(int tamaño);
    
    int GetTamañoTablero() const;
    void PosicionesOcupadas();
    void AgregarFicha();
    bool Victoria() const;
};

#endif // TABLERO_HH
