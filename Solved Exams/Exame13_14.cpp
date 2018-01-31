#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Exame 2013/2014 - Epoca Normal

// Pergunta 2

double f(double x)
{
	return -x + 40*cos(sqrt(x)) + 3;
}

double dx(double x)
{
	return -1 - (20 * sin(sqrt(x))) / sqrt(x);
}

void newton()
{
	double x = 1.7;

	for (unsigned int i = 0; i < 2; i++)
	{
		x = x - (f(x) / dx(x));
		cout << x << '\t' << f(x) << endl;
	}
}

// Pergunta 5

double f5(double x)
{
	return 5 * cos(x) - sin(x);
}

void aurea()
{
	double b = (sqrt(5) - 1) / 2;
	double a = b * b;

	double x1 = 2;
	double x2 = 4;
	double x3 = x1 + a * (x2 - x1);
	double x4 = x1 + b * (x2 - x1);

	for (unsigned int i = 0; i < 1; i++)
	{
		if (f5(x3) < f5(x4))
			x2 = x4;
		else
			x1 = x3;
		x3 = x1 + a * (x2 - x1);
		x4 = x1 + b * (x2 - x1);

		cout << "Iteracao " << i + 1 << ":" << endl << "X1: " << x1 << endl << "X2: " << x2 << endl << "X3: " << x3 << endl << "X4: " << x4 << endl << endl;
	}
}

// Pergunta 7

double f7(double x)
{
	return sqrt(sqrt(4 * x*x*x - x + 3));
}

void pp()
{
	double x = 3.5;

	for (unsigned int i = 0; i < 2; i++)
	{
		x = f7(x);
		cout << x << endl;
	}
}

int main()
{
	cout.precision(7);
	//newton();
	//aurea();
	pp();
	system("pause");
	return 0;
}
