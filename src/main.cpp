
#include <iostream>
#include <iostream>
#include <math.h>

double F(double x) {
  return pow(0.9, x);
}

template <class F>
double calcularDerivada(F f, double x) {
  double dfx, h;

  h = pow(10, -5);

  dfx = (f(x + h) - f(x))/h;

  return dfx;
}

void NewtonRaphson(double x0, double err1, double err2, int miter) {
  double h;
  double x1;
  double root;
  int iter = 1;

  while(iter < miter) {
    h = F(x0)/calcularDerivada(F, x0);
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
    double fncvalue = F(root);
    printf("Value of F(root) is: %.12lf",fncvalue);
  }
  else
    printf("The unsufficent number of iteration");
}

double FL(double xk, double xw, double lambda) {
  double dfxk = calcularDerivada(F, xk);

  if(abs(dfxk) > lambda) {
    return dfxk;
  } else {
    return calcularDerivada(F, xw);
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
    xk_p = xk - (f(xk)/FL(xk, xw, lambda));

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

int main() {
  double err = 0.05;

  NewtonRaphsonFL(F, 10, err, err, 0.05);

  return 0;
}
