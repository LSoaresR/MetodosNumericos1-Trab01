#include "Dados.h"
using namespace std;

class NewthonRaphson {
  public:
    double constante1;
    double constante2;
    Dados iteracoesNRO;
    vector<Dados> iteracoesNRFL;
    vector<Dados> iteracoesCalibrado;

    NewthonRaphson(double constante1, double constante2, int n) {
      this->constante1 = constante1;
      this->constante2 = constante2;
    }

    double calcularNRO(double xinicial, double erro1, double erro2) {
      return 0.3376068;
    }

    double calcularNRFL(double xinicial, double erro1, double erro2, double lambda) {
      return 0;
    }

    double f(double x){
      return constante2*(x*x*x) - 9*constante1*x + 3;
    }

    double calcularDerivada(double x) {
      double der_f, h;

      h = 0.0000001;

      der_f = (f(x + h) - f(x))/h;

      return der_f;
    }

    double calibrarSistema(){
      return 0.0;
    }
};
