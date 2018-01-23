#include <iostream>
#include <cmath>

using namespace std;

// Euler Simples

double f(double t)
{
	return -0.25*(t - 65);
}


int main()
{
	double T = 8;
	double t = 3;
	double step = 0.5;

	cout << "0 Iteration: " << endl << "t: " << t << endl<< "T: " << T << endl << endl;

	for (unsigned int i = 0; i < 2; i++)
	{
		T += step * f(T);
		t += step;

		cout << i + 1 << " Iteration: " << endl << "t: " << t << endl << "T: " << T << endl << endl;
	}
	system("pause");
	return 0;
}