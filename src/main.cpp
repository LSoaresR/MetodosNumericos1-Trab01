
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include "Dados.h"

using namespace std;

double F(double x) {
  return x*x*x - 9*x + 3;
}

template <class F>
double calcularDerivada(F f, double x) {
  double dfx, h;

  h = pow(10, -5);

  dfx = (f(x + h) - f(x))/h;

  return dfx;
}

template <class F>
Dados NewtonRaphson(F f, double x0, double err1, double err2, int miter) {
  double h;
  double x1;
  double root;
  int iter = 1;
  Dados dados;

  while(iter < miter) {
    h = f(x0)/calcularDerivada(f, x0);
    x1 = x0 - h;
    dados.setX(x0); //insere o x0 no vetor de x's
    dados.setPhi(h); //insere o valor de Phi no vetor de Phi's
    dados.setFx(f(x0)); //insere o valor de Fx no vetor de Fx's
    dados.setFx_der(calcularDerivada(f, x0)); //insere o valor de F'x no vetor de F'x

    //printf("The approximation's value after %d iteration is %.12lf\n",iter,x1);
    if(abs(h)<err1 || abs(x1 - x0) < err2) {
      root=x1;
      break;
    }
    else
      x0=x1;
    iter++;
  }
  /*if(root==x1) {
    printf("The root is: %.12lf\n",root);
    double fncvalue = f(root);
    printf("Value of F(root) is: %.12lf",fncvalue);
  }
  else
    printf("The unsufficent number of iteration");*/
  return dados;
}

template <class F>
Dados NewtonRaphson(F f, double x0, double err, int miter) {
  return NewtonRaphson(f, x0, err, err, miter);
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

template <class F>
Dados NewtonRaphsonFL(F f, double xinicial, double erro1, double erro2, double lambda) {
  double xk = xinicial;
  double xw = xk;
  double xk_p;
  bool verif = true;
  Dados dados;

  if(abs(f(xk)) < erro1){
    dados.setX(xk);
    return dados;
  }
  while(verif) {
    double h = (f(xk)/FL(f, xk, xw, lambda));
    xk_p = xk - (f(xk)/FL(f, xk, xw, lambda));

    dados.setX(xk); //insere o xk no vetor de x's
    dados.setPhi(h); //insere o valor de Phi no vetor de Phi's
    dados.setFx(f(xk)); //insere o valor de Fx no vetor de Fx's
    dados.setFx_der(FL(f, xk, xw, lambda)); //insere o valor de F'x no vetor de F'x

    if(std::abs(f(xk_p) < erro1) || abs(xk_p - xk) < erro2) {
      verif = false;
    }

    if(std::abs(calcularDerivada(f, xk_p)) >= lambda) {
      xw = xk_p;
    }

    xk = xk_p;
  }	
  return dados;
}

template <class F>
Dados NewtonRaphsonFL(F f, double xinicial, double erro, double lambda) {
  return NewtonRaphsonFL(f, xinicial, erro, erro, lambda);
}

int main() {
  double err = 0.0001;

  cout << "NewtonRaphson:\n";
  Dados dados = NewtonRaphson(F, 0.5, err, 100);
  for (int i = 0; i < dados.getX().size(); ++i){
    cout << "X na iteracao " << i << " eh " << dados.getX()[i] << "\n";
  }
  cout << "\n";
  Dados dados2 = NewtonRaphson(F, 1, err, 100);
    for (int i = 0; i < dados2.getX().size(); ++i){
    cout << "X na iteracao " << i << " eh " << dados2.getX()[i] << "\n";
  }
  cout << "\nNewtonRaphsonFL:\n";
  Dados dados3 = NewtonRaphsonFL(F, 0.5, err, 0.05);
  for (int i = 0; i < dados3.getX().size(); ++i){
    cout << "X na iteracao " << i << " eh " << dados3.getX()[i] << "\n";
  }
  cout << "\n";
  Dados dados4 = NewtonRaphsonFL(F, 1, err, 0.05);
    for (int i = 0; i < dados4.getX().size(); ++i){
    cout << "X na iteracao " << i << " eh " << dados4.getX()[i] << "\n";
  }

  return 0;
}
