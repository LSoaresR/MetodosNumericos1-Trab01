#ifndef NEWTON
#define NEWTON

#include "Dados.h"

using namespace std;

class NewthonRaphson {
  public:
    double constante1;
    double constante2;
    Dados iteracoesNRO;
    vector<Dados> iteracoesNRFL;
    vector<Dados> iteracoesCalibrado;

    NewthonRaphson(double constante1, double constante2, int n);

    double calcularNRO(double xinicial, double erro1, double erro2);
	
	double FL(double xk, double xw, double lambda);

    double calcularNRFL(double xinicial, double erro1, double erro2, double lambda);


    double f(double x);


    double calcularDerivada(double x);

    double calibrarSistema();
};


#endif //NEWTON	
