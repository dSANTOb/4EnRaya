#include "JugadorIaDificil.hh>
#include <Tablero.hh>
#include <gtest/gtest.h>

TEST(JugadorIaDificilTest, RealizarMovimiento) {

    Tablero tablero;

   
    tablero.redimensionar(6, 7); 
    tablero.colocarFicha(0, 1 ); 

   
    JugadorIaDificil jugador("IA Difícil");

    
    int movimiento = jugador.realizarMovimiento(tablero);

    EXPECT_GE(movimiento, 0);
    EXPECT_LT(movimiento, 7);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
