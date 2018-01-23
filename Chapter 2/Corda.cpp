#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Corda Method

double f(double x)
{
	return pow(x, 3) - 10 * sin(x) + 4.4;
}

int main()
{
	double a = 1.5;
	double b = 7;
	double w = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));

	for (unsigned int i = 0; i < 2; i++)
	{
		if (f(a)*f(w) < 0)
			b = w;
		else
			a = w;
		w = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));
	}

	cout << "A: " << a << endl << "B: " << b << endl;

	system("pause");
	return 0;
}