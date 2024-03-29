
#define CATCH_CONFIG_MAIN

#include "catch.h"
#include "newthon-raphson.cpp"
#include "Dados.cpp"
#include <cmath>

SCENARIO("NewthonRaphson") {
  NewthonRaphson newton = NewthonRaphson(2, 4, 1);
  double erro = 0.0001;

  GIVEN("calcularNRO") {
    double resultado = newton.calcularNRO(0.5, erro, erro);
    REQUIRE(std::abs(resultado - 0.3376068) < erro);
  }

  GIVEN("calcularNRFL") {
    double resultado = newton.calcularNRFL(0.5, erro, erro, 0.1);
    REQUIRE(std::abs(resultado - 0.0833655208) < erro);
  }

  GIVEN("calcularDevidada") {
    double resultado = newton.calcularDerivada(2);
    REQUIRE(std::abs(resultado - 30) < erro);
  }

  GIVEN("calibrarSistema") {
    REQUIRE(newton.calibrarSistema() == 0.0);
  }
}
