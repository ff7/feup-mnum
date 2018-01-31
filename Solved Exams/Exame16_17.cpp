#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Exame 2016/2017 - Epoca Normal

// Pergunta 2

double f1(double x, double y)
{
	return x * x - y - 1.2;
}

double f2(double x, double y)
{
	return (-x + y * y - 1);
}

double df1x(double x, double y)
{
	return 2*x;
}

double df1y(double x, double y)
{
	return -1;
}

double df2x(double x, double y)
{
	return -1;
}

double df2y(double x, double y)
{
	return 2 * y;
}

void newton()
{
	double x = 1;
	double y = 1;

	double xn, yn;

	for (unsigned int i = 0; i < 2; i++)
	{
		double denom = df1x(x, y)*df2y(x, y) - df2x(x, y)*df1y(x, y);
		xn = x - (f1(x, y)*df2y(x, y) - f2(x, y)*df1y(x, y)) / denom;
		yn = y - (f2(x, y)*df1x(x, y) - f1(x, y)*df2x(x, y)) / denom;

		x = xn;
		y = yn;

		cout << "Iteracao " << i + 1 << ": " << endl << "X: " << x << endl << "Y: " << y << endl;
	}
}

// Pergunta 4

double f4(double x)
{
	return pow(x, 7) + 0.5*x - 0.5;
}

void corda()
{
	double a = 0;
	double b = 0.8;
	double w = (a*f4(b) - b * f4(a)) / (f4(b) - f4(a));

	cout << f4(a) << endl << f4(b) << endl << f4(w) << endl << endl;

	for (unsigned int i = 0; i < 3; i++)
	{
		if (f4(a)*f4(w) < 0)
			b = w;
		else
			a = w;
		w = (a*f4(b) - b * f4(a)) / (f4(b) - f4(a));

		cout << "A: " << a << endl << "B: " << b << endl << "W: " << w << endl << endl;
	}
}

// Pergunta 5

double fz(double t, double z)
{
	return 0.5 + t * t + t * z;
}

double fy(double t, double z)
{
	return z;
}

void euler()
{
	double h = 0.25;
	double t = 0;
	double y = 0;
	double z = 1;

	for (unsigned int i = 0; i < 2; i++)
	{
		y += h * fy(t, z);
		z += h * fz(t, z);
		t += h;

		cout << t << endl << y << endl << endl;
	}
}

void rk4()
{
	double h = 0.25;
	double t = 0;
	double y = 0;
	double z = 1;

	double dy1, dy2, dy3, dy4, dz1, dz2, dz3, dz4;

	for (unsigned int i = 0; i < 2; i++)
	{
		dy1 = h * fy(t, z);
		dz1 = h * fz(t, z);

		dy2 = h * fy(t + h/2, z + dz1 / 2);
		dz2 = h * fz(t + h / 2, z + dz1 / 2);

		dy3 = h * fy(t + h / 2, z + dz2 / 2);
		dz3 = h * fz(t + h / 2, z + dz2 / 2);

		dy4 = h * fy(t + h , z + dz3);
		dz4 = h * fz(t + h , z + dz3);

		y += dy1 / 6 + dy2 / 3 + dy3 / 3 + dy4 / 6;
		z += dz1 / 6 + dz2 / 3 + dz3 / 3 + dz4 / 6;
		t += h;

		cout << t << endl << y << endl << endl;
	}
}

// Pergunta 6

double f6(double x)
{
	return sqrt(1 + pow(1.5*exp(1.5*x), 2));
}

double trap(double h)
{
	double a = 0;
	double b = 2;
	double n = (b - a) / h;
	double st = 0;

	for (unsigned int i = 1; i < n; i++)
	{
		st += f6(a + h * i) * 2;
	}
	st += f6(a) + f6(b);
	st = st * (h / 2);
	return st;
}

double simpson(double h)
{
	double a = 0;
	double b = 2;
	double n = (b - a) / h;
	double ss = 0;

	for (unsigned int i = 1; i < n; i++)
	{
		if (i%2 == 0)
			ss += f6(a + h * i) * 2;
		else
			ss += f6(a + h * i) * 4;
	}
	ss += f6(a) + f6(b);
	ss = ss * (h / 3);
	return ss;
}

void tabela()
{
	double h = 0.5;
	cout << trap(h) << '\t' << simpson(h) << endl;
	cout << trap(h/2) << '\t' << simpson(h/2) << endl;
	cout << trap(h/4) << '\t' << simpson(h/4) << endl << endl;
	cout << (trap(h / 2) - trap(h)) / (trap(h / 4) - trap(h / 2)) << '\t' << (simpson(h / 2) - simpson(h)) / (simpson(h / 4) - simpson(h / 2)) << endl;
	cout << (trap(h / 4) - trap(h / 2)) / 3 << '\t' << (simpson(h / 4) - simpson(h / 2)) / 15;
}

int main()
{
	cout.precision(7);
	//newton();
	//corda();
	//euler();
	//rk4();
	tabela();
	system("pause");
	return 0;
}