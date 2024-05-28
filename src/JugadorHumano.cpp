#include <JugadorHumano.hh>

#include <iostream>

JugadorHumano::JugadorHumano(const std::string &nombre) : IJugador(nombre) {}

int JugadorHumano::realizarMovimiento() {
  int columna;
  std::cout << "Ingrese la columna donde desea colocar su ficha: ";
  std::cin >> columna;
  return columna;
}
