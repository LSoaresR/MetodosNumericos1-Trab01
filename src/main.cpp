
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include "Dados.h"

using namespace std;

double a3 = 1;
double a2 = 1;

double F(double x) {
  return a3*x*x*x - 9*a2*x + 3;
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
    if(abs(f(x1))<err1 || abs(x1 - x0) < err2) { //Alterei h para f(x1) - Marcos
      root=x1;
      dados.setRaiz(x1);
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
Dados NewtonRaphsonFL(F f, double xinicial, double erro1, double erro2, double lambda){
  double x0 = xinicial;
  double e1 = erro1;
  double e2 = erro2;
  double x1 = 0.0;
  double ant = 0.0;
  Dados dados;
  
  if(abs(f(x0)) < e1){
    dados.setX(x0);
    return dados;
  }

  ant = x0;
  while(true){
    dados.setX(x0);

    double h = 0;
    if(abs(f(x0)) > lambda){
      h = f(x0)/calcularDerivada(f, x0);
      dados.setFx_der(calcularDerivada(f, x0));
    }
    else{
      h = f(x0)/calcularDerivada(f, ant);
      dados.setFx_der(calcularDerivada(f, ant));
    }

    x1 = x0 - h;

    dados.setPhi(h);
    dados.setFx(f(x0));
    
    if(abs(f(x1)) < e1 || abs(x1-x0) < e2){
      dados.setRaiz(x1);
      return dados;
    }
    ant = x0;
    x0 = x1;
  }
}

// template <class F>
// Dados NewtonRaphsonFL(F f, double xinicial, double erro1, double erro2, double lambda) {
//   double xk = xinicial;
//   double xw = xk;
//   double xk_p;
//   bool verif = true;
//   Dados dados;

//   if(abs(f(xk)) < erro1){
//     dados.setX(xk);
//     return dados;
//   }
//   while(verif) {
//     double h = (f(xk)/FL(f, xk, xw, lambda));
//     xk_p = xk - h; //Alterei (f(xk)/FL(f, xk, xw, lambda)) por h - Marcos

//     dados.setX(xk); //insere o xk no vetor de x's
//     dados.setPhi(h); //insere o valor de Phi no vetor de Phi's
//     dados.setFx(f(xk)); //insere o valor de Fx no vetor de Fx's
//     dados.setFx_der(FL(f, xk, xw, lambda)); //insere o valor de F'x no vetor de F'x

//     if(std::abs(f(xk_p) < erro1) || abs(xk_p - xk) < erro2) {
//       verif = false;
//     }

//     if(std::abs(calcularDerivada(f, xk_p)) >= lambda) {
//       xw = xk_p;
//     }

//     xk = xk_p;
//   }	
//   return dados;
// }

template <class F>
Dados NewtonRaphsonFL(F f, double xinicial, double erro, double lambda) {
  return NewtonRaphsonFL(f, xinicial, erro, erro, lambda);
}

void calibrarSistema(double x, double y, double erro, double lambda){
  a3 = x;
  a2 = y;

  cout << endl << endl;
  cout << "------------------------------------------------------------------------" << endl;
  cout << "Calibragem do Sistema com a3 = 1 | a2 = 1 | lambda = 0.05 | erro = 0.05" << endl;
  cout << "------------------------------------------------------------------------" << endl << endl;

  Dados dados = NewtonRaphsonFL(F, 1, erro, erro, lambda);
  for(int i = 0; i < dados.getX().size(); i++){
    cout << "     k     | " << i << endl;
    cout << "    Xk     | " << dados.getX()[i] << endl;
    cout << "  f(Xk)    | " << dados.getFx()[i] << endl;
    cout << "  f\'(Xk)   | "<< dados.getFx_der()[i] << endl;
    cout << " Intervalo | "<< abs(dados.getX()[i+1]-dados.getX()[i]) << endl;
    cout << "_______________________________________" << endl << endl;
  }
  cout << "    Raiz   | " << dados.getRaiz() << endl;
  cout << "_______________________________________" << endl << endl;
}

void quadroRespostaNRO(double x, double y, double xinicial, double erro1, double erro2, double miter){
  a3 = x;
  a2 = y;
  Dados dados = NewtonRaphson(F, xinicial, erro1, erro2, miter);

  cout << endl << endl;
  cout << "-----------------------------------------" << endl;
  cout << "Quadro para o NewtonRaphson Original" << endl;
  cout << "-----------------------------------------" << endl << endl;

  for(int i = 0; i < dados.getX().size(); i++){
    cout << "     k     | " << i << endl;
    cout << "    Xk     | " << dados.getX()[i] << endl;
    cout << "  f(Xk)    | " << dados.getFx()[i] << endl;
    cout << "  f\'(Xk)   | "<< dados.getFx_der()[i] << endl;
    cout << " Intervalo | "<< abs(dados.getX()[i+1]-dados.getX()[i]) << endl;
    cout << "_______________________________________" << endl << endl;
  }
  cout << "    Raiz   | " << dados.getRaiz() << endl;
  cout << "_______________________________________" << endl << endl;
}

int main() {

  calibrarSistema(1, 1, 0.05, 0.05);

  quadroRespostaNRO(2, 2, 2, 0.0001, 0.0001, 1000);

  // double err = 0.05;

  // cout << "NewtonRaphson:\n";
  // Dados dados = NewtonRaphson(F, 0.5, err, 100);
  // for (int i = 0; i < dados.getX().size(); ++i){
  //   cout << "X na iteracao " << i << " eh " << dados.getX()[i] << "\n";
  // }
  // cout << "Raiz: " << dados.getRaiz() << endl;

  // cout << "\n";
  // Dados dados2 = NewtonRaphson(F, 1, err, 100);
  //   for (int i = 0; i < dados2.getX().size(); ++i){
  //   cout << "X na iteracao " << i << " eh " << dados2.getX()[i] << "\n";
  // }
  // cout << "Raiz: " << dados2.getRaiz() << endl;

  // cout << "\nNewtonRaphsonFL:\n";
  // Dados dados3 = NewtonRaphsonFL(F, 0.5, err, 0.05);
  // for (int i = 0; i < dados3.getX().size(); ++i){
  //   cout << "X na iteracao " << i << " eh " << dados3.getX()[i] << "\n";
  // }
  // cout << "Raiz: " << dados3.getRaiz() << endl;
  // cout << "Last: " << dados3.getX()[dados3.getX().size()-1] << endl;

  // cout << "\n";
  // Dados dados4 = NewtonRaphsonFL(F, 1, err, 0.05);
  //   for (int i = 0; i < dados4.getX().size(); ++i){
  //   cout << "X na iteracao " << i << " eh " << dados4.getX()[i] << "\n";
  // }
  // cout << "Raiz: " << dados4.getRaiz() << endl;

  return 0;
}
