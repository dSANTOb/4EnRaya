#include <Tablero.hh>
#include <gtest/gtest.h>

TEST(TableroTest, InicializacionTablero) {
    Tablero tablero;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            EXPECT_EQ(tablero.getGrid()[i][j], 0);
        }
    }
}

TEST(TableroTest, ColocarFichaValida) {
    Tablero tablero;
    EXPECT_TRUE(tablero.colocarFicha(0, 1));
    EXPECT_EQ(tablero.getGrid()[5][0], 1);
}

TEST(TableroTest, ColocarFichaInvalida) {
    Tablero tablero;
    EXPECT_FALSE(tablero.colocarFicha(7, 1)); // Columna fuera de rango
}

TEST(TableroTest, ColocarFichaEnColumnaLlena) {
    Tablero tablero;
    for (int i = 0; i < 6; ++i) {
        EXPECT_TRUE(tablero.colocarFicha(0, 1));
    }
    EXPECT_FALSE(tablero.colocarFicha(0, 1)); // Columna ya llena
}
