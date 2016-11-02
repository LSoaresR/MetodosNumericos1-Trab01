
#define CATCH_CONFIG_MAIN

#include "catch.h"
#include "newthon-raphson.cpp"

SCENARIO("NewthonRaphson") {
  NewthonRaphson newton = NewthonRaphson(0, 0);

  GIVEN("calcularNRO") {
    REQUIRE(newton.calcularNRO(0.5, 0.0001, 0.0001) == 0.3376068);
  }

  GIVEN("calcularNRFL") {
    REQUIRE(newton.calcularNRFL(0, 0, 0, 0) == 0);
  }

  GIVEN("calcularDevidada") {
    REQUIRE(newton.calcularDerivada() == 30.0);
  }
}
