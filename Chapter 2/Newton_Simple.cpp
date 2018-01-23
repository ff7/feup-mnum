#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Newton's Method

double f(double x) {
	return (pow(x, 4) + 2 * (pow(x, 3)) - x - 1); //funcao especifica
}

double df(double x) {
	return (4 * (pow(x, 3)) + 6 * (pow(x, 2)) - 1); //derivada da funcao especifica
}

int main()
{
	double x = 1.7;

	cout << "Iteracao 0:" << endl << "X: " << x << endl << "G(x): " << f(x) << endl << endl;

	for (unsigned int i = 0; i < 2; i++)
	{
		x = x - ((f(x)) / (df(x)));
		cout << "Iteracao "<< i+1<<":" << endl << "X: " << x << endl << "G(x): " << f(x) << endl << endl;
	}

	system("pause");
	return 0;
}