#include "newthon-raphson.cpp"
#include "Dados.h"

using namespace std;

int main() {
	NewthonRaphson r;
  	r.calibrarSistema(1, 1, 0.05, 1000, 0.05);

  	r.quadroRespostaNRO(1, 1, 5, 0.0001, 0.0001, 1000);

  	r.quadroRespostaNRFL(1, 1, 5, 0.0001, 0.0001, 1000, 0.0001);

  	r.quadroComparativo(1, 1, 5, 0.0001, 0.0001, 1000, 0.0001);

  return 0;
}
