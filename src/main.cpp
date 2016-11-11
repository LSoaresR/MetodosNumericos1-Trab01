#include "NewtonRaphson.cpp"
#include "Dados.h"
#include <iostream>
#include <stdlib.h>


using namespace std;


int main() {
	NewtonRaphson r;
	int n, op;
	bool ativo = true;
	double c1, c2;
	double x0 = 0.5;
	double err1, err2;
	int miter;
	double lambda;
  //	r.calibrarSistema(1, 1, 0.05, 1000, 0.05);
	
  ///	r.quadroRespostaNRO(3, 2, -2.5, 0.001, 0.001, 1000);
	///cout << "Entre com  a quantidade de lambdas" << endl;
	///cin >> n;
	///r.quadroRespostaNRFLN(3, 2, 2.5, 0.001, 0.001, 1000, n);
//	r.quadroRespostaNRFL(1, 1, 2.5, 0.05, 0.05, 1000, 0.05);
  //	r.quadroRespostaNRFL(1, 1, 5, 0.0001, 0.0001, 1000, 0.0001);

  //	r.quadroComparativo(1, 1, 2.5, 0.05, 0.05, 1000, 0.05);
	while(ativo){
		system("clear");
		cout << "----------------------- MÉTODO DE NEWTON RAPHSON -----------------------" << endl;
		cout << "---------------------- f(x) = c1*d^3 - 9*c2*d + 3 ----------------------" << endl;
		cout << endl;
		cout << "Digite ação desejada:" << endl;
		cout << "1. Calcular e Visualizar Newton Raphson Original;" << endl;
		cout << "2. Calcular e Visualizar Newton Raphson FL com um Lambda;" << endl;
		cout << "3. Calcular e Visualizar Newton Raphson FL com n Lambdas;" << endl;
		cout << "4. Calcular e Visualizar Newton Raphson com Sistema Calibrado" << endl;
		cout << "5. Comparar Newton Raphson Original, Newton Raphson FL com um Lambda e Newton Raphson com Sistema Calibrado;" << endl;
		cout << "6. Sair;\n" << endl;
		cout << "Opção Desejada: ";
		cin >> op;

		switch(op){
			case 1:
				cout << "Digite c1: ";
				cin >> c1;
				cout << "\nDigite c2: ";
				cin >> c2;
				cout << "\nDigite erro 1: ";
				cin >> err1;
				cout << "\nDigite erro 2: ";
				cin >> err2;
				cout << "\nDigite número máximo de iterações: ";
				cin >> miter;
				r.quadroRespostaNRO(c1, c2, x0, err1, err2, miter);
				cout << "\nDeseja voltar ao menu? (1. Sim 	2.Não) ";
				cin >> op;
				if(op == 1){
					continue;
				}
				if(op == 2){
					//Destruir objeto r
					system("clear");
					return 0;
				}
				break;
			case 2:
				cout << "Digite c1: ";
				cin >> c1;
				cout << "\nDigite c2: ";
				cin >> c2;
				cout << "\nDigite erro 1: ";
				cin >> err1;
				cout << "\nDigite erro 2: ";
				cin >> err2;
				cout << "\nDigite o Lambda: ";
				cin >> lambda;
				cout << "\nDigite número máximo de iterações: ";
				cin >> miter;
				r.quadroRespostaNRFL(c1, c2, x0, err1, err2, miter, lambda);
				cout << "\nDeseja voltar ao menu? (1. Sim 	2.Não) ";
				cin >> op;
				if(op == 1){
					continue;
				}
				if(op == 2){
					//Destruir objeto r
					system("clear");
					return 0;
				}
				break;
			case 3: 
				cout << "\nDigite erro 1: ";
				cin >> err1;
				cout << "\nDigite erro 2: ";
				cin >> err2;
				cout << "\nDigite o Número de Lambdas desejados: ";
				cin >> n;
				cout << "\nDigite número máximo de iterações: ";
				cin >> miter;
				r.quadroRespostaNRFLN(c1, c2, x0, err1, err2, miter, n);
				cout << "\nDeseja voltar ao menu? (1. Sim 	2.Não) ";
				cin >> op;
				if(op == 1){
					continue;
				}
				if(op == 2){
					//Destruir objeto r
					system("clear");
					return 0;
				}
				break;
			case 4:
				r.quadroRespostaCalibragem();
				cout << "\nDeseja voltar ao menu? (1. Sim 	2.Não) ";
				cin >> op;
				if(op == 1){
					continue;
				}
				if(op == 2){
					//Destruir objeto r
					system("clear");
					return 0;
				}
				break;
			case 5:
				cout << "Digite c1: ";
				cin >> c1;
				cout << "\nDigite c2: ";
				cin >> c2;
				cout << "\nDigite erro 1: ";
				cin >> err1;
				cout << "\nDigite erro 2: ";
				cin >> err2;
				cout << "\nDigite o Lambda: ";
				cin >> lambda;
				cout << "\nDigite número máximo de iterações: ";
				cin >> miter;
				r.quadroComparativo(c1, c2, x0, err1, err2, miter, lambda);
				cout << "\nDeseja voltar ao menu? (1. Sim 	2.Não) ";
				cin >> op;
				if(op == 1){
					continue;
				}
				if(op == 2){
					//Destruir objeto r
					system("clear");
					return 0;
				}
				break;
			case 6:
				ativo = false;
				system("clear");
				break;
			default:
				continue;
		}
	}
  	
  return 0;
}
