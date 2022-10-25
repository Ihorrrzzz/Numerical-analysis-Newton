#include <iostream>
#include <cmath>

using namespace std;

double Fx(double x) { 
	return x*x-9*x+14;
}

double dFx(double x) {
	return 2*x;
}

typedef double(*function)(double x);

double NewtonFun(function Fx, function dFx, double x0, double e) {
    double xi = x0; 
    while (fabs(Fx(xi)) >= e) {
  	  xi = xi - Fx(xi) / dFx(xi);
    }
  return xi;
}


int main() {
	double x, e;
	cout << "enter eps (accuracy) - ";
	cin >> e;
	cout << "enter x - ";
	cin >> x;
	
	cout << "Newton Function - " << NewtonFun(Fx, dFx, x, e) << endl;
	
    return 0;
}
