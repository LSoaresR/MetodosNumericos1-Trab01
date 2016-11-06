#include "Dados.h"
#include <vector>

using namespace std;

Dados::Dados(){	
}

Dados::Dados(vector<double> x, vector<double> phi, vector<double> fx, vector<double> fx_der, double lambda, double raiz) {
	this->x.swap(x);
	this->phi.swap(phi);
	this->fx.swap(fx);
	this->fx_der.swap(fx_der);
	this->lambda;
	this->raiz;
}

//SETS
void Dados::setX(double x) {
	this->x.push_back(x);
}

void Dados::setPhi(double phi) {
	this->phi.push_back(phi);
}

void Dados::setFx(double fx) {
	this->fx.push_back(fx);
}

void Dados::setFx_der(double fx_der) {
	this->fx_der.push_back(fx_der);
}

void Dados::setLambda(double lambda){
	this->lambda = lambda;
}

void Dados::setRaiz(double raiz){
	this->raiz = raiz;
}

//GETS 
vector<double> Dados::getX() {
	return x;
}

vector<double> Dados::getPhi() {
	return phi;
}

vector<double> Dados::getFx() {
	return fx;
}

vector<double> Dados::getFx_der() {
	return fx_der;
}

double Dados::getLambda(){
	return lambda;
}

double Dados::getRaiz(){
	return raiz;
}
