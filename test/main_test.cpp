
#define CATCH_CONFIG_MAIN

#include "catch.h"
#include "newthon-raphson.cpp"

SCENARIO("NewthonRaphson") {
  NewthonRaphson newton = NewthonRaphson(2, 4, 1);

  GIVEN("calcularNRO") {
    REQUIRE(newton.calcularNRO(0.5, 0.0001, 0.0001) == 0.3376068);
  }

  GIVEN("calcularNRFL") {
    REQUIRE(newton.calcularNRFL(0, 0, 0, 0) == 0);
  }

  GIVEN("calcularDevidada") {
    double resultado = newton.calcularDerivada(2);
    REQUIRE(resultado > 30.000002);
    REQUIRE(resultado < 30.000003);
  }
}
