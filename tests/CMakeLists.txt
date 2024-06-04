enable_testing()
find_package(GTest REQUIRED)

set(HEADER_LIST
"${4EnRaya_SOURCE_DIR}/include/*.hh"
)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(unit_tests
# TODO: Añadan acá todos los archivos de pruebas
    test_aaa.cpp
    test_tablero.cpp
    test_jugadores.cpp
# TODO: Añadan acá el código fuente de su proyecto. Por ejemplo:
    ../src/IJugador.cpp
    ../src/JugadorHumano.cpp
    ../src/JugadorIaDificil.cpp
    ../src/JugadorIaFacil.cpp
    ../src/Tablero.cpp
)

target_include_directories(unit_tests
PUBLIC
"${4EnRaya_SOURCE_DIR}/include"
)

target_link_libraries(unit_tests
    GTest::gtest
    GTest::gtest_main)

add_test(AllTests unit_tests)
