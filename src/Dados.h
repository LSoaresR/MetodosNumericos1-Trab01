#ifndef DADOS
#define DADOS

#include <vector> 

using namespace std;
class Dados {
	public:
		//construtor
		Dados();
		Dados(vector<double> x, vector<double> phi, vector<double> fx, vector<double> fx_der);
	
		//sets
		void setX(double x);
		void setPhi(double phi);
		void setFx(double fx);
		void setFx_der(double fx_der);	
		//gets
		vector<double> getX();
		vector<double> getPhi();
		vector<double> getFx();
		vector<double> getFx_der();
		
	private:
		
		vector<double> x;
		vector<double> phi;
		vector<double> fx;
		vector<double> fx_der;
	
	
	
};






#endif //DADOS
