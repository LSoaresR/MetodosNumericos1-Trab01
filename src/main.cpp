#include "NewtonRaphson.cpp"
#include "Dados.h"
#include <iostream>


using namespace std;


int main() {
	int n = 1;
	NewtonRaphson r;
  //	r.calibrarSistema(1, 1, 0.05, 1000, 0.05);
	
  ///	r.quadroRespostaNRO(3, 2, -2.5, 0.001, 0.001, 1000);
	cout << "Entre com  a quantidade de lambdas" << endl;
	cin >> n;
	r.quadroRespostaNRFLN(3, 2, 2.5, 0.001, 0.001, 1000, n);
//	r.quadroRespostaNRFL(1, 1, 2.5, 0.05, 0.05, 1000, 0.05);
  //	r.quadroRespostaNRFL(1, 1, 5, 0.0001, 0.0001, 1000, 0.0001);

  //	r.quadroComparativo(1, 1, 2.5, 0.05, 0.05, 1000, 0.05);
  	
  return 0;
}
