#include <iostream>
#include <cmath>

using namespace std;

// Euler 2 Order

double fy(double t, double z)
{
	return z;
}

double fz(double t, double z)
{
	return (1 + pow(t, 2) + t * z);
}

int main()
{
	double t0 = 0;
	double y0 = 1;
	double z0 = 2;

	double t = t0;
	double y = y0;
	double z = z0;

	double step = 0.5;

	cout << "0 Iteration: " << endl << "Y: " << y << endl << "Z: " << z << endl << endl;

	for (unsigned int i = 0; i < 2; i++)
	{
		cout << i << " Iteration:" << endl;
		y = y + step * fy(t, z);
		z = z + step * fz(t, z);

		cout << "Y: " << y << endl << "Z: " << z << endl << endl;
	}


	system("pause");
	return 0;
}