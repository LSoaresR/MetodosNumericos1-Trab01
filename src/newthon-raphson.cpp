#include "Dados.h"
#include <cmath>
#include <stdio.h>
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

    double calcularNRO(double x0, double erro1, double erro2, int miter) {
      double h;
      double x1;
      double raiz;
      int iter = 1;

      while(iter < miter) {
        h = f(x0)/calcularDerivada(x0);
        x1 = x0 - h;

        printf("A aproximação depois da %d iteracao eh %.12lf\n",iter,x1);
        if(abs(h)<err1 || abs(x1 - x0) < err2) {
          root=x1;
          break;
        }
        else
          x0=x1;
        iter++;
      }
      if(root==x1) {
        printf("The root is: %.12lf\n",root);
        double fncvalue = F(root);
        printf("Value of F(root) is: %.12lf",fncvalue);
      }
      else
        printf("The unsufficent number of iteration");
    }

    double FL(double xk, double xw, double lambda) {
      double f_xk = calcularDerivada(xk);
      if(abs(f_xk) > lambda) {
        return f_xk;
      } else {
        return calcularDerivada(xw);
      } 
    }

    double calcularNRFL(double xinicial, double erro1, double erro2, double lambda) {
      double xk = xinicial; //xk = 1º x da iteração
      double xw = xk; //xw = última aproximação obitada tal que |f(xw)| >= 0
      double xk_p; //xk_p = valor da próxima iteração do x.
      bool verif = true;
      if(abs(f(xk)) < erro1)
        return xk;
      while(verif) {
        xk_p = xk - (f(xk)/FL(xk, xw, lambda)); //condição FL do xk+1

        //aki fazer os valores ser armazenados em Dados
        
        //condição de parada
        if(abs(f(xk_p) < erro1) && abs(xk_p - xk) < erro2) {
          verif = false;
        }
        
        //condição para ser o proximo xw
        if(abs(calcularDerivada(xk_p)) >= lambda) { 
            xw = xk_p;
        }
        
        xk = xk_p;
      } 
      return xk;
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
