#include "Dados.h"
#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

class NewthonRaphson {
 
public:
	
double F(double x) {
  return a3*x*x*x - 9*a2*x + 3;
}


double calcularDerivada( double x) {
  double dfx, h;

  h = pow(10, -5);

  dfx = (F(x + h) - F(x))/h;

  return dfx;
}

NewthonRaphson() {
	
}


Dados NewtonRaphson(double x0, double err1, double err2, int miter) {
  double h;
  double x1;
  double root;
  int iter = 1;
  Dados dados;

  while(iter < miter) {
    h = F(x0)/calcularDerivada(x0);
    x1 = x0 - h;
    dados.setX(x0); //insere o x0 no vetor de x's
    dados.setPhi(h); //insere o valor de Phi no vetor de Phi's
    dados.setFx(F(x0)); //insere o valor de Fx no vetor de Fx's
    dados.setFx_der(calcularDerivada(x0)); //insere o valor de F'x no vetor de F'x

    //printf("The approximation's value after %d iteration is %.12lf\n",iter,x1);
    if(abs(F(x1))<err1 || abs(x1 - x0) < err2) { //Alterei h para f(x1) - Marcos
      root=x1;
      dados.setRaiz(x1);
      break;
    }
    else
      x0=x1;
    iter++;
  }
  return dados;
}

Dados NewtonRaphson(double x0, double err, int miter) {
  return NewtonRaphson(x0, err, err, miter);
}

template <class F>
double FL(F f, double xk, double xw, double lambda) {
  double dfxk = calcularDerivada(f, xk);

  if(abs(dfxk) > lambda) {
    return dfxk;
  } else {
    return calcularDerivada(f, xw);
  }
}


Dados NewtonRaphsonFL(double xinicial, double erro1, double erro2, double miter, double lambda){
  double x0 = xinicial;
  double e1 = erro1;
  double e2 = erro2;
  double x1 = 0.0;
  double ant = 0.0;
  int k = 0;
  Dados dados;
  
  if(abs(F(x0)) < e1){
    dados.setX(x0);
    return dados;
  }

  ant = x0;
  while(true){
    dados.setX(x0);

    double h = 0;
    if(abs(calcularDerivada(x0)) > lambda){
      h = F(x0)/calcularDerivada(x0);
      dados.setFx_der(calcularDerivada(x0));
      ant = x0;
    }
    else{
      h = F(x0)/calcularDerivada(ant);
      dados.setFx_der(calcularDerivada(ant));
    }

    x1 = x0 - h;

    dados.setPhi(h);
    dados.setFx(F(x0));
    
    if(abs(F(x1)) < e1 || abs(x1-x0) < e2 || k > miter){
      dados.setRaiz(x1);
      return dados;
    }
    x0 = x1;
    k++;
  }
}

Dados NewtonRaphsonFL( double xinicial, double erro, double miter, double lambda) {
  return NewtonRaphsonFL( xinicial, erro, erro, miter, lambda);
}

void calibrarSistema(double x, double y, double erro, double miter, double lambda){
  a3 = x;
  a2 = y;

  cout << endl << endl;
  cout << "------------------------------------------------------------------------" << endl;
  cout << "Calibragem do Sistema com a3 = 1 | a2 = 1 | lambda = 0.05 | erro = 0.05" << endl;
  cout << "------------------------------------------------------------------------" << endl << endl;

  Dados dados = NewtonRaphsonFL( 1, erro, erro, miter, lambda);
  for(int i = 0; i < dados.getX().size(); i++){
    cout << "     k     | " << i << endl;
    cout << "    Xk     | " << dados.getX()[i] << endl;
    cout << "  f(Xk)    | " << dados.getFx()[i] << endl;
    cout << "  f\'(Xk)   | "<< dados.getFx_der()[i] << endl;
    if(i == 0)
      cout << " Intervalo |    ---   "<< endl;
    else
      cout << " Intervalo | "<< abs(dados.getX()[i]-dados.getX()[i-1]) << endl;
    cout << "_______________________________________" << endl << endl;
  }
  cout << "    Raiz   | " << dados.getRaiz() << endl;
  cout << "_______________________________________" << endl << endl;
}

void quadroRespostaNRO(double x, double y, double xinicial, double erro1, double erro2, double miter){
  a3 = x;
  a2 = y;
  Dados dados = NewtonRaphson(xinicial, erro1, erro2, miter);

  cout << endl << endl;
  cout << "-----------------------------------------" << endl;
  cout << "Quadro para o NewtonRaphson Original" << endl;
  cout << "-----------------------------------------" << endl << endl;

  for(int i = 0; i < dados.getX().size(); i++){
    cout << "     k     | " << i << endl;
    cout << "    Xk     | " << dados.getX()[i] << endl;
    cout << "  f(Xk)    | " << dados.getFx()[i] << endl;
    cout << "  f\'(Xk)   | "<< dados.getFx_der()[i] << endl;
    if(i == 0)
      cout << " Intervalo |    ---   "<< endl;
    else
      cout << " Intervalo | "<< abs(dados.getX()[i]-dados.getX()[i-1]) << endl;
    cout << "_______________________________________" << endl << endl;
  }
  cout << "    Raiz   | " << dados.getRaiz() << endl;
  cout << "_______________________________________" << endl << endl;
}

void quadroRespostaNRFL(double x, double y, double xinicial, double erro1, double erro2, double miter, double lambda){
  a3 = x;
  a2 = y;
  Dados dados = NewtonRaphsonFL(xinicial, erro1, erro2, miter, lambda);

  cout << endl << endl;
  cout << "-----------------------------------------" << endl;
  cout << "Quadro para o NewtonRaphson FL" << endl;
  cout << "-----------------------------------------" << endl << endl;

  for(int i = 0; i < dados.getX().size(); i++){
    cout << "     k     | " << i << endl;
    cout << "    Xk     | " << dados.getX()[i] << endl;
    cout << "  f(Xk)    | " << dados.getFx()[i] << endl;
    cout << "  f\'(Xk)   | "<< dados.getFx_der()[i] << endl;
    if(i == 0)
      cout << " Intervalo |    ---   "<< endl;
    else
      cout << " Intervalo | "<< abs(dados.getX()[i]-dados.getX()[i-1]) << endl;
    cout << "_______________________________________" << endl << endl;
  }
  cout << "    Raiz   | " << dados.getRaiz() << endl;
  cout << "_______________________________________" << endl << endl;
}

void quadroComparativo(double x, double y, double xinicial, double erro1, double erro2, double miter, double lambda){
  a3 = x;
  a2 = y;
  int i = 0, j = 0;
  bool imax = false, jmax = false;
  Dados dnro = NewtonRaphson(xinicial, erro1, erro2, miter);
  Dados dnrfl = NewtonRaphsonFL(xinicial, erro1, erro2, miter, lambda);

  cout << endl << endl;
  cout << "---------------------------------" << endl;
  cout << "Quadro Comparativo" << endl;
  cout << "---------------------------------" << endl << endl;

  while(!imax && !jmax){
    cout << "        k      | " << i << endl;
    cout << "_______________________________________" << endl;
    if(!imax)
      cout << "NRO     Xk     | " << dnro.getX()[i] << endl;
    else
      cout << "NRO     Xk     |  -----   " << endl;
    if(!jmax)
      cout << "NRFL    Xk     | " << dnrfl.getX()[j] << endl;
    else
      cout << "NRFL    Xk     |  -----   " << endl;

    cout << "_______________________________________" << endl;
    if(!imax)
      cout << "NRO    f(Xk)   | " << dnro.getFx()[i] << endl;
    else
      cout << "NRO    f(Xk)   |  -----   "  << endl;
    if(!jmax)
      cout << "NRFL   f(Xk)   | " << dnrfl.getFx()[j] << endl;
    else
      cout << "NRFL   f(Xk)   |  -----   " << endl;

    cout << "_______________________________________" << endl;
    if(!imax)
      cout << "NRO    f(Xk)   | " << dnro.getFx_der()[i] << endl;
    else
      cout << "NRO    f(Xk)   |  -----   " << endl;
    if(!jmax)
      cout << "NRO    f\'(Xk)  | " << dnrfl.getFx_der()[j] << endl;
    else
      cout << "NRFL   f\'(Xk)  |  -----   " << endl;
    
    cout << "_______________________________________" << endl;
    if(i == 0 || imax)
      cout << "NRO  Intervalo |    ---   "<< endl;
    else
      cout << "NRO  Intervalo | "<< abs(dnro.getX()[i]-dnro.getX()[i-1]) << endl;
    if(j == 0 || jmax)
      cout << "NRFL Intervalo |    ---   "<< endl;
    else
      cout << "NRFL Intervalo | "<< abs(dnrfl.getX()[j]-dnro.getX()[j-1]) << endl;
    
    cout << "_______________________________________" << endl << endl;
    i++;
    j++;
    imax = i >= dnro.getX().size();
    jmax = j >= dnrfl.getX().size();
  }
  cout << "NRO    Raiz   | " << dnro.getRaiz() << endl;
  cout << "NRFL   Raiz   | " << dnrfl.getRaiz() << endl;
  cout << "_______________________________________" << endl << endl;
}

 private:
    double a3 ;
	double a2 ;

};
