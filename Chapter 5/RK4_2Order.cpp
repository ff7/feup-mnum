#include <iostream>
#include <cmath>

using namespace std;

// RK4 2 Order

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
		double dy1 = step * fy(t, z);
		double dz1 = step * fz(t, z);

		double dy2 = step * fy(t + step/2, z + dz1/2);
		double dz2 = step * fz(t + step / 2, z + dz1 / 2);

		double dy3 = step * fy(t + step / 2, z + dz2 / 2);
		double dz3 = step * fz(t + step / 2, z + dz2 / 2);

		double dy4 = step * fy(t + step, z + dz3);
		double dz4 = step * fz(t + step, z + dz3);

		cout << i + 1 << " Iteration:" << endl;
		
		y = y + dy1/6 + dy2/3 + dy3/3 + dy4/6;
		z = z + dz1 / 6 + dz2 / 3 + dz3 / 3 + dz4 / 6;
		t = t + step;

		cout << "Y: " << y << endl << "Z: " << z << endl << endl;
	}


	system("pause");
	return 0;
}