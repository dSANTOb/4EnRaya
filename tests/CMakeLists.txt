enable_testing()

find_package(GTest REQUIRED)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(unit_tests
# TODO: Añadan acá todos los archivos de pruebas
    test_tablero.cpp
    test_jugadorDificil.cpp
    test_jugadorFacil.cpp
    test_aaa.cpp
# TODO: Añadan acá el código fuente de su proyecto. Por ejemplo:
    ../src/Tablero.cpp
    ../src/JugadorFacil.cpp
    ../src/JugadorDificil.cpp
    ../src/aaa.cpp
)

target_link_libraries(unit_tests
    GTest::gtest
    GTest::gtest_main)

target_include_directories(unit_tests PUBLIC ${INCLUDE_DIR})

add_test(AllTests unit_tests)