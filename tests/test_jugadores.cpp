#include <JugadorHumano.hh>
#include <JugadorIaFacil.hh>
#include <JugadorIaDificil.hh>
#include <Tablero.hh>
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

TEST(JugadorHumanoTest, RealizarMovimiento) {
    std::istringstream input("3\n");
    std::cin.rdbuf(input.rdbuf()); // Redirigir std::cin para testear entrada
    JugadorHumano jugador("Humano");
    EXPECT_EQ(jugador.realizarMovimiento(), 3);
}

TEST(JugadorIaFacilTest, RealizarMovimiento) {
    JugadorIaFacil jugador("IA Fácil");
    int movimiento = jugador.realizarMovimiento();
    EXPECT_GE(movimiento, 0);
    EXPECT_LT(movimiento, 7);
}

TEST(JugadorIaDificilTest, RealizarMovimiento) {
    JugadorIaDificil jugador("IA Difícil");
    int movimiento = jugador.realizarMovimiento();
    EXPECT_GE(movimiento, 0);
    EXPECT_LT(movimiento, 7);
}
