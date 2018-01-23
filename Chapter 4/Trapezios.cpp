#include <iostream>
#include <cmath>

using namespace std;

// Thrapezoidal Method

double f(double x)
{
	return exp(1.5 * x);
}

int main()
{
	double a = 1;
	double b = 1.5;
	double h = 0.125;
	double n = (b - a) / h;

	double st = 0;

	for (unsigned int i = 1; i < n; i++)
		st += f(a + i * h)*2;

	st += f(a) + f(b);
	st = st * (h / 2);

	cout << "The value of L is: " << st << endl;
	
	system("pause");
	return 0;
}