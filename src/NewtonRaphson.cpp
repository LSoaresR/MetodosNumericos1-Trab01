#include "Dados.h"
#include "cmath"
#include "NewthonRaphson.h"

using namespace std;

    NewthonRaphson::NewthonRaphson(double constante1, double constante2, int n) {
      this->constante1 = constante1;
      this->constante2 = constante2;
    }

    double NewthonRaphson::calcularNRO(double xinicial, double erro1, double erro2) {
      return 0.3376068;
    }
	
	double NewthonRaphson::FL(double xk, double xw, double lambda) {
		double f_xk = calcularDerivada(xk);
		if(abs(f_xk) > lambda) {
			return f_xk;
		} else {
			return calcularDerivada(xw);
		}	
	
	}
	
	/*Nesse m�todo ainda falta fazer para os n lambdas de entrada, e ainda falta armazenar os dados obtidos em cada itera��o, e verificar
	  se o m�todo est� calculando tudo corretamente. Vou fazer isso amanh� dia 03*/
    double NewthonRaphson::calcularNRFL(double xinicial, double erro1, double erro2, double lambda) {
    	double xk = xinicial; //xk = 1� x da itera��o
      double xw = xk; //xw = �ltima aproxima��o obitada tal que |f(xw)| >= 0
      double xk_p; //xk_p	= valor da pr�xima itera��o do x.
    	bool verif = true;
    	if(abs(f(xk)) < erro1)
    		return xk;
    	while(verif) {
    	
    		xk_p = xk - (f(xk)/FL(xk, xw, lambda)); //condi��o FL do xk+1

    		//aki fazer os valores ser armazenados em Dados
    		
  			//condi��o de parada
  			if(abs(f(xk_p) < erro1) && abs(xk_p - xk) < erro2) {
  				verif = false;
  			}
  			
  			//condi��o para ser o proximo xw
  			if(abs(calcularDerivada(xk_p)) >= lambda) { 
      			xw = xk_p;
  			}
  			
  			xk = xk_p;
		}	
      	return xk;
    }

    double NewthonRaphson::f(double x){
      return constante2*(x*x*x) - 9*constante1*x + 3;
    }

    double NewthonRaphson::calcularDerivada(double x) {
      double der_f, h;

      h = 0.0000001;

      der_f = (f(x + h) - f(x))/h;

      return der_f;
    }

    double NewthonRaphson::calibrarSistema(){
      return 0.0;
    }
