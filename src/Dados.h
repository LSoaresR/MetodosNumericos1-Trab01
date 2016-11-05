#ifndef DADOS
#define DADOS

#include <vector> 

using namespace std;
class Dados {
	public:
		//construtor
		Dados();
		Dados(vector<double> x, vector<double> phi, vector<double> fx, vector<double> fx_der, double lambda, double raiz);
	
		//sets
		void setX(double x);
		void setPhi(double phi);
		void setFx(double fx);
		void setFx_der(double fx_der);
		void setLambda(double lambda);
		void setRaiz(double raiz);
		//gets
		vector<double> getX();
		vector<double> getPhi();
		vector<double> getFx();
		vector<double> getFx_der();
		double getLambda();
		double getRaiz();
		
	private:
		
		vector<double> x;
		vector<double> phi;
		vector<double> fx;
		vector<double> fx_der;
		double lambda;
		double raiz;
	
	
	
};






#endif //DADOS
