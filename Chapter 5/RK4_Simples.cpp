#include <iostream>
#include <cmath>

using namespace std;

// RK4 Simples

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
		double dt1 = step * f(T);
		double dt2 = step * f(dt1/2);
		double dt3 = step * f(dt2/2);
		double dt4 = step * f(dt3);

		T += dt1/6 + dt2/3 + dt3/3 + dt4/6;
		t += step;

		cout << i + 1 << " Iteration: " << endl << "t: " << t << endl << "T: " << T << endl << endl;
	}
	system("pause");
	return 0;
}