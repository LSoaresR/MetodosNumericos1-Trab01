
#include <iostream>
#include <iostream>
#include <math.h>

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
void NewtonRaphson(F f, double x0, double err1, double err2, int miter) {
  double h;
  double x1;
  double root;
  int iter = 1;

  while(iter < miter) {
    h = f(x0)/calcularDerivada(f, x0);
    x1 = x0 - h;

    printf("The approximation's value after %d iteration is %.12lf\n",iter,x1);
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
    double fncvalue = f(root);
    printf("Value of F(root) is: %.12lf",fncvalue);
  }
  else
    printf("The unsufficent number of iteration");
}

template <class F>
void NewtonRaphson(F f, double x0, double err, int miter) {
  NewtonRaphson(f, x0, err, err, miter);
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
double NewtonRaphsonFL(F f, double xinicial, double erro1, double erro2, double lambda) {
  double xk = xinicial;
  double xw = xk;
  double xk_p;
  bool verif = true;

  if(abs(f(xk)) < erro1)
    return xk;
  while(verif) {
    xk_p = xk - (f(xk)/FL(f, xk, xw, lambda));

    if(abs(f(xk_p) < erro1) || abs(xk_p - xk) < erro2) {
      verif = false;
    }

    if(abs(calcularDerivada(f, xk_p)) >= lambda) {
      xw = xk_p;
    }

    xk = xk_p;
  }	
  return xk;
}

template <class F>
double NewtonRaphsonFL(F f, double xinicial, double erro, double lambda) {
  return NewtonRaphsonFL(f, xinicial, erro, erro, lambda);
}

int main() {
  double err = 0.05;

  NewtonRaphson(F, 1, err, 100);

  return 0;
}
