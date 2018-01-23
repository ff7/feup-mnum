#include <iostream>
#include <cmath>

using namespace std;

// Gradient Method

double f(double x, double y)
{
	return (6 * pow(x, 2) - x * y + 12 * y + pow(y, 2) - 8 * x);
}

double dx(double x, double y)
{
	return 12 * x - y - 8;
}

double dy(double x, double y)
{
	return -x + 12 + 2 * y;
}

int main()
{
	double x = 0;
	double y = 0;
	double h = 0.25;

	double xc;
	double yc;

	cout << "Iteracao: 0" << endl << "X: " << x << endl << "Y: " << y << endl << endl;

	for (unsigned int i = 0; i < 1; i++)
	{
		xc = x - h * dx(x, y);
		yc = x - h * dy(x, y);

		if (f(xc, yc)<f(x, y))

			h = 2 * h;
		else
			h = h / 2;

		cout << "Iteracao: " << i + 1 << endl << "X: " << xc << endl << "Y: " << yc << endl << endl;
	}

	system("pause");
	return 0;
}