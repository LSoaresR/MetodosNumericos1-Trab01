#ifndef DADOS
#define DADOS

#include <vector> 

using namespace std;
class Dados {
	public:
		//construtor
		Dados();
		Dados(vector<double> x, vector<double> phi, vector<double> fx, vector<double> fx_der, double lambda);
	
		//sets
		void setX(double x);
		void setPhi(double phi);
		void setFx(double fx);
		void setFx_der(double fx_der);
		void setLambda(double lambda);
		//gets
		vector<double> getX();
		vector<double> getPhi();
		vector<double> getFx();
		vector<double> getFx_der();
		double getLambda();
		
	private:
		
		vector<double> x;
		vector<double> phi;
		vector<double> fx;
		vector<double> fx_der;
		double lambda;
	
	
	
};






#endif //DADOS
